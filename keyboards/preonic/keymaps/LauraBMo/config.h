#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PREONIC_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

#define MUSIC_MASK (keycode != KC_NO)

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

/* Input mode for unicode chars: UC_MAC, UC_LNX or UC_WINC */
#define UNICODE_SELECTED_MODES UC_LNX

/* Space Cadet Shift */
/* https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/feature_space_cadet */
/* WARNING: Space Cadet must be defined here, in config.h */
/* WARNING:  LAPO_KEYS is already in use */
#define LSPO_KEYS KC_LGUI, KC_LSFT, KC_SCLN
#define RSPC_KEYS KC_LSFT, KC_LSFT, KC_LBRC
