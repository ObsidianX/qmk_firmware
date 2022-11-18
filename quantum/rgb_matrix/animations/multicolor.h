RGB_MATRIX_EFFECT(MULTICOLOR)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

enum MulticolorColor {
    MC_B = 0,
    MC_Y,
    MC_G,
    MC_P,
    MC_R,
    MC_O
};

uint8_t led_id_to_color_map[] =
{
    // RGB LED Index to Flag
//   ESC       F1    F2    F3    F4    F5    F6    F7    F8    F9   F10   F11   F12        PRSC   MIC  LGHT     CIRC   TRI   SQR   CRS
    MC_R,    MC_Y, MC_Y, MC_Y, MC_Y, MC_Y, MC_Y, MC_P, MC_P, MC_P, MC_Y, MC_Y, MC_Y,       MC_R, MC_R, MC_R,    MC_R, MC_R, MC_R, MC_R,

//    `!    1!    2@    3#    4$    5%    6^    7&    8*    9(    0)    -_    =+  BKSP      INS  HOME  PGUP     NMLK   NM/   NM*   NM-
    MC_B, MC_O, MC_O, MC_O, MC_O, MC_O, MC_O, MC_O, MC_O, MC_O, MC_O, MC_B, MC_B, MC_B,    MC_B, MC_B, MC_B,    MC_P, MC_B, MC_B, MC_B,

//   TAB     Q     W     E     R     T     Y     U     I     O     P    [{    ]}    \|      DEL   END  PGDN      NM7   NM8   NM9
    MC_B, MC_G, MC_Y, MC_G, MC_G, MC_G, MC_G, MC_G, MC_G, MC_G, MC_G, MC_G, MC_G, MC_B,    MC_B, MC_B, MC_B,    MC_G, MC_G, MC_G,

//  CPLK        A     S     D     F     G     H     J     K     L    ;:    '"      ENT                           NM4   NM5   NM6   NM+
    MC_P,    MC_Y, MC_Y, MC_Y, MC_G, MC_G, MC_G, MC_G, MC_G, MC_G, MC_G, MC_G,    MC_B,                         MC_G, MC_G, MC_G, MC_B,

//  SHFT           Z     X     C     V     B     N     M    ,<    .>    /?        SHFT            AUP            NM1   NM2   NM3
    MC_B,       MC_G, MC_G, MC_G, MC_G, MC_G, MC_G, MC_G, MC_G, MC_G, MC_G,       MC_B,          MC_Y,          MC_G, MC_G, MC_G,

//  CTRL  META   ALT                    SPC                      ALT  META    FN  CTRL      ALF   ADN   ART      NM0         NM.  NMEN
    MC_B, MC_B, MC_B,                  MC_B,                    MC_B, MC_B, MC_B, MC_B,    MC_Y, MC_Y, MC_Y,    MC_G,       MC_G, MC_B,
};

bool MULTICOLOR(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for(uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();

        switch(led_id_to_color_map[i]) {
            case MC_B: rgb_matrix_set_color(i, RGB_BLUE); break;
            case MC_Y: rgb_matrix_set_color(i, RGB_YELLOW); break;
            case MC_G: rgb_matrix_set_color(i, RGB_GREEN); break;
            case MC_P: rgb_matrix_set_color(i, RGB_PURPLE); break;
            case MC_R: rgb_matrix_set_color(i, RGB_RED); break;
            case MC_O: rgb_matrix_set_color(i, RGB_ORANGE); break;
        }
    }

    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
