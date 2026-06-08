#pragma once

// =========================================================
//  LCD ST7789 240x240 - Pin Definitions
// =========================================================
#define LCD_RST_PIN     GP17
#define LCD_CS_PIN      GP21
#define LCD_DC_PIN      GP20

// =========================================================
//  SPI Bus (SPI0 → SPID0)
//  SCK=GP18, MOSI=GP19, MISO=not used (display is write-only)
// =========================================================
#define SPI_DRIVER      SPID0
#define SPI_SCK_PIN     GP18
#define SPI_MOSI_PIN    GP19
#define SPI_MISO_PIN    NO_PIN

// =========================================================
//  Backlight PWM
//  GP22 → PWM Slice 3 Channel A (RP2040 pinout)
// =========================================================
#define BACKLIGHT_PWM_DRIVER    PWMD3
#define BACKLIGHT_PWM_CHANNEL   RP2040_PWM_CHANNEL_A

// =========================================================
//  Quantum Painter (QP) Settings
// =========================================================
// Jumlah animasi yang bisa berjalan bersamaan
#define QUANTUM_PAINTER_CONCURRENT_ANIMATIONS   4

// 0 = layar selalu menyala; isi angka (ms) untuk auto-off
#define QUANTUM_PAINTER_DISPLAY_TIMEOUT         0

// Jumlah slot gambar/font yang bisa dimuat sekaligus
#define QUANTUM_PAINTER_NUM_IMAGES              4

// Jika layar ST7789 kamu punya offset piksel, uncomment baris ini:
// #define LCD_OFFSET_X  0
// #define LCD_OFFSET_Y  0

// =========================================================
//  Bootmagic (hold key saat plug-in untuk reset)
//  Default: posisi [0,0] = ESC
// =========================================================
#define BOOTMAGIC_LITE_ROW      0
#define BOOTMAGIC_LITE_COLUMN   0
