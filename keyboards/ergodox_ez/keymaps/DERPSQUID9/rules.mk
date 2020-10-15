# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file

# Custom Matrix
SRC = matrix.c

# Enable Features
LTO_ENABLE = yes           # Enable Link Time Optimization
DYNAMIC_MACRO_ENABLE = yes # Enable Dynamic Macros
RGB_MATRIX_ENABLE = yes    # Enable RGB Matrix

# Disable Unused Features
CONSOLE_ENABLE = no        # Disable debugging output
COMMAND_ENABLE = no        # Disable command
RGBLIGHT_ENABLE = no       # Disable RGB Light (RGB Matrix is already in use)
SWAP_HANDS_ENABLE = no     # Disable Swap Hands
