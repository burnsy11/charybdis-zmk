MCU = RP2040
BOOTLOADER = rp2040

# Build Options
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output

# Split keyboard settings
SPLIT_KEYBOARD = yes

# Pointing device settings
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pmw3610

# Advanced features
COMBO_ENABLE = yes
TAP_DANCE_ENABLE = no
KEY_OVERRIDE_ENABLE = no

# Optimize for size
LTO_ENABLE = yes

# Serial communication for split
SERIAL_DRIVER = vendor