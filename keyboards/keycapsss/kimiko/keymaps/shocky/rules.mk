OLED_ENABLE = no
ENCODER_ENABLE = no       # Enables the use of one or more encoders
RGBLIGHT_ENABLE = yes     # Enable keyboard RGB underglow

# LTO: Link Time Optimizations.
# Reduce compiled size, but will automatically disable the legacy TMK Macros and Functions features.
# This does not affect QMK Macros and Layers
LTO_ENABLE = yes


MOUSEKEY_ENABLE = yes # Mouse keys
EXTRAKEY_ENABLE = yes # Audio control and System control
AUTO_SHIFT_ENABLE = yes # Auto Shift - long hold to shift, e.g. 5 -> %
DYNAMIC_TAPPING_TERM_ENABLE = yes # adjusting how long it takes to press shift
KEY_OVERRIDE_ENABLE = yes  # overrides, eg shift + comma = `;`
COMBO_ENABLE = yes  # enable chording combo's
REPEAT_KEY_ENABLE = no
CAPS_WORD_ENABLE = yes

# Load the necessary external C files if and only if
# the associated config option has been enabled
ifeq ($(strip $(COMBO_ENABLE)), yes)
	VPATH += keyboards/gboards
endif
