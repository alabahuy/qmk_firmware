#pragma once

// ── SPI (dibutuhkan oleh Quantum Painter ST7789) ──────────
#define HAL_USE_SPI         TRUE
#define SPI_USE_WAIT        TRUE
#define SPI_SELECT_MODE     SPI_SELECT_MODE_PAD

// ── PWM (dibutuhkan oleh Backlight GP22) ─────────────────
// Tanpa ini: PWMConfig, PWMD3, pwmStart dll. tidak dikenal compiler
#define HAL_USE_PWM         TRUE

// Teruskan ke file halconf.h bawaan QMK/ChibiOS
#include_next <halconf.h>
