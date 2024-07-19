// Copyright 2022 Aidan Smith (@Aidan-OS) (Code taken from him and modified by zeix)
// SPDX-License-Identifier: GPL-2.0-or-later
// cd qmk_firmware/keyboards/zeix/lain/graphics
// To generate the qgf file for the GIF: qmk painter-convert-graphics -f rgb565 -i my_image.gif -o .
// documentation here: https://github.com/qmk/qmk_firmware/blob/master/docs/quantum_painter.md?id=quantum-painter-cli
#include "quantum.h"
#include <qp.h>
//#include "graphics/anime.qgf.h"
#include "graphics1/luffy.qgf.h"

static painter_device_t display;
static painter_image_handle_t image;


void keyboard_post_init_kb(void) {
    // image = qp_load_image_mem(gfx_anime);    
    image = qp_load_image_mem(gfx_luffy);
    
    display = qp_st7789_make_spi_device(240, 300, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, 4, 3);
    qp_set_viewport_offsets(display, 0, 20);
    qp_init(display, QP_ROTATION_90);
    qp_power(display, true);

    if (image != NULL) {
      qp_animate(display, (300 - image->width), (220 - image->height) , image);  
    }
}


void suspend_power_down_user(void) {
    qp_power(display, false);
}
