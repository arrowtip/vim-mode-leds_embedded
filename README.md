# Vim Mode Leds - Embedded Code
## Install directly
To compile and flash the code 


## Install using Micronucleus
### Install Micronucleus
- Flash the ArduinoISP program to an arduino board of your choice and
connect the ATtiny85 to it
- Download the Micronucleus code from its github
- To compile the bootloader, switch into the firmware folder and run
```shell
make CONFIG=t85_default
```
- Burn the fuses on the ATtiny85:
```shell
make CONFIG=t85_default PROGRAMMER="-c arduino -P <Port> -b 19200" fuse
```
- Flash the Micronucleus bootloader to the ATtiny85:
```shell
make CONFIG=t85_default PROGRAMMER="-c arduino -P <Port> -b 19200" flash
```
- Insert the ATtiny85 into its socket on the PCB

### Install Led Code
- Switch to the vim-mode-led_embedded folder and run
```shell
pio run -t upload -e attiny85
```
- Plug the USB-PCB in when prompted by PlatformIO

