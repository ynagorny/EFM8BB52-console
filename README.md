# EFM8BB52 Console
An example of how to setup a console for BB52 Explorer Kit (BB52-EK2701A) based on EFM8BB52 MCU from Silicon Labs. It allows both for transmitting and receving data via a terminal application. Use Simplicity Studio to compile and run.

## Background
The BB52 Explorer Kit provides a virtual COM port that is connected to UART0 of the MCU on pins P0.4 (TX) and P0.5 (RX). This code has all the necessary configuration steps for the MCU to start communicating on the port.
 
## UART0 configuration
UART0 will be configured with the serial format of 115200 bps, 8 bits, no parity, and 1 stop bit. The key configuration steps are done in **src/EFM8BB52/UART0.c**

## Run Console
Open and run this project in Simplicity Studio with the explorer kit board connected. Connect your favorite terminal (e.g. PuTTY) to the corresponding COM port (see all COM ports in Device Manager on Windows). Once device starts, you should see **BB52 Explorer Kit Console** and then every character you type should be echoed back.
