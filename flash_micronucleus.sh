#!/bin/bash

while getopts ":P:" option; do
  case $option in
    P)
      avrdude -c arduino -P ${OPTARG} -b 19200 -p attiny85  -U lfuse:w:0xe1:m -U hfuse:w:0xdd:m -U efuse:w:0xfe:m -B 20
      avrdude -c arduino -P ${OPTARG} -b 19200 -p attiny85  -U flash:w:main.hex:i -B 20
      exit;;
    \?)
      echo "Usage: $0 [-P <Port of arduino>]"
      exit;;
  esac
done

avrdude -c arduino -P /dev/ttyACM0 -b 19200 -p attiny85  -U lfuse:w:0xe1:m -U hfuse:w:0xdd:m -U efuse:w:0xfe:m -B 20
avrdude -c arduino -P /dev/ttyACM0 -b 19200 -p attiny85  -U flash:w:bootloader/micronucleus_attiny85-default.hex:i -B 20


