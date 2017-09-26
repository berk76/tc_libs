/*
*       adli_tc.h
*
*       This file is part of Turbo C Libraries.
*       https://github.com/berk76/tc_libs
*       
*       Turbo C Libs is free software; you can redistribute it and/or modify
*       it under the terms of the GNU General Public License as published by
*       the Free Software Foundation; either version 3 of the License, or
*       (at your option) any later version. <http://www.gnu.org/licenses/>
*       
*       Written by Jaroslav Beran <jaroslav.beran@gmail.com>, on 25.8.2017        
*/


#ifndef _ADLI_TC_H_
#define _ADLI_TC_H_

#include "wait_tc.h"


typedef struct {
        unsigned char ar0;      /* Attack Rate                               */ 
        unsigned char dr0;      /* Decay Rate                                */ 
        unsigned char sl0;      /* Sustain Level                             */ 
        unsigned char rr0;      /* Release Rate                              */ 
        unsigned char ml0;      /* Multiple                                  */
        unsigned char ks0;      /* Key scaling level                         */ 
        unsigned char tl0;      /* Operator output level                     */ 
        unsigned char ws0;      /* Wave Select                               */ 
        unsigned char avek0;    /* Amp Mod / Vibrato / EG type / Key Scaling */
        unsigned char ar1; 
        unsigned char dr1; 
        unsigned char sl1; 
        unsigned char rr1; 
        unsigned char ml1;
        unsigned char ks1; 
        unsigned char tl1; 
        unsigned char ws1; 
        unsigned char avek1;
        unsigned char fb;       /* Feedback strength                         */ 
        unsigned char c;        /* Connection type                           */
} AL_SND_SHAPE;


enum AL_NOTE {
        REST = 0,
        REPEAT = 1,
        STOP = 2,
        
        C  = 0x2ae, 
        CS = 0x16b,
        D  = 0x181,
        DS = 0x198,
        E  = 0x1b0,
        F  = 0x1ca,
        FS = 0x1e5,
        G  = 0x202,
        GS = 0x220,
        A  = 0x241,
        AS = 0x263,
        B  = 0x287
};


enum AL_OCTAVE {
        O0 = 0, 
        O1 = 1,
        O2 = 2,
        O3 = 3,
        O4 = 4,
        O5 = 5,
        O6 = 6,
        O7 = 7
};


enum AL_CHANNEL {
        C1 = 0, 
        C2 = 1,
        C3 = 2,
        C4 = 3,
        C5 = 4,
        C6 = 5,
        C7 = 6,
        C8 = 7,
        C9 = 8
};


enum AL_DURATION {
        N1DOT   = 192,
        N1      = 128, 
        N2DOT   = 96,
        N2      = 64,
        N4DOT   = 48,
        N4      = 32,
        N8DOT   = 24,
        N8      = 16,
        N16DOT  = 12,
        N16     = 8,
        N32DOT  = 6,
        N32     = 4,
        N64DOT  = 3,
        N64     = 2,
        N128    = 1
};


typedef struct {
        enum SB_NOTE note;
        enum SB_OCTAVE octave;
        enum SB_DURATION duration;
} AL_PLAY_NOTE;
      
      
typedef struct {
        long duration;
        long rest;
        AL_PLAY_NOTE *song;
} AL_SONG;


/* 
*  Initialize sound card
*  0  = OK
*  -1 = sound card not found
*/
extern int al_init(int verbose);

/* 
*  Get instrument 
*/
extern AL_SND_SHAPE *al_getinstr(int i);
extern void al_setonech(unsigned char ch, AL_SND_SHAPE *s);
extern void al_setallch(AL_SND_SHAPE *s);

/*      
*  Play note
*/      
        
extern void al_playnote(enum AL_NOTE n, enum AL_OCTAVE o, enum AL_CHANNEL c);

/*      
*  Setup song
*/

extern void al_setsong(AL_SONG *s);

/*      
*  Play song
*/

extern long al_play_sound(enum W_ACTION a);


#endif