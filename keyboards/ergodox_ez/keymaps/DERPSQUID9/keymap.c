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
    RGB_SLD = EZ_SAFE_RANGE,
    ALTCASE,
};

enum tap_dance {
    TD_GESC,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for grave
    [TD_GESC] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_GRAVE),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Base layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Hue++  |   1  |   2  |   3  |   4  |   5  |ChngFx|           | ARRW |   6  |   7  |   8  |   9  |   0  | C+A+D  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Hue--  |   Q  |   W  |   E  |   R  |   T  | FNCT |           | MOUS |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Mac1Play|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   -    |
 * |--------+------+------+------+------+------| KTTY |           | BkSp |------+------+------+------+------+--------|
 * |Mac2Play|   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |   =    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |RecStp|ESC/~`|  '"  | Left |Right |                                       |  Up  | Down |   [  |   ]  |ALTCASE |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |CAP/Hy|L Win |       |R Win |  Meh   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |L Alt |       |Del/RA|        |      |
 *                                 |Space |Tab/  |------|       |------| Enter/ |Space |
 *                                 |      |LCtrl |Shift(|       |Shift)| RCtrl  |      |
 *                                 `--------------------'       `----------------------'
 */
    [BASE] = LAYOUT_ergodox_pretty(
        RGB_HUI,         KC_1,        KC_2,     KC_3,    KC_4,     KC_5, RGB_MOD,                                                 TG(ARRW),  KC_6, KC_7,  KC_8,     KC_9,        KC_0,        RALT(RCTL(KC_DELETE)),
        RGB_HUD,         KC_Q,        KC_W,     KC_E,    KC_R,     KC_T, TT(FNCT),                                                TG(MOUS),  KC_Y, KC_U,  KC_I,     KC_O,        KC_P,        KC_BSLASH,
        DYN_MACRO_PLAY1, KC_A,        KC_S,     KC_D,    KC_F,     KC_G,                                                                     KC_H, KC_J,  KC_K,     KC_L,        KC_SCOLON,   KC_MINUS,
        DYN_MACRO_PLAY2, KC_Z,        KC_X,     KC_C,    KC_V,     KC_B, TT(KTTY),                                                KC_BSPACE, KC_N, KC_M,  KC_COMMA, KC_DOT,      KC_SLASH,    KC_EQUAL,
        DYN_REC_STOP,    TD(TD_GESC), KC_QUOTE, KC_LEFT, KC_RIGHT,                                                                                 KC_UP, KC_DOWN,  KC_LBRACKET, KC_RBRACKET, ALTCASE,
                                                                         MT(MOD_HYPR, KC_CAPSLOCK),   KC_LGUI, KC_RGUI,           KC_MEH,
                                                                                                      KC_LALT, RALT_T(KC_DELETE),
                                                                         KC_SPACE,    LCTL_T(KC_TAB), KC_LSPO, KC_RSPC,           RCTL_T(KC_ENTER), KC_SPACE
  ),

/* Keymap 1: Function layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Mac1Rec |  F1  |  F2  |  F3  |  F4  |  F5  |ChngFx|           | ARRW |  F6  |  F7  |  F8  |  F9  |  F10 | RESET  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |Mac2Rec |  F11 |  F12 |  F13 |  F14 |  F15 | FNCT |           | MOUS |  F16 |  F17 |  F18 |  F19 |  F20 |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Mac1Play|  F21 |  F22 |  F23 |  F24 |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------| KTTY |           | BkSp |------+------+------+------+------+--------|
 * |Mac2Play|      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |RecStp|      |      |      |      |                                       |      |      |      |      |Stop Fx |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |CAP/Hy| LWin |       | RWin |  Meh   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |Esc/LA|       |Del/RA|        |      |
 *                                 |Space |Tab/  |------|       |------| Enter/ |Space |
 *                                 |      |LCtrl |Shift(|       |Shift)| RCtrl  |      |
 *                                 `--------------------'       `----------------------'
 */
    [FNCT] = LAYOUT_ergodox_pretty(
        DYN_REC_START1, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,                   _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  RESET,
        DYN_REC_START2, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  _______,                   _______, KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  XXXXXXX,
        _______,        KC_F21,  KC_F22,  KC_F23,  KC_F24,  XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_SLD,
                                                                     _______, _______, _______, _______,
                                                                              _______, _______,
                                                            _______, _______, _______, _______, _______, _______
  ),

/* Keymap 2: Mouse layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Hue++  |   1  |   2  |   3  |   4  |   5  |ChngFx|           | ARRW |   6  |   7  |   8  |   9  |   0  | C+A+D  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Hue--  |   Q  |   W  |   E  |   R  |   T  | FNCT |           | MOUS |W Left|W Down| W Up |WRight|   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Mac1Play|   A  |   S  |   D  |   F  |   G  |------|           |------| Left | Down |  Up  |Right |   ;  |   -    |
 * |--------+------+------+------+------+------| KTTY |           | BkSp |------+------+------+------+------+--------|
 * |Mac2Play|   Z  |   X  |   C  |   V  |   B  |      |           |      |M Left|M Down| M Up |MRight|   /  |   =    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |RecStp|  `~  |  '"  | Left |Right |                                       |  Up  | Down |   [  |   ]  |ALTCASE |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |CAP/Hy| LWin |       | RWin |Button 5|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |Esc/LA|       |Butt 4|        |      |
 *                                 |Space |Tab/  |------|       |------| RClick |LClick|
 *                                 |      |LCtrl |Shift(|       |MClick|        |      |
 *                                 `--------------------'       `----------------------'
 */
    [MOUS] = LAYOUT_ergodox_pretty(
        _______, _______, _______, _______, _______, _______, _______,                      _______, _______,       _______,       _______,     _______,        _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                      _______, KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT, _______, _______,
        _______, _______, _______, _______, _______, _______,                                        KC_LEFT,       KC_DOWN,       KC_UP,       KC_RIGHT,       _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                      _______, KC_MS_LEFT,    KC_MS_DOWN,    KC_MS_UP,    KC_MS_RIGHT,    _______, _______,
        _______, _______, _______, _______, _______,                                                                _______,       _______,     _______,        _______, _______,
                                                              _______, _______, _______,    KC_MS_BTN5,
                                                                       _______, KC_MS_BTN4,
                                                     _______, _______, _______, KC_MS_BTN3, KC_MS_BTN2, KC_MS_BTN1
  ),

/* Keymap 3: Arrow layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Hue++  |   1  |   2  |   3  |   4  |   5  |ChngFx|           | ARRW |   6  |   7  |   8  |   9  |   0  | C+A+D  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Hue--  |   Q  |   W  |   E  |   R  |   T  | FNCT |           | MOUS |   Y  |   U  |  Up  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Mac1Play|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  | Left | Down |Right |   ;  |   -    |
 * |--------+------+------+------+------+------| KTTY |           | BkSp |------+------+------+------+------+--------|
 * |Mac2Play|   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |   =    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |RecStp|  `~  |  '"  | Left |Right |                                       |  Up  | Down |   [  |   ]  |ALTCASE |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |CAP/Hy| LWin |       | RWin |  Meh   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |Esc/LA|       |Del/RA|        |      |
 *                                 |Space |Tab/  |------|       |------| Enter/ |Space |
 *                                 |      |LCtrl |Shift(|       |Shift)| RCtrl  |      |
 *                                 `--------------------'       `----------------------'
 */
    [ARRW] = LAYOUT_ergodox_pretty(
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, KC_UP,   _______,  _______, _______,
        _______, _______, _______, _______, _______, _______,                                     _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______,                                                       _______, _______, _______,  _______, _______,
                                                              _______, _______, _______, _______,
                                                                       _______, _______,
                                                     _______, _______, _______, _______, _______, _______
  ),

/* Keymap 4: Kitty layer
 * An asterisk (*) means CTRL+SHIFT+<key> where <key> is the key's value
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Hue++  |   1* |   2* |   3* |   4* |   5* | F2*  |           |Alt-T*|   6* |   7* |   8* |   9* |   0* | C+A+D  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Hue--  |   Q* |   W* |   E* |   R  |   T* | Esc* |           |Enter*|   Y  |   U* |   I  |   O* |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Mac1Play|   A  |   S* |   D  |   F* |   G  |------|           |------|   H  |   J  |   K  |   L* |   ;  |   -    |
 * |--------+------+------+------+------+------| TT 5 |           | BkSp |------+------+------+------+------+--------|
 * |Mac2Play|   Z  |   X  |   C* |   V* |   B* |      |           |      |   N* |   M  |   ,* |   .* |   /  |   =    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |RecStp|  `*  |  '"  | Left*|Right*|                                       |  Up* | Down*|   [* |   ]* |ALTCASE |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |CAP/Hy| LWin |       | RWin |  Meh   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |Esc/LA|       |Del/RA|        |      |
 *                                 |Space |Tab/  |------|       |------| Enter/ |Space |
 *                                 |      |LCtrl |Shift(|       |Shift)| RCtrl  |      |
 *                                 `--------------------'       `----------------------'
 */
    [KTTY] = LAYOUT_ergodox_pretty(
        _______, RCS(KC_1),    RCS(KC_2), RCS(KC_3),    RCS(KC_4),     RCS(KC_5), RCS(KC_F2),                RALT(RCS(KC_T)), RCS(KC_6),  RCS(KC_7),    RCS(KC_8),        RCS(KC_9),        RCS(KC_0), _______,
        _______, RCS(KC_Q),    RCS(KC_W), RCS(KC_E),    _______,       RCS(KC_T), RCS(KC_ESCAPE),            RCS(KC_ENTER),   _______,    RCS(KC_U),    _______,          RCS(KC_O),        _______,   _______,
        _______, _______,      RCS(KC_S), _______,      RCS(KC_F),     _______,                                               _______,    _______,      _______,          RCS(KC_L),        _______,   _______,
        _______, _______,      _______,   RCS(KC_C),    RCS(KC_V),     RCS(KC_B), _______,                   _______,         RCS(KC_N),  _______,      RCS(KC_COMMA),    RCS(KC_DOT),      _______,   _______,
        _______, RCS(KC_GRAVE), _______,  RCS(KC_LEFT), RCS(KC_RIGHT),                                                        RCS(KC_UP), RCS(KC_DOWN), RCS(KC_LBRACKET), RCS(KC_RBRACKET), _______,
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
    // rgb_matrix_sethsv_noeeprom(215, 255, 255);
    rgb_matrix_sethsv_noeeprom(HSV_MAGENTA);
    rgb_matrix_mode_noeeprom(RGB_MATRIX_MULTISPLASH);
}

// clang-format off
const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
              // Right hand
    [FNCT] = {{205, 255, 255}, {205, 255, 255}, {205, 255, 255}, {205, 255, 255}, {205, 255, 255},
              {205, 255, 255}, {205, 255, 255}, {205, 255, 255}, {205, 255, 255}, {205, 255, 255},
              {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},
              {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},
                               {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},

              // Left Hand (flipped)
              {205, 255, 255}, {205, 255, 255}, {205, 255, 255}, {205, 255, 255}, {205, 255, 255},
              {205, 255, 255}, {205, 255, 255}, {205, 255, 255}, {205, 255, 255}, {205, 255, 255},
              {0, 0, 0},       {205, 255, 255}, {205, 255, 255}, {205, 255, 255}, {205, 255, 255},
              {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},
                               {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0}},      

              // Right hand
    [MOUS] = {{0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0}, 
              {233, 218, 217}, {233, 218, 217}, {233, 218, 217}, {233, 218, 217}, {0, 0, 0},
              {205, 255, 255}, {205, 255, 255}, {205, 255, 255}, {205, 255, 255}, {0, 0, 0},
              {180, 255, 233}, {180, 255, 233}, {180, 255, 233}, {180, 255, 233}, {0, 0, 0},
                               {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},

              // Left Hand (flipped)
              {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
              {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
              {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
              {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
                         {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},

              // Right hand
    [ARRW] = {{0, 0, 0}, {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},
              {0, 0, 0}, {0, 0, 0},       {255, 220, 201}, {0, 0, 0},       {0, 0, 0},
              {0, 0, 0}, {255, 220, 201}, {255, 220, 201}, {255, 220, 201}, {0, 0, 0},
              {0, 0, 0}, {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},
                         {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},

              // Left Hand (flipped)
              {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
              {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
              {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
              {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
                         {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},

              // Right hand
    [KTTY] = {{255, 220, 201}, {255, 220, 201}, {255, 220, 201}, {255, 220, 201}, {255, 220, 201},
              {0, 0, 0},       {205, 255, 255}, {0, 0, 0},       {205, 255, 255}, {0, 0, 0},
              {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {180, 255, 233}, {0, 0, 0},
              {255, 220, 201}, {0, 0, 0},       {180, 255, 233}, {180, 255, 233}, {0, 0, 0},
                               {205, 255, 255}, {205, 255, 255}, {255, 220, 201}, {255, 220, 201},

              // Left Hand (flipped)
              {255, 220, 201}, {255, 220, 201}, {255, 220, 201}, {255, 220, 201}, {255, 220, 201},
              {180, 255, 233}, {0, 0, 0},       {205, 255, 255}, {255, 220, 201}, {180, 255, 233},
              {0, 0, 0},       {255, 220, 201}, {0, 0, 0},       {205, 255, 255}, {0, 0, 0},
              {255, 220, 201}, {205, 255, 255}, {205, 255, 255}, {0, 0, 0},       {0, 0, 0},
                               {180, 255, 233}, {180, 255, 233}, {0, 0, 0},       {255, 220, 201}},

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
    switch (biton32(layer_state)) {
        case FNCT:
            set_layer_color(FNCT);
            break;
        case MOUS:
            set_layer_color(MOUS);
            break;
        case ARRW:
            set_layer_color(ARRW);
            break;
        case KTTY:
            set_layer_color(KTTY);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
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
                alt_case_shift = !alt_case_shift;
            }
            return true;
        case ALTCASE:
            if (record->event.pressed) {
                alt_case_toggle = !alt_case_toggle;
                alt_case_shift  = false;
            }
            return false;
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
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
