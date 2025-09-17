#pragma once

/* --- Matrix size (total across both halves) --- */
#define MATRIX_ROWS 6
#define MATRIX_COLS 7

/* --- Diodes --- */
#define DIODE_DIRECTION ROW2COL  

/* --- Left-half pins (your previous wiring) --- */
#define MATRIX_ROW_PINS { F6, F7, B1 }
#define MATRIX_COL_PINS { D3, D4, C6, D7, E6, B4, B5 }



/* --- Split transport (single-wire soft serial) --- */
#define USE_SERIAL
#define SOFT_SERIAL_PIN D2        

/* --- Handedness --- */
#define EE_HANDS              

/* --- Optional but recommended --- */
#define DEBOUNCE 5
#define TAPPING_TERM 200
#define NO_USB_STARTUP_CHECK
