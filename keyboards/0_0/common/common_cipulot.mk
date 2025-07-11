CUSTOM_MATRIX = lite
ANALOG_DRIVER_REQUIRED = yes
VPATH += keyboards/0_0/common
SRC += keyboards/0_0/common/matrix.c
SRC += keyboards/0_0/common/ec_board.c
SRC += keyboards/0_0/common/ec_switch_matrix.c

ifeq ($(strip $(VIA_ENABLE)), yes)
    SRC += via_ec.c
endif
