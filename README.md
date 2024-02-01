# Vim Mode Leds - Embedded Code
Everything you need to turn your next neovim coding session into a strobo party.
## Install directly (without Micronucleus)
1. Set up programmer, like an 
[Arduino configured as ISP programmer](https://www.arduino.cc/en/Tutorial/BuiltInExamples/ArduinoISP)
2. Flash software with:
    ```bash
    pio run -e attiny85_bare-metal -t upload --upload-port <Port of programmer>
    ```

## Install using Micronucleus
### Option 1: Install with precompiled hex-file
1. Flash the [ArduinoISP program](https://www.arduino.cc/en/Tutorial/BuiltInExamples/ArduinoISP) 
to an Arduino board of your choice and
connect the ATtiny85 to it
2. Run the provided shell script `/flash_micronucleus.sh` (might require root privileges)

### Option 2: Install Micronucleus from Repo
1. Flash the [ArduinoISP program](https://www.arduino.cc/en/Tutorial/BuiltInExamples/ArduinoISP) 
to an Arduino board of your choice and
connect the ATtiny85 to it
2. Download the [Micronucleus](https://github.com/micronucleus/micronucleus) code from its github
and go to the `/firmware` folder
3. Burn the fuses on the ATtiny85:
    ```bash
    make CONFIG=t85_default PROGRAMMER="-c arduino -P <Port> -b 19200" fuse
    ```
4. Flash the Micronucleus bootloader to the ATtiny85:
    ```bash
    make CONFIG=t85_default PROGRAMMER="-c arduino -P <Port> -b 19200" flash
    ```
5. Insert the ATtiny85 into its socket on the PCB



### Install Led Code
1. Go to project root folder and run:
    ```shell
    pio run -t upload -e attiny85
    ```
2. Plug the USB-PCB in when prompted by PlatformIO

