#AUDIO_ENABLE = yes          # Audio output
#AUDIO_DRIVER = pwm_hardware

QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS += st7789_spi

LTO_ENABLE = yes

#POINTING_DEVICE_ENABLE = yes
#POINTING_DEVICE_DRIVER = analog_joystick

#Additional Configuration to fix compiler issue
OPT_DEFS = -O2
EXTRALDFLAGS = -Wl,--defsym,FLASH_LEN=8192k
#DEFERRED_EXEC_ENABLE = yes

#SRC += graphics1/anime.qgf.c
SRC += graphics/win.qgf.c