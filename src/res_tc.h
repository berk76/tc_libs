/*
*       res_tc.h
*
*       This file is part of Turbo C Libraries.
*       https://github.com/berk76/tc_libs
*
*       Tetris is free software; you can redistribute it and/or modify
*       it under the terms of the GNU General Public License as published by
*       the Free Software Foundation; either version 3 of the License, or
*       (at your option) any later version. <http://www.gnu.org/licenses/>
*
*       Written by Jaroslav Beran <jaroslav.beran@gmail.com>, on 25.6.2017
*/


#ifndef _RES_TC_
#define _RES_TC_


static char *floating_text = "TC Libs is collection of Turbo C libraries. "
        "All sources are available at github.com/berk76/tc_libs - berk -";


/*
*       Colors:
*       -------
*       blue            \x01\x01
*       green           \x01\x02
*       cyan            \x01\x03
*       red             \x01\x04
*       magenta         \x01\x05
*       brown           \x01\x06
*       lightgray       \x01\x07
*       darkgray        \x01\x08
*       lightblue       \x01\x09
*       lightgreen      \x01\x0a
*       lightcyan       \x01\x0b
*       lightred        \x01\x0c
*       lightmagenta    \x01\x0d
*       yellow          \x01\x0e
*       white           \x01\x0f
*/


char *gfx_tclibs =  "\x01\x0e  _______ _______     ___    __ __ \n"
                    " |       |   _   |   |   |  |__|  |--.-----.\n"
                    " |.|   | |.  1___|   |.  |  |  |  _  |__ --|\n"
                    " \x01\x0c`-|.  |-|.  |___    |.  |__|__|_____|_____|\n"
                    "   |:  | |:  1   |   |:  1   |\n"
                    "   |::.| |::.. . |   |::.. . |\n"
                    "   `---' `-------'   `-------'";

#ifdef _SOUND_TC_

/*
*       Sounds
*/


/* Holka modrooka */
#define SD2 17
#define SR2 60
static SND_PLAY_NOTE s2[] = {{G5,N4},{A5,N4},{G5,N8},{G5,N8},{E5,N8},{G5,N8}, 
                       {F5,N8},{F5,N8},{D5,N8},{F5,N8},{G5,N8},{G5,N8},{E5,N8},{F5,N8}, 
                       {G5,N4},{A5,N4},{G5,N8},{G5,N8},{E5,N8},{G5,N8}, 
                       {F5,N8},{F5,N8},{D5,N8},{F5,N8},{E5,N4},{REST,N4}, 
                       {F5,N8},{F5,N8},{D5,N8},{F5,N8},{G5,N8},{G5,N8},{E5,N8},{G5,N8}, 
                       {F5,N8},{F5,N8},{D5,N8},{F5,N8},{G5,N8},{G5,N8},{E5,N8},{F5,N8}, 
                       {G5,N4},{A5,N4},{G5,N8},{G5,N8},{E5,N8},{G5,N8}, 
                       {F5,N8},{F5,N8},{D5,N8},{F5,N8},{E5,N4},{REST,N4}, 
                       {REST,N2}, 
                       {REPEAT,N2} 
                };


/* Saxana */
#define SD4 17
#define SR4 60
static SND_PLAY_NOTE s4[] = {{C4,N4},{A4,N4},{G4,N4},{REST,N4}, 
                       {E4,N16},{E4,N8},{E4,N16},{E4,N64},{D4,N16},{C4,N8},{E4,N4},{D4,N4},
                       {C4,N4},{A4,N4},{G4,N4},{REST,N4},
                       {E4,N8},{E4,N16},{E4,N16},{D4,N8},{D4,N8},{C4,N4},{REST,N4},
                       {C4,N4},{A4,N4},{G4,N4},{REST,N4},
                       {E4,N16},{E4,N8},{E4,N16},{E4,N64},{D4,N16},{C4,N8},{E4,N4},{D4,N4},
                       {C4,N4},{A4,N4},{G4,N4},{REST,N4},
                       {E4,N8},{E4,N16},{E4,N16},{D4,N8},{D4,N8},
                       {C4,N4},{REST,N4},{REST,N2},
                       {C4,N16},{C4,N8},{C4,N16},{C4,N16},{C4,N8},{C4,N16},{E4,N16},{E4,N16},{E4,N8},{E4,N16},{E4,N8},{E4,N16},
                       {F4,N16},{F4,N16},{F4,N8},{F4,N16},{F4,N8},{F4,N16},{A4,N4},{A4,N16},{A4,N8},{B4,N16},
                       {B4,N2},{REST,N16},{B4,N16},{B4,N8},
                       {B4,N1},
                       {C4,N16},{C4,N8},{C4,N16},{C4,N16},{C4,N8},{C4,N16},{E4,N16},{E4,N16},{E4,N8},{E4,N16},{E4,N8},{E4,N16},
                       {F4,N16},{F4,N16},{F4,N8},{F4,N16},{F4,N8},{F4,N16},{A4,N4},{A4,N16},{A4,N8},{B4,N16},
                       {B4,N2},{REST,N16},{B4,N16},{B4,N8},
                       {B4,N1},
                       {REPEAT,N32} 
                };


/* Dance of The Trolls */
#define SD5 17
#define SR5 60
static SND_PLAY_NOTE s5[] = {{F5,N8},{E5,N8},{C5,N8},{B4,N8},{A4,N4},{A4,N4},
                               {F5,N8},{E5,N8},{C5,N8},{B4,N8},{D5,N4},{D5,N8},{REST,N8},
                               {F5,N8},{E5,N8},{C5,N8},{B4,N8},{A4,N4},{A4,N4},
                               {B4,N8},{C5,N8},{D5,N8},{G4,N8},{A4,N4},{A4,N8},{REST,N8},
                               {A4,N4},{B4,N4},{C5,N8},{D5,N8},{E5,N4},
                               {E5,N8},{D5,N8},{C5,N4},{B4,N4},{B4,N4},
                               {A4,N4},{B4,N4},{C5,N8},{D5,N8},{E5,N4},
                               {E5,N8},{C5,N8},{B4,N8},{C5,N8},{A4,N4},{A4,N4},
                               {F5,N8},{E5,N8},{C5,N8},{B4,N8},{D5,N4},{D5,N8},{REST,N8},
                               {F5,N8},{E5,N8},{C5,N8},{B4,N8},{A4,N4},{A4,N4},
                               {F5,N8},{E5,N8},{C5,N8},{B4,N8},{D5,N4},{D5,N8},{REST,N8},
                               {B4,N8},{C5,N8},{D5,N8},{G4,N8},{A4,N4},{A4,N8},{REST,N8},
                               {A4,N4},{B4,N4},{C5,N8},{D5,N8},{E5,N4},
                               {E5,N8},{D5,N8},{C5,N4},{B4,N4},{B4,N4},
                               {A4,N4},{B4,N4},{C5,N8},{D5,N8},{E5,N4},
                               {E5,N8},{C5,N8},{B4,N8},{C5,N8},{A4,N4},{E5,N8},{F5,N8},
                               {E5,N4},{E5,N8},{F5,N8},{D5,N4},{D5,N8},{E5,N8},
                               {C5,N4},{C5,N8},{D5,N8},{B4,N4},{B4,N8},{C5,N8},
                               {E5,N8},{C5,N8},{B4,N8},{C5,N8},{A4,N4},{A4,N4},
                               {F5,N8},{E5,N8},{C5,N8},{B4,N8},{D5,N4},{D5,N8},{REST,N8},
                               {F5,N8},{E5,N8},{C5,N8},{B4,N8},{A4,N4},{A4,N4},
                               {F5,N8},{E5,N8},{C5,N8},{B4,N8},{D5,N4},{D5,N8},{REST,N8},
                               {B4,N8},{C5,N8},{D5,N8},{G4,N8},{A4,N4},{A4,N8},{REST,N8},
                               {REPEAT,N16}
                };
                
                
/* Can Can */
#define SD6 11
#define SR6 60
static SND_PLAY_NOTE s6[] = {{D4,N8},{A4,N8},{A4,N8},{B4,N8},
                             {A4,N8},{G4,N8},{G4,N8},{B4,N8},
                             {C5,N8},{E5,N8},{G5,N8},{E5,N8},
                             {E5,N8},{D5,N8},{D5,N4},
                             {E5,N8},{F4,N8},{F4,N8},{E5,N8},
                             {D5,N8},{G4,N8},{G4,N8},{B4,N8},
                             {B4,N8},{A4,N8},{B4,N8},{A4,N8},
                             {B4,N8},{A4,N8},{B4,N8},{A4,N8},
                             /* 09 */
                             {A4,N8},{G4,N8},{G4,N4},
                             {B4,N4},{G4,N4},
                             {E4,N4},{D4,N4},
                             {D4,N8},{A4,N8},{B4,N8},{C5,N8},
                             {B4,N8},{A4,N8},{G4,N4},
                             {B4,N4},{G4,N4},
                             {E4,N4},{D4,N4},
                             {C4S,N8},{D4,N8},{E4,N8},{F4,N8},
                             {A4,N8},{G4,N8},{G4,N4},
                             /* 18 */
                             {G4,N8},{D4,N8},{F4,N8},{D4,N8},
                             {G4,N8},{D4,N8},{F4,N8},{D4,N8},
                             {G4,N8},{D4,N8},{F4,N8},{D4,N8},
                             {G4,N8},{D4,N8},{F4,N8},{D4,N8},
                             {G4,N8DOT},{G4,N16},{G4,N8DOT},{G4,N16},
                             {G4,N8DOT},{G4,N16},{G4,N8DOT},{G4,N16},
                             {G4,N8DOT},{G4,N16},{G4,N8DOT},{G4,N16},
                             {G4,N8DOT},{G4,N16},{G4,N8DOT},{G4,N16},
                             /* 26 */
                             {C4,N2},
                             {D4,N8},{F4,N8},{E4,N8},{D4,N8},
                             {G4,N4},{G4,N4},
                             {G4,N8},{A4,N8},{E4,N8},{F4,N8},
                             {D4,N4},{D4,N4},
                             {D4,N8},{F4,N8},{E4,N8},{D4,N8},
                             {C4,N8},{C5,N8},{B4,N8},{A4,N8},
                             {G4,N8},{F4,N8},{E4,N8},{D4,N8},
                             {C4,N2},
                             {D4,N8},{F4,N8},{E4,N8},{D4,N8},
                             /* 36 */
                             {G4,N4},{G4,N4},
                             {G4,N8},{A4,N8},{E4,N8},{F4,N8},
                             {D4,N4},{D4,N4},
                             {D4,N8},{F4,N8},{E4,N8},{D4,N8},
                             {C4,N8},{G4,N8},{D4,N8},{E4,N8},
                             {C4,N4},{G4,N4},
                             {C4,N4},{C4,N4},
                             {D4,N8},{A4,N8},{A4,N8},{B4,N8},
                             {A4,N8},{G4,N8},{G4,N8},{B4,N8},
                             /* 45 */
                             {C5,N8},{E5,N8},{G5,N8},{E5,N8},
                             {E5,N8},{D5,N8},{D5,N4},
                             {E5,N8},{F4,N8},{F4,N8},{E5,N8},
                             {D5,N8},{G4,N8},{G4,N8},{B4,N8},
                             {B4,N8},{A4,N8},{B4,N8},{A4,N8},
                             {B4,N8},{A4,N8},{B4,N8},{A4,N8},
                             {E5,N8},{D5,N8},{D5,N4},
                             {E5,N8},{D5,N8},{D5,N4},
                             {E5,N8},{D5,N8},{D5,N4},
                             /* 54 */
                             {E5,N8},{D5,N8},{D5,N4},
                             {E5,N8},{D5,N8},{D5,N4},
                             {E5,N8},{D5,N8},{D5,N4},
                             {E5,N8},{D5,N8},{D5,N4},
                             {E5,N8},{D5,N8},{D5,N4},
                             {E5,N8},{D5,N8},{E5,N8},{D5,N8},
                             {E5,N8},{D5,N8},{E5,N8},{D5,N8},
                             {G4,N2},
                             {A4,N8},{C5,N8},{B4,N8},{A4,N8},
                             {D5,N4},{D5,N4},
                             /* 64 */
                             {D5,N8},{E5,N8},{B4,N8},{C5,N8},
                             {A4,N4},{A4,N4},
                             {A4,N8},{C5,N8},{B4,N8},{A4,N8},
                             {G4,N8},{G5,N8},{F5,N8},{E5,N8},
                             {D5,N8},{C5,N8},{B4,N8},{A4,N8},
                             {G4,N2},
                             {A4,N8},{C5,N8},{B4,N8},{A4,N8},
                             {D5,N4},{D5,N4},
                             {D5,N8},{E5,N8},{B4,N8},{C5,N8},
                             /* 73 */
                             {A4,N4},{A4,N4},
                             {A4,N8},{C5,N8},{B4,N8},{A4,N8},
                             {G4,N8},{D5,N8},{A4,N8},{B4,N8},
                             {G4,N4},{D4,N4},
                             {G4,N4},{G4,N4},
                             {A4,N4},{B4,N4},
                             {D5,N8},{C5,N8},{F5,N8},{E5,N8},
                             {D5,N8},{C5,N8},{B4,N8},{A4,N8},
                             {G4,N4},{G4,N4},
                             {A4,N4},{B4,N4},
                             /* 83 */
                             {D5,N8},{C5,N8},{F5,N8},{E5,N8},
                             {D5,N8},{C5,N8},{B4,N8},{A4,N8},
                             {G4,N8},{D5,N8},{A4,N8},{B4,N8},
                             {G4,N8},{D5,N8},{A4,N8},{B4,N8},
                             {G4,N8},{D5,N8},{A4,N8},{B4,N8},
                             {G4,N8},{D5,N8},{A4,N8},{B4,N8},
                             {G4,N4},{REST,N4},
                             {G4,N4},{G5,N4},
                             {G4,N4},{REST,N4},
                             {REPEAT,N1}
                };

#endif                
#endif

