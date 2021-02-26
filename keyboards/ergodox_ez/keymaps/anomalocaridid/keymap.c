#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE,  // default layer
    FNCT,  // function keys
    MOUS,  // mouse keys
    ARRW,  // arrow keys
    KTTY,  // Kitty hotkeys
};

enum custom_keycodes {
    ALTCASE = EZ_SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Base layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  |NextFX|           | ARRW |   6  |   7  |   8  |   9  |   0  |ALTCASE |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  | FNCT |           | MOUS |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   -    |
 * |--------+------+------+------+------+------| KTTY |           |Delete|------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |   =    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | ESC  |  ~`  |  '"  | Left |Right |                                       |  Up  | Down |   [  |   ]  |        |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Hyper |L Win |       |R Win |  Meh   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |Cap/LA|       |R Alt |        |      |
 *                                 |Space |Tab/  |------|       |------| Enter/ |BackSp|
 *                                 |      |LCtrl |Shift(|       |Shift)| RCtrl  |      |
 *                                 `--------------------'       `----------------------'
 */
    [BASE] = LAYOUT_ergodox_pretty(
        XXXXXXX, KC_1,   KC_2,    KC_3,    KC_4,    KC_5, RGB_MOD,                           TG(ARRW), KC_6, KC_7,  KC_8,    KC_9,    KC_0,    ALTCASE,
        XXXXXXX, KC_Q,   KC_W,    KC_E,    KC_R,    KC_T, TT(FNCT),                          TG(MOUS), KC_Y, KC_U,  KC_I,    KC_O,    KC_P,    KC_BSLS,
        XXXXXXX, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                                              KC_H, KC_J,  KC_K,    KC_L,    KC_SCLN, KC_MINUS,
        XXXXXXX, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, TT(KTTY),                          KC_DEL,   KC_N, KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_EQL,
        KC_ESC,  KC_GRV, KC_QUOT, KC_LEFT, KC_RGHT,                                                          KC_UP, KC_DOWN, KC_LBRC, KC_RBRC, XXXXXXX,
                                                          HYPR_T(KC_CAPS), KC_LGUI, KC_RGUI, KC_MEH,
                                                                           KC_LALT, KC_RALT,
                                                KC_SPACE, LCTL_T(KC_TAB),  KC_LSPO, KC_RSPC, RCTL_T(KC_ENTER), KC_BSPC
  ),

/* Keymap 1: Function layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Mac1Rec |  F1  |  F2  |  F3  |  F4  |  F5  |NextFX|           |      |  F6  |  F7  |  F8  |  F9  |  F10 | Reset  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |Mac2Rec |  F11 |  F12 |  F13 |  F14 |  F15 | FNCT |           |      |  F16 |  F17 |  F18 |  F19 |  F20 |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Mac1Play|  F21 |  F22 |  F23 |  F24 |      |------|           |------|      |      |      |      |      | Hue++  |
 * |--------+------+------+------+------+------|      |           |Delete|------+------+------+------+------+--------|
 * |Mac2Play|      |      |      |      |      |      |           |      |      |      |      |      |      |Speed++ |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |RecStp|      |      |      |      |                                       |      |      |      |      |TogglRGB|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Hyper |L Win |       |R Win |  Meh   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |Cap/LA|       |R Alt |        |      |
 *                                 |Space |Tab/  |------|       |------| Enter/ |Space |
 *                                 |      |LCtrl |Shift(|       |Shift)| RCtrl  |      |
 *                                 `--------------------'       `----------------------'
 */
    [FNCT] = LAYOUT_ergodox_pretty(
        DM_REC1, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,                   XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  RESET,
        DM_REC2, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  _______,                   XXXXXXX, KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  XXXXXXX,
        DM_PLY1, KC_F21,  KC_F22,  KC_F23,  KC_F24,  XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUI,
        DM_PLY2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_SPI,
        DM_RSTP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,
                                                              _______, _______, _______, _______,
                                                                       _______, _______,
                                                     _______, _______, _______, _______, _______, _______
  ),

/* Keymap 2: Mouse layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |ALTCASE |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |      |           | MOUS |W Left|W Down| W Up |WRight|   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |   F  |   G  |------|           |------| Left | Down |  Up  |Right |   ;  |   -    |
 * |--------+------+------+------+------+------|      |           |Delete|------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |           |      |M Left|M Down| M Up |MRight|   /  |   =    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | ESC  |  `~  |  '"  | Left |Right |                                       |  Up  | Down |   [  |   ]  |        |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Hyper |L Win |       |R Win |Button 5|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |Cap/LA|       |Butt 4|        |      |
 *                                 |Space |Tab/  |------|       |------| RClick |LClick|
 *                                 |      |LCtrl |Shift(|       |MClick|        |      |
 *                                 `--------------------'       `----------------------'
 */
    [MOUS] = LAYOUT_ergodox_pretty(
        _______, _______, _______, _______, _______, _______, _______,                   XXXXXXX, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, XXXXXXX,                   _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______,
        _______, _______, _______, _______, _______, _______,                                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______, XXXXXXX,                   _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______,
                                                              _______, _______, _______, KC_BTN5,
                                                                       _______, KC_BTN4,
                                                     _______, _______, _______, KC_BTN3, KC_BTN2, KC_BTN1
  ),

/* Keymap 3: Arrow layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  |NextFX|           | ARRW |   6  |   7  |   8  |   9  |   0  |ALTCASE |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |  Up  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  | Left | Down |Right |   ;  |   -    |
 * |--------+------+------+------+------+------|      |           |Delete|------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |   =    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | ESC  |  `~  |  '"  | Left |Right |                                       |  Up  | Down |   [  |   ]  |        |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Hyper |L Win |       |R Win |  Meh   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |Cap/LA|       |L Alt |        |      |
 *                                 |Space |Tab/  |------|       |------| Enter/ |BackSp|
 *                                 |      |LCtrl |Shift(|       |Shift)| RCtrl  |      |
 *                                 `--------------------'       `----------------------'
 */
    [ARRW] = LAYOUT_ergodox_pretty(
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, XXXXXXX,                   XXXXXXX, _______, _______, KC_UP,   _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                     _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______, XXXXXXX,                   _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______,
                                                              _______, _______, _______, _______,
                                                                       _______, _______,
                                                     _______, _______, _______, _______, _______, _______
  ),

/* Keymap 4: Kitty layer
 * An asterisk (*) means CTRL+SHIFT+<key> where <key> is the key's value
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   1* |   2* |   3* |   4* |   5* | F2*  |           |Alt-T*|   6* |   7* |   8* |   9* |   0* |ALTCASE |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q* |   W* |   E* |   R  |   T* |      |           |Enter*|   Y  |   U* |   I  |   O* |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   S* |   D  |   F* |   G  |------|           |------|   H  |   J  |   K  |   L* |   ;  |   -    |
 * |--------+------+------+------+------+------| KTTY |           |Delete|------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C* |   V* |   B* |      |           |      |   N* |   M  |   ,* |   .* |   /  |   =    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | ESC* |  `*  |  '"  | Left*|Right*|                                       |  Up* | Down*|   [* |   ]* |        |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Hyper |L Win |       |R Win |  Meh   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |Cap/LA|       |R Alt |        |      |
 *                                 |Space |Tab/  |------|       |------| Enter/ |BackSp |
 *                                 |      |LCtrl |Shift(|       |Shift)| RCtrl  |      |
 *                                 `--------------------'       `----------------------'
 */
    [KTTY] = LAYOUT_ergodox_pretty(
        _______,        RCS(KC_1),     RCS(KC_2), RCS(KC_3),    RCS(KC_4),     RCS(KC_5), RCS(KC_F2),                MEH(KC_T),     RCS(KC_6),  RCS(KC_7),    RCS(KC_8),        RCS(KC_9),        RCS(KC_0), _______,
        _______,        RCS(KC_Q),     RCS(KC_W), RCS(KC_E),    _______,       RCS(KC_T), XXXXXXX,                   RCS(KC_ENTER), _______,    RCS(KC_U),    _______,          RCS(KC_O),        _______,   _______,
        _______,        _______,       RCS(KC_S), _______,      RCS(KC_F),     _______,                                             _______,    _______,      _______,          RCS(KC_L),        _______,   _______,
        _______,        _______,       _______,   RCS(KC_C),    RCS(KC_V),     RCS(KC_B), _______,                   _______,       RCS(KC_N),  _______,      RCS(KC_COMMA),    RCS(KC_DOT),      _______,   _______,
        RCS(KC_ESCAPE), RCS(KC_GRAVE), _______,   RCS(KC_LEFT), RCS(KC_RIGHT),                                                      RCS(KC_UP), RCS(KC_DOWN), RCS(KC_LBRACKET), RCS(KC_RBRACKET), _______,
                                                                               _______, _______, _______, _______,
                                                                                        _______, _______,
                                                                      _______, _______, _______, _______, _______, _______
  ),
};
// clang-format on

extern bool         g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable_noeeprom();
    rgb_matrix_sethsv_noeeprom(HSV_MAGENTA);
    rgb_matrix_mode_noeeprom(RGB_MATRIX_MULTISPLASH);
    rgb_matrix_set_speed_noeeprom(60);
}

// Macro for formatting per-key LED layouts
// Numbering intended to match respective keys in LAYOUT_ergodox_pretty
// And skips non-led keys
// clang-format off
#define LED_LAYOUT_ergodox_ez_pretty(               \
/*  ---- LEFT HAND ----     ---- RIGHT HAND ---- */ \
    L01,L02,L03,L04,L05,    R01,R02,R03,R04,R05,    \
    L11,L12,L13,L14,L15,    R11,R12,R13,R14,R15,    \
    L21,L22,L23,L24,L25,    R21,R22,R23,R24,R25,    \
    L31,L32,L33,L34,L35,    R31,R32,R33,R34,R35,    \
    L41,L42,L43,L44,            R42,R43,R44,R45     \
)                                                   \
                                                    \
{                                                   \
    /* Right Hand */                                \
    {R01}, {R02}, {R03}, {R04}, {R05},              \
    {R11}, {R12}, {R13}, {R14}, {R15},              \
    {R21}, {R22}, {R23}, {R24}, {R25},              \
    {R31}, {R32}, {R33}, {R34}, {R35},              \
           {R42}, {R43}, {R44}, {R45},              \
                                                    \
    /* Left Hand (Flipped Horizontally) */          \
    {L05}, {L04}, {L03}, {L02}, {L01},              \
    {L15}, {L14}, {L13}, {L12}, {L11},              \
    {L25}, {L24}, {L23}, {L22}, {L21},              \
    {L35}, {L34}, {L33}, {L32}, {L31},              \
           {L44}, {L43}, {L42}, {L41},              \
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [FNCT] = LED_LAYOUT_ergodox_ez_pretty(
        HSV_PURPLE, HSV_PURPLE, HSV_PURPLE, HSV_PURPLE, HSV_PURPLE,        HSV_PURPLE, HSV_PURPLE, HSV_PURPLE, HSV_PURPLE, HSV_PURPLE,
        HSV_PURPLE, HSV_PURPLE, HSV_PURPLE, HSV_PURPLE, HSV_PURPLE,        HSV_PURPLE, HSV_PURPLE, HSV_PURPLE, HSV_PURPLE, HSV_PURPLE,
        HSV_PURPLE, HSV_PURPLE, HSV_PURPLE, HSV_PURPLE, HSV_OFF,           HSV_OFF,    HSV_OFF,    HSV_OFF,    HSV_OFF,    HSV_OFF,
        HSV_OFF,    HSV_OFF,    HSV_OFF,    HSV_OFF,    HSV_OFF,           HSV_OFF,    HSV_OFF,    HSV_OFF,    HSV_OFF,    HSV_OFF,
        HSV_OFF,    HSV_OFF,    HSV_OFF,    HSV_OFF,                                   HSV_OFF,    HSV_OFF,    HSV_OFF,    HSV_OFF
    ),

    [MOUS] = LED_LAYOUT_ergodox_ez_pretty(
        HSV_OFF, HSV_OFF, HSV_OFF, HSV_OFF, HSV_OFF,        HSV_OFF,     HSV_OFF,     HSV_OFF,     HSV_OFF,     HSV_OFF,
        HSV_OFF, HSV_OFF, HSV_OFF, HSV_OFF, HSV_OFF,        HSV_MAGENTA, HSV_MAGENTA, HSV_MAGENTA, HSV_MAGENTA, HSV_OFF,
        HSV_OFF, HSV_OFF, HSV_OFF, HSV_OFF, HSV_OFF,        HSV_PURPLE,  HSV_PURPLE,  HSV_PURPLE,  HSV_PURPLE,  HSV_OFF,
        HSV_OFF, HSV_OFF, HSV_OFF, HSV_OFF, HSV_OFF,        HSV_BLUE,    HSV_BLUE,    HSV_BLUE,    HSV_BLUE,    HSV_OFF,
        HSV_OFF, HSV_OFF, HSV_OFF, HSV_OFF,                              HSV_OFF,     HSV_OFF,     HSV_OFF,     HSV_OFF
    ),

    [ARRW] = LED_LAYOUT_ergodox_ez_pretty(
        HSV_OFF, HSV_OFF, HSV_OFF, HSV_OFF, HSV_OFF,        HSV_OFF, HSV_OFF, HSV_OFF, HSV_OFF, HSV_OFF,
        HSV_OFF, HSV_OFF, HSV_OFF, HSV_OFF, HSV_OFF,        HSV_OFF, HSV_OFF, HSV_RED, HSV_OFF, HSV_OFF,
        HSV_OFF, HSV_OFF, HSV_OFF, HSV_OFF, HSV_OFF,        HSV_OFF, HSV_RED, HSV_RED, HSV_RED, HSV_OFF,
        HSV_OFF, HSV_OFF, HSV_OFF, HSV_OFF, HSV_OFF,        HSV_OFF, HSV_OFF, HSV_OFF, HSV_OFF, HSV_OFF,
        HSV_OFF, HSV_OFF, HSV_OFF, HSV_OFF,                          HSV_OFF, HSV_OFF, HSV_OFF, HSV_OFF
    ),

    [KTTY] = LED_LAYOUT_ergodox_ez_pretty(
        HSV_RED,  HSV_RED,    HSV_RED,    HSV_RED,    HSV_RED,        HSV_RED, HSV_RED,    HSV_RED,    HSV_RED,    HSV_RED,
        HSV_BLUE, HSV_RED,    HSV_PURPLE, HSV_OFF,    HSV_BLUE,       HSV_OFF, HSV_PURPLE, HSV_OFF,    HSV_PURPLE, HSV_OFF,
        HSV_OFF,  HSV_PURPLE, HSV_OFF,    HSV_RED,    HSV_OFF,        HSV_OFF, HSV_OFF,    HSV_OFF,    HSV_BLUE,   HSV_OFF,
        HSV_OFF,  HSV_OFF,    HSV_PURPLE, HSV_PURPLE, HSV_RED,        HSV_RED, HSV_OFF,    HSV_BLUE,   HSV_BLUE,   HSV_OFF,
        HSV_RED,  HSV_OFF,    HSV_BLUE,   HSV_BLUE,                            HSV_PURPLE, HSV_PURPLE, HSV_RED,    HSV_RED
    ),

};
// clang-format on

void set_layer_color(int layer) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

void rgb_matrix_indicators_user(void) {
    if (g_suspend_state || keyboard_config.disable_layer_led) {
        return;
    }

    uint8_t layer = biton32(layer_state);

    if (layer > BASE) {
        set_layer_color(layer);
    }
}

static bool alt_case_toggle = false;
static bool alt_case_shift  = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_A ... KC_Z:
            if (alt_case_toggle && record->event.pressed) {
                if (alt_case_shift) {
                    set_oneshot_mods(get_oneshot_mods() | MOD_MASK_SHIFT);
                }
                alt_case_shift ^= 1;
            }
            return true;
        case ALTCASE:
            if (record->event.pressed) {
                alt_case_toggle ^= 1;
                alt_case_shift = false;
            }
            return false;
    }

    return true;
}

uint32_t layer_state_set_user(uint32_t state) {
    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }
    return state;
};

// Everything below this line enables a blinking red LED
// When a dynamic macro is being recorded
static bool is_dynamic_recording = false;

void dynamic_macro_record_start_user(void) {
    is_dynamic_recording = true;
    ergodox_right_led_1_on();
}

void dynamic_macro_record_end_user(int8_t direction) { is_dynamic_recording = false; }

void matrix_scan_user(void) {
    if (is_dynamic_recording) {
        ergodox_right_led_1_off();

        static uint8_t counter;
        counter++;

        if (counter > 100) {
            ergodox_right_led_1_on();
        }
    }
}
