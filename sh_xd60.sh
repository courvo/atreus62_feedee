# a mettre dans le dossier qmk_firmware
make xd60:feedee
dfu-programmer atmega32u4 erase
dfu-programmer atmega32u4 flash xd60_feedee.hex
dfu-programmer atmega32u4 reset
