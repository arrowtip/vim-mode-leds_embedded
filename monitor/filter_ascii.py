from platformio.public import DeviceMonitorFilterBase
import serial


class Demo(DeviceMonitorFilterBase):
    NAME = "ascii"

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        print("ascii filter is loaded")

    def rx(self, text):
        result = ""
        for b in serial.iterbytes(text):
            ascii_code = ord(b)
            if ascii_code <= 255:
                result += "{:02X} ".format(ascii_code)
            else:
                result += f"{ascii_code} "
        return result

    def tx(self, text):
        print(f"Sent: {text}\n")
        return text
