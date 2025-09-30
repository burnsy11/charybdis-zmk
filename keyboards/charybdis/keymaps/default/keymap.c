#include QMK_KEYBOARD_H

// Layer definitions (matching ZMK config)
enum layers {
    _BASE = 0,
    _NUFU,     // Numeral/Function
    _SYM,      // Symbol 
    _NAV,      // Navigation
    _MED,      // Media
    _POI,      // Pointer
    _SCR,      // Scroll
    _SNI       // Sniper
};

// Home row mod tap keys
#define HML_A    LGUI_T(KC_A)
#define HML_S    LALT_T(KC_S) 
#define HML_D    LCTL_T(KC_D)
#define HML_F    LSFT_T(KC_F)

#define HMR_J    RSFT_T(KC_J)
#define HMR_K    RCTL_T(KC_K)
#define HMR_L    RALT_T(KC_L)
#define HMR_SCLN RGUI_T(KC_SCLN)

// Layer tap keys
#define LT_ESC   LT(_MED, KC_ESC)
#define LT_SPC   LT(_NAV, KC_SPC)
#define LT_TAB   LT(_NUFU, KC_TAB)
#define LT_BSPC  LT(_SYM, KC_BSPC)
#define LT_Z     LT(_POI, KC_Z)
#define LT_SLSH  LT(_POI, KC_SLSH)

// Custom keycodes for advanced features
enum custom_keycodes {
    // Mouse click keycodes
    MS_LCLK = SAFE_RANGE,
    MS_RCLK,
    MS_MCLK,
    // Scroll/sniper toggle
    TOG_SCR,
    TOG_SNI,
    // Momentary scroll/sniper
    MO_SCR,
    MO_SNI
};

// Combo definitions (matching ZMK config positions)
const uint16_t PROGMEM combo_l_lclk[] = {HML_D, HML_F, COMBO_END};
const uint16_t PROGMEM combo_l_rclk[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo_l_mclk[] = {KC_V, KC_B, COMBO_END};

const uint16_t PROGMEM combo_r_lclk[] = {HMR_J, HMR_K, COMBO_END};
const uint16_t PROGMEM combo_r_rclk[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_r_mclk[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_l_lclk, MS_LCLK),
    COMBO(combo_l_rclk, MS_RCLK), 
    COMBO(combo_l_mclk, MS_MCLK),
    COMBO(combo_r_lclk, MS_LCLK),
    COMBO(combo_r_rclk, MS_RCLK),
    COMBO(combo_r_mclk, MS_MCLK)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Base Layer
     * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
     * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │
     * └───┴───┴───┼───┼───┼───┐ ┌───┼───┼───┼───┴───┴───┘
     *             │ESC│SPC│TAB│ │ENT│BSP│   │
     *             └───┴───┴───┘ └───┴───┘   └
     */
    [_BASE] = LAYOUT_5x3(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
        HML_A,   HML_S,   HML_D,   HML_F,   KC_G,         KC_H,     HMR_J,    HMR_K,    HMR_L,    HMR_SCLN,
        LT_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,     KC_M,     KC_COMM,  KC_DOT,   LT_SLSH,
                                   LT_ESC,  LT_SPC, LT_TAB,   KC_ENT,   LT_BSPC
    ),

    /*
     * Numeral/Function Layer
     * ┌────┬───┬───┬───┬─────┐       ┌─────┬───┬───┬───┬───┐
     * │F12 │F7 │F8 │F9 │PSCR │       │     │ 7 │ 8 │ 9 │DEL│
     * ├────┼───┼───┼───┼─────┤       ├─────┼───┼───┼───┼───┤
     * │F11 │F4 │F5 │F6 │SLCK │       │     │ 4 │ 5 │ 6 │BSP│
     * ├────┼───┼───┼───┼─────┤       ├─────┼───┼───┼───┼───┤
     * │F10 │F1 │F2 │F3 │PAUS │       │     │ 1 │ 2 │ 3 │   │
     * └────┴───┴───┼───┼─────┼───┐ ┌─────┼───┼───┼───┴───┴───┘
     *               │   │     │███│ │  .  │ 0 │   │
     *               └───┴─────┴───┘ └─────┴───┘   └
     */
    [_NUFU] = LAYOUT_5x3(
        KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,      KC_TRNS,  KC_7,     KC_8,     KC_9,     KC_DEL,
        KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL,      KC_TRNS,  KC_4,     KC_5,     KC_6,     KC_BSPC,
        KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS,      KC_TRNS,  KC_1,     KC_2,     KC_3,     KC_TRNS,
                                   KC_TRNS, KC_TRNS, KC_TRNS,  KC_DOT,   KC_0
    ),

    /*
     * Symbol Layer  
     * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
     * │ ~ │ & │ * │   │ + │       │   │ { │ } │   │ | │
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │ - │ $ │ % │ ^ │ = │       │   │ ( │ ) │ " │ ' │
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │ _ │ ! │ @ │ # │ ` │       │   │ [ │ ] │   │ \ │
     * └───┴───┴───┼───┼───┼───┐ ┌───┼───┼───┼───┴───┴───┘
     *             │   │   │   │ │   │███│   │
     *             └───┴───┴───┘ └───┴───┘   └
     */
    [_SYM] = LAYOUT_5x3(
        KC_TILD, KC_AMPR, KC_ASTR, KC_TRNS, KC_PLUS,      KC_TRNS,  KC_LCBR,  KC_RCBR,  KC_TRNS,  KC_PIPE,
        KC_MINS, KC_DLR,  KC_PERC, KC_CIRC, KC_EQL,       KC_TRNS,  KC_LPRN,  KC_RPRN,  KC_DQUO,  KC_QUOT,
        KC_UNDS, KC_EXLM, KC_AT,   KC_HASH, KC_GRV,       KC_TRNS,  KC_LBRC,  KC_RBRC,  KC_TRNS,  KC_BSLS,
                                   KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS
    ),

    /*
     * Navigation Layer
     * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
     * │     │     │     │     │     │       │REDO │PASTE│COPY │ CUT │UNDO │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │     │     │     │     │     │       │ ←   │ ↓   │ ↑   │ →   │CAPS │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │     │     │     │     │     │       │HOME │PGDN │PGUP │ END │ INS │
     * └─────┴─────┴─────┼─────┼─────┼───┐ ┌─────┼─────┼─────┼─────┴─────┴─────┘
     *                   │     │ ███ │   │ │     │ DEL │     │
     *                   └─────┴─────┴───┘ └─────┴─────┘     └
     */
    [_NAV] = LAYOUT_5x3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_AGIN,  KC_PSTE,  KC_COPY,  KC_CUT,   KC_UNDO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_CAPS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_INS,
                                   KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_DEL
    ),

    /*
     * Media Layer
     * ┌─────┬──────┬──────┬──────┬─────┐       ┌─────┬──────┬──────┬──────┬─────┐
     * │     │      │ BTCL │      │     │       │     │      │ BTCL │      │     │
     * ├─────┼──────┼──────┼──────┼─────┤       ├─────┼──────┼──────┼──────┼─────┤
     * │PREV │ VOLD │ MUTE │ VOLU │NEXT │       │PREV │ VOLD │ MUTE │ VOLU │NEXT │
     * ├─────┼──────┼──────┼──────┼─────┤       ├─────┼──────┼──────┼──────┼─────┤
     * │     │      │      │      │     │       │     │      │      │      │     │
     * └─────┴──────┴──────┼──────┼─────┼───┐ ┌─────┼──────┼──────┼──────┴─────┴─────┘
     *                     │  ███ │PLAY │STP│ │ STP │ PLAY │      │
     *                     └──────┴─────┴───┘ └─────┴──────┘      └
     */
    [_MED] = LAYOUT_5x3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_MPRV, KC_VOLD, KC_MUTE, KC_VOLU, KC_MNXT,      KC_MPRV,  KC_VOLD,  KC_MUTE,  KC_VOLU,  KC_MNXT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                   KC_TRNS, KC_MPLY, KC_MSTP,  KC_MSTP,  KC_MPLY
    ),

    /*
     * Pointer Layer
     * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
     * │     │     │     │     │     │       │     │     │     │     │     │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │LGUI │LALT │LCTL │LSFT │     │       │     │RSFT │RCTL │RALT │RGUI │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │ ███ │ SCR │ SNI │     │     │       │     │     │TSNI │TSCR │ ███ │
     * └─────┴─────┴─────┼─────┼─────┼───┐ ┌─────┼─────┼─────┼─────┴─────┴─────┘
     *                   │RCLK │LCLK │MCL│ │ MCL │LCLK │     │
     *                   └─────┴─────┴───┘ └─────┴─────┘     └
     */
    [_POI] = LAYOUT_5x3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_TRNS,      KC_TRNS,  KC_RSFT,  KC_RCTL,  KC_RALT,  KC_RGUI,
        KC_TRNS, MO_SCR,  MO_SNI,  KC_TRNS, KC_TRNS,      KC_TRNS,  KC_TRNS,  TOG_SNI,  TOG_SCR,  KC_TRNS,
                                   MS_RCLK, MS_LCLK, MS_MCLK,  MS_MCLK,  MS_LCLK
    ),

    /*
     * Scroll Layer - Empty for trackball scroll mode
     */
    [_SCR] = LAYOUT_5x3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                   KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS
    ),

    /*
     * Sniper Layer - Empty for trackball sniper mode
     */
    [_SNI] = LAYOUT_5x3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                   KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS
    )
};

// Home row mod configuration with identical timing to ZMK
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HML_A:
        case HML_S:
        case HML_D:
        case HML_F:
        case HMR_J:
        case HMR_K:
        case HMR_L:
        case HMR_SCLN:
            return 200; // Match ZMK tapping-term-ms = 200
        default:
            return TAPPING_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HML_A:
        case HML_S:
        case HML_D:
        case HML_F:
        case HMR_J:
        case HMR_K:
        case HMR_L:
        case HMR_SCLN:
            return false; // Disable permissive hold for home row mods
        default:
            return true;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HML_A:
        case HML_S:
        case HML_D:
        case HML_F:
        case HMR_J:
        case HMR_K:
        case HMR_L:
        case HMR_SCLN:
            return true; // Match ZMK hold-trigger-on-release
        default:
            return false;
    }
}

// Custom keycode handling
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MS_LCLK:
            if (record->event.pressed) {
                tap_code(KC_MS_BTN1);
            }
            return false;
        case MS_RCLK:
            if (record->event.pressed) {
                tap_code(KC_MS_BTN2);
            }
            return false;
        case MS_MCLK:
            if (record->event.pressed) {
                tap_code(KC_MS_BTN3);
            }
            return false;
        case TOG_SCR:
            if (record->event.pressed) {
                // Toggle scroll mode layer
                layer_invert(_SCR);
            }
            return false;
        case TOG_SNI:
            if (record->event.pressed) {
                // Toggle sniper mode layer
                layer_invert(_SNI);
            }
            return false;
        case MO_SCR:
            if (record->event.pressed) {
                layer_on(_SCR);
            } else {
                layer_off(_SCR);
            }
            return false;
        case MO_SNI:
            if (record->event.pressed) {
                layer_on(_SNI);
            } else {
                layer_off(_SNI);
            }
            return false;
    }
    return true;
}

// Trackball scroll and sniper mode handling
layer_state_t layer_state_set_user(layer_state_t state) {
    // Implement trackball behavior based on active layers
    static bool scroll_mode = false;
    static bool sniper_mode = false;
    
    bool new_scroll = layer_state_cmp(state, _SCR);
    bool new_sniper = layer_state_cmp(state, _SNI);
    
    if (new_scroll != scroll_mode) {
        scroll_mode = new_scroll;
        // Configure trackball for scroll mode
        // This would interface with PMW3610 driver
    }
    
    if (new_sniper != sniper_mode) {
        sniper_mode = new_sniper;
        // Configure trackball for sniper mode (lower CPI)
        // This would interface with PMW3610 driver
    }
    
    return state;
}