
#MCU
MCU = atmega32u4
F_CPU = 16000000

#BOOTLOADER
BOOTLOADER = amtel-dfu

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp

AUDIO_ENABLE = no
BACKLIGHT_ENABLE = no   # Enable keyboard backlight functionality
BOOTMAGIC_ENABLE = yes	# Virtual DIP switch configuration
COMMAND_ENABLE = no     # Commands for debug and configuration
CONSOLE_ENABLE= no	# Console for debug
EXTRAKEY_ENABLE = yes	# Audio control and System control
MOUSEKEY_ENABLE = no	# Mouse keys
NKRO_ENABLE = no	# USB Nkey Rollover -

RGBLIGHT_ENABLE = no
SLEEP_LED_ENABLE = no   # Breathing sleep LED during USB suspend
UNICODE_ENABLE = no
TAP_DANCE_ENABLE = no
OLED_DRIVER_ENABLE = yes
