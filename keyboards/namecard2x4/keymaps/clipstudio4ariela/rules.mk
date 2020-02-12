
# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE = no       # Mouse keys(+4700)
EXTRAKEY_ENABLE = no       # Audio control and System control(+450)
CONSOLE_ENABLE = no         # Console for debug(+400)
COMMAND_ENABLE = no        # Commands for debug and configuration
NKRO_ENABLE = no            # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
MIDI_ENABLE = no            # MIDI controls
AUDIO_ENABLE = no           # Audio output on port C6
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight.
SWAP_HANDS_ENABLE = no        # Enable one-hand typing

LED_UNDERGLOW_ENABLE = no   # LED underglow (Enable WS2812 RGB underlight.)
IOS_DEVICE_ENABLE = no      # connect to IOS device (iPad,iPhone)
Link_Time_Optimization = no # if firmware size over limit, try this option

MODE_MAC = no

##    make NC24=<options> namecard2x4/rev1:clipstudio4ariela
##    option= under | mac | ios
##    ex.
##      make NC24=under         namecard2x4/rev1:clipstudio4ariela
##      make NC24=under,mac     namecard2x4/rev1:clipstudio4ariela
##      make NC24=mac,ios       namecard2x4/rev1:clipstudio4ariela
##      make NC24=under,mac,ios namecard2x4/rev1:clipstudio4ariela
##
ifneq ($(strip $(NC24)),)
    ifeq ($(findstring under,$(NC24)), under)
        LED_UNDERGLOW_ENABLE = yes
    endif
    ifeq ($(findstring mac,$(NC24)), mac)
        MODE_MAC = yes
    endif
    ifeq ($(findstring ios,$(HELIX)), ios)
        IOS_DEVICE_ENABLE = yes
    endif
    $(info )
endif

ifeq ($(strip $(LED_UNDERGLOW_ENABLE)), yes)
    RGBLIGHT_ENABLE = yes
else
    RGBLIGHT_ENABLE = no
endif

ifeq ($(strip $(IOS_DEVICE_ENABLE)), yes)
    OPT_DEFS += -DIOS_DEVICE_ENABLE
endif

ifeq ($(strip $(MODE_MAC)), yes)
    OPT_DEFS += -DMODE_MAC
endif

ifeq ($(strip $(Link_Time_Optimization)),yes)
    EXTRAFLAGS += -flto -DUSE_Link_Time_Optimization
endif

# Uncomment these for debugging
# $(info -- RGBLIGHT_ENABLE=$(RGBLIGHT_ENABLE))
# $(info -- OPT_DEFS=$(OPT_DEFS))
# $(info )
