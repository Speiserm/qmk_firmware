#pragma once
#define NO_MUSIC_MODE
#define CUSTOM \
E__NOTE(_A5  ), \
HD_NOTE(_E6  ),

#ifdef AUDIO_ENABLE
      #define STARTUP_SONG SONG(CUSTOM)
    // #define STARTUP_SONG SONG(NO_SOUND)
    #define AUDIO_CLICKY

#endif

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

#define LEADER_TIMEOUT 300
#define MK_3_SPEED
