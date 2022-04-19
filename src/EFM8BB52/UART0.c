#include <SI_EFM8BB52_Register_Enums.h>

#include <EFM8BB52/SYSCLK.h>
#include <EFM8BB52/UART0.h>

void UART0_configure(void) {
  SFRPAGE = 0x00;

  // enable crossbar
  XBR2 |= XBR2_XBARE__ENABLED;

  // route UART0 pins via crossbar
  XBR0 |= XBR0_URT0E__ENABLED;

  // UART0 pins (P0.4 and P0.5) are digital
  P0MDIN |= P0MDIN_B4__DIGITAL | P0MDIN_B5__DIGITAL;

  // UART0 TX pin is output
  P0MDOUT |= P0MDOUT_B4__PUSH_PULL;

  // disable UART0 RX pin output component by making it open drain and latch it high
  P0MDOUT &= ~(P0MDIN_B5__BMASK);
  P0 |= P0_B5__HIGH;

  // UART0 uses Timer 1 for timing - configure Timer 1
  TMOD = (TMOD & ~(TMOD_GATE1__BMASK | TMOD_CT1__BMASK | TMOD_T1M__FMASK))
      | TMOD_GATE1__DISABLED // ignore INT1
      | TMOD_CT1__TIMER // setup as timer
      | TMOD_T1M__MODE2; // mode 2 (8 bit with auto reload)

  // Timer 1 clock source is SYSCLK
  CKCON0 |= CKCON0_T1M__SYSCLK;

  // Calculate overflow rate so that Timer 1 overflows at double the baud rate
#define TIMER_TICKS (SYSCLK_FREQUENCY / UART0_BAUD / 2)
#if TIMER_TICKS >= 255
#error "Clock is too fast"
#elif TIMER_TICKS <= 8
#error "Clock is too slow"
#endif
  // deducting 1 reduces frequency slightly
  // which makes transmission more stable at lower SYSCLK
  TH1 = 0x100 - TIMER_TICKS - 1;

  TCON_TR1 = 1; // start Timer 1

  SCON0_REN = 1; // allow UART0 receiving

  SCON0_TI = 1; // kick off send
}
