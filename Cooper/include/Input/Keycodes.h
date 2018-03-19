
#pragma once

namespace Cooper { namespace Input {

enum {
    //--------------------------------------------------------------------------
    //
    Mouse_Input_Shift    = 100,
    Keyboard_Input_Shift = 200,

    //--------------------------------------------------------------------------
    //
    M_LEFT   = (SDL_BUTTON_LEFT   + Mouse_Input_Shift),
    M_MIDDLE = (SDL_BUTTON_MIDDLE + Mouse_Input_Shift),
    M_RIGHT  = (SDL_BUTTON_RIGHT  + Mouse_Input_Shift),
    M_X1     = (SDL_BUTTON_X1     + Mouse_Input_Shift),
    M_X2     = (SDL_BUTTON_X2     + Mouse_Input_Shift),

    //--------------------------------------------------------------------------
    //


    K_A = (SDL_SCANCODE_A + Keyboard_Input_Shift),
    K_B = (SDL_SCANCODE_B + Keyboard_Input_Shift),
    K_C = (SDL_SCANCODE_C + Keyboard_Input_Shift),
    K_D = (SDL_SCANCODE_D + Keyboard_Input_Shift),
    K_E = (SDL_SCANCODE_E + Keyboard_Input_Shift),
    K_F = (SDL_SCANCODE_F + Keyboard_Input_Shift),
    K_G = (SDL_SCANCODE_G + Keyboard_Input_Shift),
    K_H = (SDL_SCANCODE_H + Keyboard_Input_Shift),
    K_I = (SDL_SCANCODE_I + Keyboard_Input_Shift),
    K_J = (SDL_SCANCODE_J + Keyboard_Input_Shift),
    K_K = (SDL_SCANCODE_K + Keyboard_Input_Shift),
    K_L = (SDL_SCANCODE_L + Keyboard_Input_Shift),
    K_M = (SDL_SCANCODE_M + Keyboard_Input_Shift),
    K_N = (SDL_SCANCODE_N + Keyboard_Input_Shift),
    K_O = (SDL_SCANCODE_O + Keyboard_Input_Shift),
    K_P = (SDL_SCANCODE_P + Keyboard_Input_Shift),
    K_Q = (SDL_SCANCODE_Q + Keyboard_Input_Shift),
    K_R = (SDL_SCANCODE_R + Keyboard_Input_Shift),
    K_S = (SDL_SCANCODE_S + Keyboard_Input_Shift),
    K_T = (SDL_SCANCODE_T + Keyboard_Input_Shift),
    K_U = (SDL_SCANCODE_U + Keyboard_Input_Shift),
    K_V = (SDL_SCANCODE_V + Keyboard_Input_Shift),
    K_W = (SDL_SCANCODE_W + Keyboard_Input_Shift),
    K_X = (SDL_SCANCODE_X + Keyboard_Input_Shift),
    K_Y = (SDL_SCANCODE_Y + Keyboard_Input_Shift),
    K_Z = (SDL_SCANCODE_Z + Keyboard_Input_Shift),

    //--------------------------------------------------------------------------
    //
    K_1 = (SDL_SCANCODE_1 + Keyboard_Input_Shift),
    K_2 = (SDL_SCANCODE_2 + Keyboard_Input_Shift),
    K_3 = (SDL_SCANCODE_3 + Keyboard_Input_Shift),
    K_4 = (SDL_SCANCODE_4 + Keyboard_Input_Shift),
    K_5 = (SDL_SCANCODE_5 + Keyboard_Input_Shift),
    K_6 = (SDL_SCANCODE_6 + Keyboard_Input_Shift),
    K_7 = (SDL_SCANCODE_7 + Keyboard_Input_Shift),
    K_8 = (SDL_SCANCODE_8 + Keyboard_Input_Shift),
    K_9 = (SDL_SCANCODE_9 + Keyboard_Input_Shift),
    K_0 = (SDL_SCANCODE_0 + Keyboard_Input_Shift),

    //--------------------------------------------------------------------------
    //
    K_RETURN       = (SDL_SCANCODE_RETURN       + Keyboard_Input_Shift),
    K_ESCAPE       = (SDL_SCANCODE_ESCAPE       + Keyboard_Input_Shift),
    K_BACKSPACE    = (SDL_SCANCODE_BACKSPACE    + Keyboard_Input_Shift),
    K_TAB          = (SDL_SCANCODE_TAB          + Keyboard_Input_Shift),
    K_SPACE        = (SDL_SCANCODE_SPACE        + Keyboard_Input_Shift),
    K_MINUS        = (SDL_SCANCODE_MINUS        + Keyboard_Input_Shift),
    K_EQUALS       = (SDL_SCANCODE_EQUALS       + Keyboard_Input_Shift),
    K_LEFTBRACKET  = (SDL_SCANCODE_LEFTBRACKET  + Keyboard_Input_Shift),
    K_RIGHTBRACKET = (SDL_SCANCODE_RIGHTBRACKET + Keyboard_Input_Shift),
    K_BACKSLASH    = (SDL_SCANCODE_BACKSLASH    + Keyboard_Input_Shift),
    K_NONUSHASH    = (SDL_SCANCODE_NONUSHASH    + Keyboard_Input_Shift),
    K_SEMICOLON    = (SDL_SCANCODE_SEMICOLON    + Keyboard_Input_Shift),
    K_APOSTROPHE   = (SDL_SCANCODE_APOSTROPHE   + Keyboard_Input_Shift),
    K_GRAVE        = (SDL_SCANCODE_GRAVE        + Keyboard_Input_Shift),
    K_COMMA        = (SDL_SCANCODE_COMMA        + Keyboard_Input_Shift),
    K_PERIOD       = (SDL_SCANCODE_PERIOD       + Keyboard_Input_Shift),
    K_SLASH        = (SDL_SCANCODE_SLASH        + Keyboard_Input_Shift),

    //--------------------------------------------------------------------------
    //
    K_CAPSLOCK = (SDL_SCANCODE_CAPSLOCK + Keyboard_Input_Shift),

    //--------------------------------------------------------------------------
    //
    K_F1  = (SDL_SCANCODE_F1  + Keyboard_Input_Shift),
    K_F2  = (SDL_SCANCODE_F2  + Keyboard_Input_Shift),
    K_F3  = (SDL_SCANCODE_F3  + Keyboard_Input_Shift),
    K_F4  = (SDL_SCANCODE_F4  + Keyboard_Input_Shift),
    K_F5  = (SDL_SCANCODE_F5  + Keyboard_Input_Shift),
    K_F6  = (SDL_SCANCODE_F6  + Keyboard_Input_Shift),
    K_F7  = (SDL_SCANCODE_F7  + Keyboard_Input_Shift),
    K_F8  = (SDL_SCANCODE_F8  + Keyboard_Input_Shift),
    K_F9  = (SDL_SCANCODE_F9  + Keyboard_Input_Shift),
    K_F10 = (SDL_SCANCODE_F10 + Keyboard_Input_Shift),
    K_F11 = (SDL_SCANCODE_F11 + Keyboard_Input_Shift),
    K_F12 = (SDL_SCANCODE_F12 + Keyboard_Input_Shift),

    //--------------------------------------------------------------------------
    //
    K_PRINTSCREEN = (SDL_SCANCODE_PRINTSCREEN + Keyboard_Input_Shift),
    K_SCROLLLOCK  = (SDL_SCANCODE_SCROLLLOCK  + Keyboard_Input_Shift),
    K_PAUSE       = (SDL_SCANCODE_PAUSE       + Keyboard_Input_Shift),
    K_INSERT      = (SDL_SCANCODE_INSERT      + Keyboard_Input_Shift),

    //--------------------------------------------------------------------------
    //
    K_HOME     = (SDL_SCANCODE_HOME     + Keyboard_Input_Shift),
    K_PAGEUP   = (SDL_SCANCODE_PAGEUP   + Keyboard_Input_Shift),
    K_DELETE   = (SDL_SCANCODE_DELETE   + Keyboard_Input_Shift),
    K_END      = (SDL_SCANCODE_END      + Keyboard_Input_Shift),
    K_PAGEDOWN = (SDL_SCANCODE_PAGEDOWN + Keyboard_Input_Shift),
    K_RIGHT    = (SDL_SCANCODE_RIGHT    + Keyboard_Input_Shift),
    K_LEFT     = (SDL_SCANCODE_LEFT     + Keyboard_Input_Shift),
    K_DOWN     = (SDL_SCANCODE_DOWN     + Keyboard_Input_Shift),
    K_UP       = (SDL_SCANCODE_UP       + Keyboard_Input_Shift),

    //--------------------------------------------------------------------------
    //
    K_NUMLOCKCLEAR = (SDL_SCANCODE_NUMLOCKCLEAR + Keyboard_Input_Shift),

    //--------------------------------------------------------------------------
    //
    K_KP_DIVIDE   = (SDL_SCANCODE_KP_DIVIDE  + Keyboard_Input_Shift),
    K_KP_MULTIPLY = (SDL_SCANCODE_KP_MULTIPLY+ Keyboard_Input_Shift),
    K_KP_MINUS    = (SDL_SCANCODE_KP_MINUS   + Keyboard_Input_Shift),
    K_KP_PLUS     = (SDL_SCANCODE_KP_PLUS    + Keyboard_Input_Shift),
    K_KP_ENTER    = (SDL_SCANCODE_KP_ENTER   + Keyboard_Input_Shift),
    K_KP_1        = (SDL_SCANCODE_KP_1       + Keyboard_Input_Shift),
    K_KP_2        = (SDL_SCANCODE_KP_2       + Keyboard_Input_Shift),
    K_KP_3        = (SDL_SCANCODE_KP_3       + Keyboard_Input_Shift),
    K_KP_4        = (SDL_SCANCODE_KP_4       + Keyboard_Input_Shift),
    K_KP_5        = (SDL_SCANCODE_KP_5       + Keyboard_Input_Shift),
    K_KP_6        = (SDL_SCANCODE_KP_6       + Keyboard_Input_Shift),
    K_KP_7        = (SDL_SCANCODE_KP_7       + Keyboard_Input_Shift),
    K_KP_8        = (SDL_SCANCODE_KP_8       + Keyboard_Input_Shift),
    K_KP_9        = (SDL_SCANCODE_KP_9       + Keyboard_Input_Shift),
    K_KP_0        = (SDL_SCANCODE_KP_0       + Keyboard_Input_Shift),
    K_KP_PERIOD   = (SDL_SCANCODE_KP_PERIOD  + Keyboard_Input_Shift),

    //--------------------------------------------------------------------------
    //
    K_NONUSBACKSLASH = (SDL_SCANCODE_NONUSBACKSLASH + Keyboard_Input_Shift),

    //--------------------------------------------------------------------------
    //
    K_APPLICATION    = (SDL_SCANCODE_APPLICATION    + Keyboard_Input_Shift),
    K_POWER          = (SDL_SCANCODE_POWER          + Keyboard_Input_Shift),
    K_KP_EQUALS      = (SDL_SCANCODE_KP_EQUALS      + Keyboard_Input_Shift),
    K_F13            = (SDL_SCANCODE_F13            + Keyboard_Input_Shift),
    K_F14            = (SDL_SCANCODE_F14            + Keyboard_Input_Shift),
    K_F15            = (SDL_SCANCODE_F15            + Keyboard_Input_Shift),
    K_F16            = (SDL_SCANCODE_F16            + Keyboard_Input_Shift),
    K_F17            = (SDL_SCANCODE_F17            + Keyboard_Input_Shift),
    K_F18            = (SDL_SCANCODE_F18            + Keyboard_Input_Shift),
    K_F19            = (SDL_SCANCODE_F19            + Keyboard_Input_Shift),
    K_F20            = (SDL_SCANCODE_F20            + Keyboard_Input_Shift),
    K_F21            = (SDL_SCANCODE_F21            + Keyboard_Input_Shift),
    K_F22            = (SDL_SCANCODE_F22            + Keyboard_Input_Shift),
    K_F23            = (SDL_SCANCODE_F23            + Keyboard_Input_Shift),
    K_F24            = (SDL_SCANCODE_F24            + Keyboard_Input_Shift),
    K_EXECUTE        = (SDL_SCANCODE_EXECUTE        + Keyboard_Input_Shift),
    K_HELP           = (SDL_SCANCODE_HELP           + Keyboard_Input_Shift),
    K_MENU           = (SDL_SCANCODE_MENU           + Keyboard_Input_Shift),
    K_SELECT         = (SDL_SCANCODE_SELECT         + Keyboard_Input_Shift),
    K_STOP           = (SDL_SCANCODE_STOP           + Keyboard_Input_Shift),
    K_AGAIN          = (SDL_SCANCODE_AGAIN          + Keyboard_Input_Shift),
    K_UNDO           = (SDL_SCANCODE_UNDO           + Keyboard_Input_Shift),
    K_CUT            = (SDL_SCANCODE_CUT            + Keyboard_Input_Shift),
    K_COPY           = (SDL_SCANCODE_COPY           + Keyboard_Input_Shift),
    K_PASTE          = (SDL_SCANCODE_PASTE          + Keyboard_Input_Shift),
    K_FIND           = (SDL_SCANCODE_FIND           + Keyboard_Input_Shift),
    K_MUTE           = (SDL_SCANCODE_MUTE           + Keyboard_Input_Shift),
    K_VOLUMEUP       = (SDL_SCANCODE_VOLUMEUP       + Keyboard_Input_Shift),
    K_VOLUMEDOWN     = (SDL_SCANCODE_VOLUMEDOWN     + Keyboard_Input_Shift),
    K_KP_COMMA       = (SDL_SCANCODE_KP_COMMA       + Keyboard_Input_Shift),
    K_KP_EQUALSAS400 = (SDL_SCANCODE_KP_EQUALSAS400 + Keyboard_Input_Shift),

    //--------------------------------------------------------------------------
    //
    K_INTERNATIONAL1 = (SDL_SCANCODE_INTERNATIONAL1 + Keyboard_Input_Shift),
    K_INTERNATIONAL2 = (SDL_SCANCODE_INTERNATIONAL2 + Keyboard_Input_Shift),
    K_INTERNATIONAL3 = (SDL_SCANCODE_INTERNATIONAL3 + Keyboard_Input_Shift),
    K_INTERNATIONAL4 = (SDL_SCANCODE_INTERNATIONAL4 + Keyboard_Input_Shift),
    K_INTERNATIONAL5 = (SDL_SCANCODE_INTERNATIONAL5 + Keyboard_Input_Shift),
    K_INTERNATIONAL6 = (SDL_SCANCODE_INTERNATIONAL6 + Keyboard_Input_Shift),
    K_INTERNATIONAL7 = (SDL_SCANCODE_INTERNATIONAL7 + Keyboard_Input_Shift),
    K_INTERNATIONAL8 = (SDL_SCANCODE_INTERNATIONAL8 + Keyboard_Input_Shift),
    K_INTERNATIONAL9 = (SDL_SCANCODE_INTERNATIONAL9 + Keyboard_Input_Shift),
    K_LANG1          = (SDL_SCANCODE_LANG1          + Keyboard_Input_Shift),
    K_LANG2          = (SDL_SCANCODE_LANG2          + Keyboard_Input_Shift),
    K_LANG3          = (SDL_SCANCODE_LANG3          + Keyboard_Input_Shift),
    K_LANG4          = (SDL_SCANCODE_LANG4          + Keyboard_Input_Shift),
    K_LANG5          = (SDL_SCANCODE_LANG5          + Keyboard_Input_Shift),
    K_LANG6          = (SDL_SCANCODE_LANG6          + Keyboard_Input_Shift),
    K_LANG7          = (SDL_SCANCODE_LANG7          + Keyboard_Input_Shift),
    K_LANG8          = (SDL_SCANCODE_LANG8          + Keyboard_Input_Shift),
    K_LANG9          = (SDL_SCANCODE_LANG9          + Keyboard_Input_Shift),

    //--------------------------------------------------------------------------
    //
    K_ALTERASE   = (SDL_SCANCODE_ALTERASE   + Keyboard_Input_Shift),
    K_SYSREQ     = (SDL_SCANCODE_SYSREQ     + Keyboard_Input_Shift),
    K_CANCEL     = (SDL_SCANCODE_CANCEL     + Keyboard_Input_Shift),
    K_CLEAR      = (SDL_SCANCODE_CLEAR      + Keyboard_Input_Shift),
    K_PRIOR      = (SDL_SCANCODE_PRIOR      + Keyboard_Input_Shift),
    K_RETURN2    = (SDL_SCANCODE_RETURN2    + Keyboard_Input_Shift),
    K_SEPARATOR  = (SDL_SCANCODE_SEPARATOR  + Keyboard_Input_Shift),
    K_OUT        = (SDL_SCANCODE_OUT        + Keyboard_Input_Shift),
    K_OPER       = (SDL_SCANCODE_OPER       + Keyboard_Input_Shift),
    K_CLEARAGAIN = (SDL_SCANCODE_CLEARAGAIN + Keyboard_Input_Shift),
    K_CRSEL      = (SDL_SCANCODE_CRSEL      + Keyboard_Input_Shift),
    K_EXSEL      = (SDL_SCANCODE_EXSEL      + Keyboard_Input_Shift),

    //--------------------------------------------------------------------------
    //
    K_KP_00              = (SDL_SCANCODE_KP_00              + Keyboard_Input_Shift),
    K_KP_000             = (SDL_SCANCODE_KP_000             + Keyboard_Input_Shift),
    K_THOUSANDSSEPARATOR = (SDL_SCANCODE_THOUSANDSSEPARATOR + Keyboard_Input_Shift),
    K_DECIMALSEPARATOR   = (SDL_SCANCODE_DECIMALSEPARATOR   + Keyboard_Input_Shift),
    K_CURRENCYUNIT       = (SDL_SCANCODE_CURRENCYUNIT       + Keyboard_Input_Shift),
    K_CURRENCYSUBUNIT    = (SDL_SCANCODE_CURRENCYSUBUNIT    + Keyboard_Input_Shift),
    K_KP_LEFTPAREN       = (SDL_SCANCODE_KP_LEFTPAREN       + Keyboard_Input_Shift),
    K_KP_RIGHTPAREN      = (SDL_SCANCODE_KP_RIGHTPAREN      + Keyboard_Input_Shift),
    K_KP_LEFTBRACE       = (SDL_SCANCODE_KP_LEFTBRACE       + Keyboard_Input_Shift),
    K_KP_RIGHTBRACE      = (SDL_SCANCODE_KP_RIGHTBRACE      + Keyboard_Input_Shift),
    K_KP_TAB             = (SDL_SCANCODE_KP_TAB             + Keyboard_Input_Shift),
    K_KP_BACKSPACE       = (SDL_SCANCODE_KP_BACKSPACE       + Keyboard_Input_Shift),
    K_KP_A               = (SDL_SCANCODE_KP_A               + Keyboard_Input_Shift),
    K_KP_B               = (SDL_SCANCODE_KP_B               + Keyboard_Input_Shift),
    K_KP_C               = (SDL_SCANCODE_KP_C               + Keyboard_Input_Shift),
    K_KP_D               = (SDL_SCANCODE_KP_D               + Keyboard_Input_Shift),
    K_KP_E               = (SDL_SCANCODE_KP_E               + Keyboard_Input_Shift),
    K_KP_F               = (SDL_SCANCODE_KP_F               + Keyboard_Input_Shift),
    K_KP_XOR             = (SDL_SCANCODE_KP_XOR             + Keyboard_Input_Shift),
    K_KP_POWER           = (SDL_SCANCODE_KP_POWER           + Keyboard_Input_Shift),
    K_KP_PERCENT         = (SDL_SCANCODE_KP_PERCENT         + Keyboard_Input_Shift),
    K_KP_LESS            = (SDL_SCANCODE_KP_LESS            + Keyboard_Input_Shift),
    K_KP_GREATER         = (SDL_SCANCODE_KP_GREATER         + Keyboard_Input_Shift),
    K_KP_AMPERSAND       = (SDL_SCANCODE_KP_AMPERSAND       + Keyboard_Input_Shift),
    K_KP_DBLAMPERSAND    = (SDL_SCANCODE_KP_DBLAMPERSAND    + Keyboard_Input_Shift),
    K_KP_VERTICALBAR     = (SDL_SCANCODE_KP_VERTICALBAR     + Keyboard_Input_Shift),
    K_KP_DBLVERTICALBAR  = (SDL_SCANCODE_KP_DBLVERTICALBAR  + Keyboard_Input_Shift),
    K_KP_COLON           = (SDL_SCANCODE_KP_COLON           + Keyboard_Input_Shift),
    K_KP_HASH            = (SDL_SCANCODE_KP_HASH            + Keyboard_Input_Shift),
    K_KP_SPACE           = (SDL_SCANCODE_KP_SPACE           + Keyboard_Input_Shift),
    K_KP_AT              = (SDL_SCANCODE_KP_AT              + Keyboard_Input_Shift),
    K_KP_EXCLAM          = (SDL_SCANCODE_KP_EXCLAM          + Keyboard_Input_Shift),
    K_KP_MEMSTORE        = (SDL_SCANCODE_KP_MEMSTORE        + Keyboard_Input_Shift),
    K_KP_MEMRECALL       = (SDL_SCANCODE_KP_MEMRECALL       + Keyboard_Input_Shift),
    K_KP_MEMCLEAR        = (SDL_SCANCODE_KP_MEMCLEAR        + Keyboard_Input_Shift),
    K_KP_MEMADD          = (SDL_SCANCODE_KP_MEMADD          + Keyboard_Input_Shift),
    K_KP_MEMSUBTRACT     = (SDL_SCANCODE_KP_MEMSUBTRACT     + Keyboard_Input_Shift),
    K_KP_MEMMULTIPLY     = (SDL_SCANCODE_KP_MEMMULTIPLY     + Keyboard_Input_Shift),
    K_KP_MEMDIVIDE       = (SDL_SCANCODE_KP_MEMDIVIDE       + Keyboard_Input_Shift),
    K_KP_PLUSMINUS       = (SDL_SCANCODE_KP_PLUSMINUS       + Keyboard_Input_Shift),
    K_KP_CLEAR           = (SDL_SCANCODE_KP_CLEAR           + Keyboard_Input_Shift),
    K_KP_CLEARENTRY      = (SDL_SCANCODE_KP_CLEARENTRY      + Keyboard_Input_Shift),
    K_KP_BINARY          = (SDL_SCANCODE_KP_BINARY          + Keyboard_Input_Shift),
    K_KP_OCTAL           = (SDL_SCANCODE_KP_OCTAL           + Keyboard_Input_Shift),
    K_KP_DECIMAL         = (SDL_SCANCODE_KP_DECIMAL         + Keyboard_Input_Shift),
    K_KP_HEXADECIMAL     = (SDL_SCANCODE_KP_HEXADECIMAL     + Keyboard_Input_Shift),

    //--------------------------------------------------------------------------
    //
    K_LCTRL  = (SDL_SCANCODE_LCTRL  + Keyboard_Input_Shift),
    K_LSHIFT = (SDL_SCANCODE_LSHIFT + Keyboard_Input_Shift),
    K_LALT   = (SDL_SCANCODE_LALT   + Keyboard_Input_Shift),
    K_LGUI   = (SDL_SCANCODE_LGUI   + Keyboard_Input_Shift),
    K_RCTRL  = (SDL_SCANCODE_RCTRL  + Keyboard_Input_Shift),
    K_RSHIFT = (SDL_SCANCODE_RSHIFT + Keyboard_Input_Shift),
    K_RALT   = (SDL_SCANCODE_RALT   + Keyboard_Input_Shift),
    K_RGUI   = (SDL_SCANCODE_RGUI   + Keyboard_Input_Shift),
    K_MODE   = (SDL_SCANCODE_MODE   + Keyboard_Input_Shift),

    //--------------------------------------------------------------------------
    //
    K_AUDIONEXT   = (SDL_SCANCODE_AUDIONEXT    + Keyboard_Input_Shift),
    K_AUDIOPREV   = (SDL_SCANCODE_AUDIOPREV    + Keyboard_Input_Shift),
    K_AUDIOSTOP   = (SDL_SCANCODE_AUDIOSTOP    + Keyboard_Input_Shift),
    K_AUDIOPLAY   = (SDL_SCANCODE_AUDIOPLAY    + Keyboard_Input_Shift),
    K_AUDIOMUTE   = (SDL_SCANCODE_AUDIOMUTE    + Keyboard_Input_Shift),
    K_MEDIASELECT = (SDL_SCANCODE_MEDIASELECT  + Keyboard_Input_Shift),
    K_WWW         = (SDL_SCANCODE_WWW          + Keyboard_Input_Shift),
    K_MAIL        = (SDL_SCANCODE_MAIL         + Keyboard_Input_Shift),
    K_CALCULATOR  = (SDL_SCANCODE_CALCULATOR   + Keyboard_Input_Shift),
    K_COMPUTER    = (SDL_SCANCODE_COMPUTER     + Keyboard_Input_Shift),
    K_AC_SEARCH   = (SDL_SCANCODE_AC_SEARCH    + Keyboard_Input_Shift),
    K_AC_HOME     = (SDL_SCANCODE_AC_HOME      + Keyboard_Input_Shift),
    K_AC_BACK     = (SDL_SCANCODE_AC_BACK      + Keyboard_Input_Shift),
    K_AC_FORWARD  = (SDL_SCANCODE_AC_FORWARD   + Keyboard_Input_Shift),
    K_AC_STOP     = (SDL_SCANCODE_AC_STOP      + Keyboard_Input_Shift),
    K_AC_REFRESH  = (SDL_SCANCODE_AC_REFRESH   + Keyboard_Input_Shift),
    K_AC_BOOKMARKS= (SDL_SCANCODE_AC_BOOKMARKS + Keyboard_Input_Shift),


    //--------------------------------------------------------------------------
    //
    K_BRIGHTNESSDOWN = (SDL_SCANCODE_BRIGHTNESSDOWN + Keyboard_Input_Shift),
    K_BRIGHTNESSUP  = (SDL_SCANCODE_BRIGHTNESSUP    + Keyboard_Input_Shift),
    K_DISPLAYSWITCH = (SDL_SCANCODE_DISPLAYSWITCH   + Keyboard_Input_Shift),

    //--------------------------------------------------------------------------
    //
    K_KBDILLUMTOGGLE = (SDL_SCANCODE_KBDILLUMTOGGLE + Keyboard_Input_Shift),
    K_KBDILLUMDOWN   = (SDL_SCANCODE_KBDILLUMDOWN   + Keyboard_Input_Shift),
    K_KBDILLUMUP     = (SDL_SCANCODE_KBDILLUMUP     + Keyboard_Input_Shift),
    K_EJECT          = (SDL_SCANCODE_EJECT          + Keyboard_Input_Shift),
    K_SLEEP          = (SDL_SCANCODE_SLEEP          + Keyboard_Input_Shift),

    //--------------------------------------------------------------------------
    //
    K_APP1 = (SDL_SCANCODE_APP1 + Keyboard_Input_Shift),
    K_APP2 = (SDL_SCANCODE_APP2 + Keyboard_Input_Shift),

    //--------------------------------------------------------------------------
    //
    K_AUDIOREWIND      = (SDL_SCANCODE_AUDIOREWIND       + Keyboard_Input_Shift),
    K_AUDIOFASTFORWARD = (SDL_SCANCODE_AUDIOFASTFORWARD + Keyboard_Input_Shift),

}; // enum

} // namespace Input
} // namespace Cooper
