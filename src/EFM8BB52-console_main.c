#include <stdio.h>

#include <settings.h>
#include <EFM8BB52/EFM8BB52.h>

void SiLabs_Startup(void) {
  WDT_disable();
}

void configure(void) {
  SYSCLK_configure();
  UART0_configure();
}

int main(void) {
  configure();

  printf("BB52 Explorer Kit Console\n");

  // echo input to output
  while (1) {
      char ch = _getkey(); // unlike getchar, _getkey does not auto-echo
      if (ch == '\r') {
          putchar('\n'); // line feed on character return
      }
      putchar(ch);
  }
}
