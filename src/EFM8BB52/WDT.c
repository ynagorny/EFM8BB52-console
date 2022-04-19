#include <SI_EFM8BB52_Register_Enums.h>

#include <EFM8BB52/WDT.h>

void WDT_disable(void) {
  SFRPAGE = 0x00;
  WDTCN = 0xDE;
  WDTCN = 0xAD;
}
