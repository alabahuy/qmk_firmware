#pragma once

// Ambil config default RP2040 dari QMK terlebih dahulu
#include_next <mcuconf.h>

// ── SPI0 (SPID0) – GP18=SCK, GP19=MOSI → display ST7789 ──
#undef  RP_SPI_USE_SPI0
#define RP_SPI_USE_SPI0     TRUE

// ── PWM slice 3 (PWMD3) – GP22 = PWM3A → backlight ───────
// GP22 berada di PWM hardware slice 3 channel A.
// RP_PWM_USE_PWM3 mengaktifkan driver PWMD3 untuk slice tersebut.
#undef  RP_PWM_USE_PWM3
#define RP_PWM_USE_PWM3     TRUE
