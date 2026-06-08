# =========================================================
#  rules.mk  –  AL Custom 60
# =========================================================

# --- Quantum Painter (ST7789 via SPI) --------------------
QUANTUM_PAINTER_ENABLE   = yes
QUANTUM_PAINTER_DRIVERS += st7789_spi

# --- WPM counter (dipakai di display) --------------------
WPM_ENABLE = yes

# --- Hapus komentar di bawah kalau mau tambah font -------
# Cara konversi font:
#   qmk painter-convert-graphics -t font -f your_font.ttf -o keyboards/al_custom60/
# Lalu uncomment baris berikut dan sesuaikan nama file:
# SRC += keyboards/al_custom60/your_font.qff.c

# --- Hapus komentar kalau mau tambah gambar/logo ---------
# qmk painter-convert-graphics -t image -f logo.png -o keyboards/al_custom60/
# SRC += keyboards/al_custom60/logo.qgf.c
