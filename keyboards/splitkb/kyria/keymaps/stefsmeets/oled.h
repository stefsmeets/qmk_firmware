oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    if (is_keyboard_master()) {

        oled_write_P(PSTR("Layer: "), false);
        
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("QWERTY\n\n"), false);
                oled_write_P(PSTR("q w e r t  y u i o p\n"), false);
                oled_write_P(PSTR("a s d f g  h j k l ;\n"), false);
                oled_write_P(PSTR("z x c v b  n m , . /\n"), false);
                break;

            case _COLEMAK:
                oled_write_P(PSTR("COLEMAK\n\n"), false);
                oled_write_P(PSTR("q w f p b  j l u y ;\n"), false);
                oled_write_P(PSTR("a r s t g  m n e i o\n"), false);
                oled_write_P(PSTR("z x c d v  k h , . /\n"), false);
                break;

            case _GAME:
                oled_write_P(PSTR("GAME\n\n"), false);
                oled_write_P(PSTR("q w e r t  y u i o p\n"), false);
                oled_write_P(PSTR("a s d f g  h j k l ;\n"), false);
                oled_write_P(PSTR("z x c v b  n m , . /\n"), false);
                break;

            case _NAV:
                oled_write_P(PSTR("Navigation\n\n"), false);
                oled_write_P(PSTR(". b t d up . . . . .\n"), false);
                oled_write_P(PSTR(". < ^ > dn . S C A G\n"), false);
                oled_write_P(PSTR(". h v e .  . . . . .\n"), false);
                break;
            
            case _SYMBOL:
                oled_write_P(PSTR("Symbol\n\n"), false);
                oled_write_P(PSTR("@ _ [ ] ^  ! < > = &\n"), false);
                oled_write_P(PSTR("\\ / { } *  ? ( ) - :\n"), false);
                oled_write_P(PSTR("# $ | ~ `  + % \" ' ;\n"), false);
                break;
            
            case _NUM:
                oled_write_P(PSTR("Number\n\n"), false);
                oled_write_P(PSTR(". . . . .  / 7 8 9 -\n"), false);
                oled_write_P(PSTR("G A C S .  * 4 5 6 ,\n"), false);
                oled_write_P(PSTR(". . . . .  0 1 2 3 =\n"), false);
                break;
            
            case _FUNCTION:
                oled_write_P(PSTR("Function\n\n"), false);
                oled_write_P(PSTR(". . . . .  . 7 8 9 0\n"), false);
                oled_write_P(PSTR("G A C S .  . 4 5 6 1\n"), false);
                oled_write_P(PSTR(". . . . .  . 1 2 3 2\n"), false);
                break;
            
            case _ADJUST:
                oled_write_P(PSTR("Adjust\n\n"), false);
                oled_write_P(PSTR(". . ^ . .  e e e e e\n"), false);
                oled_write_P(PSTR(".<< v >>.  e e e e e\n"), false);
                oled_write_P(PSTR(". . p m .  e e e e e\n"), false);
                break;
            
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("\nNUM ") : PSTR("\n    "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAP ") : PSTR("    "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    }
    return false;
}
