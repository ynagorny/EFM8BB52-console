#ifndef __SETTINGS_H__
#define __SETTINGS_H__

// Choose one of clock sources:
// CLKSEL_CLKSL__HFOSC0_clk24p5         24.5 MHz  - Internal High Frequency Oscillator - default
// CLKSEL_CLKSL__EXTOSC                 unknown   - External Oscillator circuit
// CLKSEL_CLKSL__LFOSC                  80 kHz    - Internal Low-Frequency Oscillator
// CLKSEL_CLKSL__HFOSC0_clk49           49 MHz    - Internal High Frequency Oscillator
// CLKSEL_CLKSL__HFOSC0_clk24p5_div_1p5 16.33 MHz - Internal High Frequency Oscillator 24.5 MHz, pre-scaled by 1.5
// CLKSEL_CLKSL__FSRCO_clk10            10 MHz    - Internal Fast Start Up Oscillator
// CLKSEL_CLKSL__FSRCO_clk2p5           2.5 MHz   - Internal Fast Start Up Oscillator with 4x prescale (2.5 MHz)
// CLKSEL_CLKSL__HFOSC0_clk49_div_1p5   33.67 MHz - Internal High Frequency Oscillator 49 MHz, pre-scaled by 1.5.
#define SYSCLK_CLOCK  CLKSEL_CLKSL__HFOSC0_clk24p5


// Choose one of clock source dividers:
// CLKSEL_CLKDIV__SYSCLK_DIV_1          divide by 1
// CLKSEL_CLKDIV__SYSCLK_DIV_2          divide by 2
// CLKSEL_CLKDIV__SYSCLK_DIV_4          divide by 4
// CLKSEL_CLKDIV__SYSCLK_DIV_8          divide by 8 - default
// CLKSEL_CLKDIV__SYSCLK_DIV_16         divide by 16
// CLKSEL_CLKDIV__SYSCLK_DIV_32         divide by 32
// CLKSEL_CLKDIV__SYSCLK_DIV_64         divide by 64
// CLKSEL_CLKDIV__SYSCLK_DIV_128        divide by 128
#define SYSCLK_DIV    CLKSEL_CLKDIV__SYSCLK_DIV_8

// UART0 baud rate
#define UART0_BAUD 115200

#endif
