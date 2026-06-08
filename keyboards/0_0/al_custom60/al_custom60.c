#include "al_custom60.h"
#include "qp.h"

// =========================================================
//  Quantum Painter – ST7789 240×240
//  Palette warna pakai HSV (Hue 0-255, Sat 0-255, Val 0-255)
//    Hue: 0=merah, 85=hijau, 128=cyan, 170=biru, 213=ungu
//
//  hsv_t sudah tersedia dari quantum/color.h (field: h, s, v)
//  JANGAN definisikan ulang di sini.
// =========================================================

static painter_device_t display;
static bool             display_ready = false;

// Warna latar per layer (hue, sat, val) — pakai hsv_t bawaan QMK
static const hsv_t LAYER_COLOR[] = {
    {170, 180,  80},   // Layer 0 – Biru
    {  0, 200,  90},   // Layer 1 – Merah  (FN)
    { 85, 180,  80},   // Layer 2 – Hijau
    {213, 180,  80},   // Layer 3 – Ungu
};

// ─── Gambar latar & bingkai sekali saat init ─────────────
static void display_draw_background(uint8_t layer) {
    hsv_t c = (layer < 4) ? LAYER_COLOR[layer] : LAYER_COLOR[0];

    // Background penuh
    qp_rect(display, 0, 0, 239, 239, 0, 0, 8, true);

    // Header bar
    qp_rect(display, 0, 0, 239, 34, c.h, c.s, c.v, true);
    // Garis bawah header
    qp_rect(display, 0, 35, 239, 36, c.h, c.s, 200, true);

    // Area layer indicator
    qp_rect(display, 0, 44, 239, 120, 0, 0, 14, true);

    // Area WPM
    qp_rect(display, 0, 128, 239, 195, 0, 0, 12, true);
    qp_rect(display, 0, 127, 239, 128, c.h, 100, 120, true); // divider

    // Area status (CapsLock, dll)
    qp_rect(display, 0, 203, 239, 239, 0, 0, 10, true);
    qp_rect(display, 0, 202, 239, 203, c.h, 100, 100, true); // divider
}

// ─── Update indikator layer ───────────────────────────────
void display_set_layer(uint8_t layer) {
    if (!display_ready) return;

    display_draw_background(layer);

    // Kotak indikator kecil untuk 4 layer
    for (uint8_t i = 0; i < 4; i++) {
        uint16_t x0 = 12 + i * 56;
        uint16_t x1 = x0 + 44;
        hsv_t    c  = LAYER_COLOR[i];

        if (i == layer) {
            qp_rect(display, x0,     50, x1,     114, c.h, c.s,   c.v,   true);
            qp_rect(display, x0 - 1, 49, x1 + 1, 115, c.h, 255,   255,   false);
        } else {
            qp_rect(display, x0, 50, x1, 114, c.h, c.s / 3, c.v / 4, true);
        }
    }

    qp_flush(display); // pastikan semua piksel terkirim ke panel
}

// ─── Update bar WPM ──────────────────────────────────────
static void display_update_wpm(uint8_t wpm) {
    if (!display_ready) return;

    uint16_t capped   = (wpm > 200) ? 200 : wpm;
    uint16_t bar_w    = (uint16_t)(capped * 234 / 200);

    qp_rect(display, 2, 140, 237, 188, 0, 0, 12, true);

    if (bar_w > 0) {
        uint8_t hue = (uint8_t)(170 - (uint8_t)(capped * 85 / 200));
        qp_rect(display, 2, 148, 2 + bar_w, 180, hue, 220, 220, true);
    }

    qp_rect(display, 2, 148, 237, 180, 0, 0, 20, false);
    qp_flush(display);
}

// ─── Update status LED (CapsLock, dll) ───────────────────
static void display_update_leds(led_t leds) {
    if (!display_ready) return;

    if (leds.caps_lock) {
        qp_rect(display,   8, 210,  80, 235, 0,   230, 230, true);
        qp_rect(display,   8, 210,  80, 235, 0,   255, 255, false);
    } else {
        qp_rect(display,   8, 210,  80, 235, 0,   0,    20, true);
        qp_rect(display,   8, 210,  80, 235, 0,   0,    50, false);
    }

    if (leds.num_lock) {
        qp_rect(display,  90, 210, 160, 235, 85,  200, 220, true);
        qp_rect(display,  90, 210, 160, 235, 85,  255, 255, false);
    } else {
        qp_rect(display,  90, 210, 160, 235, 0,   0,    20, true);
        qp_rect(display,  90, 210, 160, 235, 0,   0,    50, false);
    }

    qp_flush(display);
}

// =========================================================
//  QMK Callbacks
// =========================================================

void keyboard_post_init_kb(void) {
    // ── 1. Nyalakan backlight di level maksimum ──────────
    // Tanpa ini layar bisa gelap total meski display sudah jalan
    backlight_level(BACKLIGHT_LEVELS);

    // ── 2. Tunggu display stabil setelah power-on ────────
    // ST7789 butuh ~100-150ms setelah VCC naik sebelum bisa terima perintah
    wait_ms(150);

    // ── 3. Buat device ST7789 via SPI0 ──────────────────
    // (CS=GP21, DC=GP20, RST=GP17, divisor=4 → ~31MHz, mode=0)
    display = qp_st7789_make_spi_device(240, 240,
                                         LCD_CS_PIN,
                                         LCD_DC_PIN,
                                         LCD_RST_PIN,
                                         4,    // SPI divisor: 125MHz/4 ≈ 31MHz
                                         0);   // SPI mode 0 (CPOL=0 CPHA=0)

    if (display != NULL) {
        // ── 4. Init display – cek return value ──────────
        if (qp_init(display, QP_ROTATION_0)) {
            qp_power(display, true);
            wait_ms(20); // tunggu panel aktif setelah power on

            // ── 5. TES DIAGNOSTIK ────────────────────────
            // Isi layar MERAH selama 1 detik.
            // Jika layar menyala merah  → SPI OK, lanjut ke UI normal.
            // Jika layar tetap blank    → cek: kabel, pin CS/DC/RST,
            //                             atau coba ganti SPI divisor (8/16).
            qp_rect(display, 0, 0, 239, 239, 0, 255, 220, true);
            qp_flush(display);
            wait_ms(1000);

            // ── 6. Gambar UI normal ──────────────────────
            display_ready = true;
            display_set_layer(0);
            display_update_leds((led_t){0});

        }
        // qp_init gagal: display NULL / SPI tidak terhubung
        // Coba kurangi kecepatan SPI → ganti angka 4 di atas jadi 8 atau 16
    }

    keyboard_post_init_user();
}

// Dipanggil setiap kali layer berubah
layer_state_t layer_state_set_kb(layer_state_t state) {
    display_set_layer(get_highest_layer(state));
    return layer_state_set_user(state);
}

// Dipanggil setiap kali LED status berubah (CapsLock, dll)
bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if (res) {
        display_update_leds(led_state);
    }
    return res;
}

// Dipanggil terus-menerus di main loop → update WPM setiap 500ms
void housekeeping_task_kb(void) {
    if (display_ready) {
        static uint32_t last_wpm_tick = 0;
        if (timer_elapsed32(last_wpm_tick) >= 500) {
            last_wpm_tick = timer_read32();
#ifdef WPM_ENABLE
            display_update_wpm(get_current_wpm());
#endif
        }
    }
    housekeeping_task_user();
}
