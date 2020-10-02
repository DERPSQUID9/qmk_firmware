#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE,  // default layer
    FNCT,  // function keys
    MDIA,  // media keys
    MOUS,  // mouse keys
    ARRW,  // arrow keys
    KTTY,  // Kitty hotkeys
};

enum custom_keycodes {
    RGB_SLD = EZ_SAFE_RANGE,
    HSV_172_255_255,
    HSV_86_255_128,
    HSV_215_255_128,
    HSV_0_255_255,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Base layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | MO 2   |   1  |   2  |   3  |   4  |   5  |      |           | TG 4 |   6  |   7  |   8  |   9  |   0  | C+A+D  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  | TT 1 |           | TG 3 |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Mac1Play|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   -    |
 * |--------+------+------+------+------+------| TT 5 |           | BkSp |------+------+------+------+------+--------|
 * |Mac2Play|   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |   =    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |RecStp|  `~  |  '"  | Left | Right|                                       |  Up  | Down |   [  |   ]  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |CAP/Hy| LWin |       | RWin |  Meh   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |Esc/LA|       |Del/RA|        |      |
 *                                 | Space|Tab/  |------|       |------| Enter/ |Enter |
 *                                 |      |LCtrl |Shift(|       |Shift)| RCtrl  |      |
 *                                 `--------------------'       `----------------------'
 */
  [BASE] = LAYOUT_ergodox_pretty(
    MO(2),           KC_1,     KC_2,     KC_3,    KC_4,     KC_5, XXXXXXX,                                                         TG(4),     KC_6, KC_7,  KC_8,     KC_9,        KC_0,        RALT(RCTL(KC_DELETE)),
    XXXXXXX,         KC_Q,     KC_W,     KC_E,    KC_R,     KC_T, TT(1),                                                           TG(3),     KC_Y, KC_U,  KC_I,     KC_O,        KC_P,        KC_BSLASH,
    DYN_MACRO_PLAY1, KC_A,     KC_S,     KC_D,    KC_F,     KC_G,                                                                             KC_H, KC_J,  KC_K,     KC_L,        KC_SCOLON,   KC_MINUS,
    DYN_MACRO_PLAY2, KC_Z,     KC_X,     KC_C,    KC_V,     KC_B, TT(5),                                                           KC_BSPACE, KC_N, KC_M,  KC_COMMA, KC_DOT,      KC_SLASH,    KC_EQUAL,
    DYN_REC_STOP,    KC_GRAVE, KC_QUOTE, KC_LEFT, KC_RIGHT,                                                                                         KC_UP, KC_DOWN,  KC_LBRACKET, KC_RBRACKET, XXXXXXX,
                                                                  MT(MOD_HYPR, KC_CAPSLOCK), KC_LGUI,           KC_RGUI,           KC_MEH,
                                                                                             LALT_T(KC_ESCAPE), RALT_T(KC_DELETE),
                                                        KC_SPACE, LCTL_T(KC_TAB),            KC_LSPO,           KC_RSPC,           RCTL_T(KC_ENTER), KC_SPACE
  ),

/* Keymap 1: Function layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Mac1Rec |  F1  |  F2  |  F3  |  F4  |  F5  |      |           | TG 4 |  F6  |  F7  |  F8  |  F9  |  F10 | C+A+D  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |Mac2Rec |  F11 |  F12 |  F13 |  F14 |  F15 | TT 1 |           | TG 3 |  F16 |  F17 |  F18 |  F19 |  F20 |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Mac1Play|  F21 |  F22 |  F23 |  F24 |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------| TT 5 |           | BkSp |------+------+------+------+------+--------|
 * |Mac2Play|      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |RecStp|      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |CAP/Hy| LWin |       | RWin |  Meh   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |Esc/LA|       |Del/RA|        |      |
 *                                 | Space|Tab/  |------|       |------| Enter/ |Enter |
 *                                 |      |LCtrl |Shift(|       |Shift)| RCtrl  |      |
 *                                 `--------------------'       `----------------------'
 */
  [FNCT] = LAYOUT_ergodox_pretty(
    DYN_REC_START1, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,                   KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
    DYN_REC_START2, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_TRNS,                   KC_TRNS, KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  XXXXXXX,
    KC_TRNS,        KC_F21,  KC_F22,  KC_F23,  KC_F24,  XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_TRNS,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,                   KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_TRNS,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                          KC_TRNS, KC_TRNS,
                                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

/* Keymap 2: Media layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | MO 2   |   1  |   2  |   3  |   4  |   5  |      |           | TG 4 |   6  |   7  |   8  |   9  |   0  | Reset  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  | TT 1 |           | TG 3 |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Mac1Play|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   -    |
 * |--------+------+------+------+------+------| TT 5 |           | BkSp |------+------+------+------+------+--------|
 * |Mac2Play|   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |   =    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |RecStp|  `~  |  '"  | Left | Right|                                       |  Up  | Down |   [  |   ]  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |SwitAn|TogCol|       |TogLig|PauseAni|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Blue |       |Purple|        |      |
 *                                 |Bright|Bright|------|       |------|Hue Dec |HueInc|
 *                                 |Dec   |Inc   |Green |       | Red  |        |      |
 *                                 `--------------------'       `----------------------'
 */
  [MDIA] = LAYOUT_ergodox_pretty(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                          RGB_MOD, TOGGLE_LAYER_COLOR, RGB_TOG,         RGB_SLD,
                                                                   HSV_172_255_255,    HSV_215_255_128,
                                                 RGB_VAD, RGB_VAI, HSV_86_255_128,     HSV_0_255_255,   RGB_HUD, RGB_HUI
  ),

/* Keymap 3: Mouse layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | MO 2   |   1  |   2  |   3  |   4  |   5  |      |           | TG 4 |   6  |   7  |   8  |   9  |   0  | C+A+D  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  | TT 1 |           | TG 3 |W Left|W Down| W Up |WRight|   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Mac1Play|   A  |   S  |   D  |   F  |   G  |------|           |------| Left | Down |  Up  |Right |   ;  |   -    |
 * |--------+------+------+------+------+------| TT 5 |           | BkSp |------+------+------+------+------+--------|
 * |Mac2Play|   Z  |   X  |   C  |   V  |   B  |      |           |      |M Left|M Down| M Up |MRight|   /  |   =    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |RecStp|  `~  |  '"  | Left | Right|                                       |  Up  | Down |   [  |   ]  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |CAP/Hy| LWin |       | RWin |Button 5|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |Esc/LA|       |Butt 4|        |      |
 *                                 | Space|Tab/  |------|       |------| RClick |LClick|
 *                                 |      |LCtrl |Shift(|       |MClick|        |      |
 *                                 `--------------------'       `----------------------'
 */
  [MOUS] = LAYOUT_ergodox_pretty(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,     KC_TRNS,        KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                        KC_LEFT,       KC_DOWN,       KC_UP,       KC_RIGHT,       KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_MS_LEFT,    KC_MS_DOWN,    KC_MS_UP,    KC_MS_RIGHT,    KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                                KC_TRNS,       KC_TRNS,     KC_TRNS,        KC_TRNS, KC_TRNS,
                                                          KC_TRNS, KC_TRNS, KC_TRNS,    KC_MS_BTN5,
                                                                   KC_TRNS, KC_MS_BTN4,
                                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_BTN3, KC_MS_BTN2, KC_MS_BTN1
  ),

/* Keymap 4: Arrow layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | MO 2   |   1  |   2  |   3  |   4  |   5  |      |           | TG 4 |   6  |   7  |   8  |   9  |   0  | C+A+D  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  | TT 1 |           | TG 3 |   Y  |   U  |  Up  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Mac1Play|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  | Left | Down |Right |   ;  |   -    |
 * |--------+------+------+------+------+------| TT 5 |           | BkSp |------+------+------+------+------+--------|
 * |Mac2Play|   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |   =    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |RecStp|  `~  |  '"  | Left | Right|                                       |  Up  | Down |   [  |   ]  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |CAP/Hy| LWin |       | RWin |  Meh   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |Esc/LA|       |Del/RA|        |      |
 *                                 | Space|Tab/  |------|       |------| Enter/ |Enter |
 *                                 |      |LCtrl |Shift(|       |Shift)| RCtrl  |      |
 *                                 `--------------------'       `----------------------'
 */
  [ARRW] = LAYOUT_ergodox_pretty(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS,  KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                     KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                       KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                                                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                   KC_TRNS, KC_TRNS,
                                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

/* Keymap 5: Kitty layer
 * An asterisk (*) means CTRL+SHIFT+<key> where <key> is the key's value
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | MO 2   |   1* |   2* |   3* |   4* |   5* | F2*  |           |Alt-T*|   6* |   7* |   8* |   9* |   0* | C+A+D  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q* |   W* |   E* |   R  |   T* | Esc* |           |Enter*|   Y  |   U* |   I  |   O* |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Mac1Play|   A  |   S* |   D  |   F* |   G  |------|           |------|   H  |   J  |   K  |   L* |   ;  |   -    |
 * |--------+------+------+------+------+------| TT 5 |           | BkSp |------+------+------+------+------+--------|
 * |Mac2Play|   Z  |   X  |   C* |   V* |   B* |      |           |      |   N* |   M  |   ,* |   .* |   /  |   =    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |RecStp|  `* |  '"  | Left*|Right*|                                       |  Up*  | Down*|   [* |   ]* |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |CAP/Hy| LWin |       | RWin |  Meh   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |Esc/LA|       |Del/RA|        |      |
 *                                 | Space|Tab/  |------|       |------| Enter/ |Enter |
 *                                 |      |LCtrl |Shift(|       |Shift)| RCtrl  |      |
 *                                 `--------------------'       `----------------------'
 */
  [KTTY] = LAYOUT_ergodox_pretty(
    KC_TRNS, LCTL(LSFT(KC_1)),     LCTL(LSFT(KC_2)), LCTL(LSFT(KC_3)),    LCTL(LSFT(KC_4)),     LCTL(LSFT(KC_5)), LCTL(LSFT(KC_F2)),         RALT(RCTL(RSFT(KC_T))), RCTL(RSFT(KC_6)),  RCTL(RSFT(KC_7)),    RCTL(RSFT(KC_8)),        RCTL(RSFT(KC_9)),        RCTL(RSFT(KC_0)), KC_TRNS,
    KC_TRNS, LCTL(LSFT(KC_Q)),     LCTL(LSFT(KC_W)), LCTL(LSFT(KC_E)),    KC_TRNS,              LCTL(LSFT(KC_T)), LCTL(LSFT(KC_ESCAPE)),     RCTL(RSFT(KC_ENTER)),   KC_TRNS,           RCTL(RSFT(KC_U)),    KC_TRNS,                 RCTL(RSFT(KC_O)),        KC_TRNS,          KC_TRNS,
    KC_TRNS, KC_TRNS,              LCTL(LSFT(KC_S)), KC_TRNS,             LCTL(LSFT(KC_F)),     KC_TRNS,                                                             KC_TRNS,           KC_TRNS,             KC_TRNS,                 RCTL(RSFT(KC_L)),        KC_TRNS,          KC_TRNS,
    KC_TRNS, KC_TRNS,              KC_TRNS,          LCTL(LSFT(KC_C)),    LCTL(LSFT(KC_V)),     LCTL(LSFT(KC_B)), KC_TRNS,                   KC_TRNS,                RCTL(RSFT(KC_N)),  KC_TRNS,             RCTL(RSFT(KC_COMMA)),    RCTL(RSFT(KC_DOT)),      KC_TRNS,          KC_TRNS,
    KC_TRNS, LCTL(LSFT(KC_GRAVE)), KC_TRNS,          LCTL(LSFT(KC_LEFT)), LCTL(LSFT(KC_RIGHT)),                                                                      RCTL(RSFT(KC_UP)), RCTL(RSFT(KC_DOWN)), RCTL(RSFT(KC_LBRACKET)), RCTL(RSFT(KC_RBRACKET)), KC_TRNS,
                                                                                                                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                                                           KC_TRNS, KC_TRNS,
                                                                                                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
};
// clang-format on

extern bool         g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) { rgb_matrix_enable(); }

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [1] = {{205, 255, 255}, {205, 255, 255}, {205, 255, 255}, {205, 255, 255}, {205, 255, 255}, {205, 255, 255}, {205, 255, 255}, {205, 255, 255}, {205, 255, 255}, {205, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {205, 255, 255}, {205, 255, 255}, {205, 255, 255}, {205, 255, 255}, {205, 255, 255}, {205, 255, 255}, {205, 255, 255}, {205, 255, 255}, {205, 255, 255}, {205, 255, 255}, {0, 0, 0}, {205, 255, 255}, {205, 255, 255}, {205, 255, 255}, {205, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},

    [3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {233, 218, 217}, {233, 218, 217}, {233, 218, 217}, {233, 218, 217}, {0, 0, 0}, {205, 255, 255}, {205, 255, 255}, {205, 255, 255}, {205, 255, 255}, {0, 0, 0}, {180, 255, 233}, {180, 255, 233}, {180, 255, 233}, {180, 255, 233}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},

    [4] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 220, 201}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 220, 201}, {255, 220, 201}, {255, 220, 201}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},

    [5] = {{255, 220, 201}, {255, 220, 201}, {255, 220, 201}, {255, 220, 201}, {255, 220, 201}, {0, 0, 0}, {205, 255, 255}, {0, 0, 0}, {205, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {180, 255, 233}, {0, 0, 0}, {255, 220, 201}, {0, 0, 0}, {180, 255, 233}, {180, 255, 233}, {0, 0, 0}, {205, 255, 255}, {205, 255, 255}, {255, 220, 201}, {255, 220, 201}, {255, 220, 201}, {255, 220, 201}, {255, 220, 201}, {255, 220, 201}, {255, 220, 201}, {180, 255, 233}, {0, 0, 0}, {205, 255, 255}, {255, 220, 201}, {180, 255, 233}, {0, 0, 0}, {255, 220, 201}, {0, 0, 0}, {205, 255, 255}, {0, 0, 0}, {255, 220, 201}, {205, 255, 255}, {205, 255, 255}, {0, 0, 0}, {0, 0, 0}, {180, 255, 233}, {180, 255, 233}, {0, 0, 0}, {255, 220, 201}},

};

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
        case 1:
            set_layer_color(1);
            break;
        case 3:
            set_layer_color(3);
            break;
        case 4:
            set_layer_color(4);
            break;
        case 5:
            set_layer_color(5);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
        case HSV_172_255_255:
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(172, 255, 255);
            }
            return false;
        case HSV_86_255_128:
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(86, 255, 128);
            }
            return false;
        case HSV_215_255_128:
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(215, 255, 128);
            }
            return false;
        case HSV_0_255_255:
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(0, 255, 255);
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
