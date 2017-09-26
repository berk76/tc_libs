/*      res_snd.h
*
*       This file is part of Turbo C Libraries.
*       https://github.com/berk76/tc_libs
*       
*       Turbo C Libs is free software; you can redistribute it and/or modify
*       it under the terms of the GNU General Public License as published by
*       the Free Software Foundation; either version 3 of the License, or
*       (at your option) any later version. <http://www.gnu.org/licenses/>
*       
*       Written by Jaroslav Beran <jaroslav.beran@gmail.com>, on 18.9.2017
*/

#ifndef _RES_SND_
#define _RES_SND_


/* Holka modrooka */
#define SD2 17
#define SR2 60
static AL_PLAY_NOTE s2[] = {
{G,O5,N4},{A,O5,N4},{G,O5,N8},{G,O5,N8},{E,O5,N8},{G,O5,N8}, 
{F,O5,N8},{F,O5,N8},{D,O5,N8},{F,O5,N8},{G,O5,N8},{G,O5,N8},{E,O5,N8},{F,O5,N8}, 
{G,O5,N4},{A,O5,N4},{G,O5,N8},{G,O5,N8},{E,O5,N8},{G,O5,N8}, 
{F,O5,N8},{F,O5,N8},{D,O5,N8},{F,O5,N8},{E,O5,N4},{REST,O5,N4}, 
{F,O5,N8},{F,O5,N8},{D,O5,N8},{F,O5,N8},{G,O5,N8},{G,O5,N8},{E,O5,N8},{G,O5,N8}, 
{F,O5,N8},{F,O5,N8},{D,O5,N8},{F,O5,N8},{G,O5,N8},{G,O5,N8},{E,O5,N8},{F,O5,N8}, 
{G,O5,N4},{A,O5,N4},{G,O5,N8},{G,O5,N8},{E,O5,N8},{G,O5,N8}, 
{F,O5,N8},{F,O5,N8},{D,O5,N8},{F,O5,N8},{E,O5,N4},{REST,O5,N4}, 
{REST,O5,N2}, 
{REPEAT,O5,N2} 
};


/* Pro Elisku */
#define SD3 17
#define SR3 60
static AL_PLAY_NOTE s3[] = {{E,O5,N16},{DS,O5,N16},
                       {E,O5,N16},{DS,O5,N16},{E,O5,N16},{B,O4,N16},{D,O5,N16},{C,O5,N16},
                       {A,O4,N8},{REST,O4,N16},{C,O4,N16},{E,O4,N16},{A,O4,N16},
                       {B,O4,N8},{REST,O4,N16},{E,O4,N16},{GS,O4,N16},{B,O4,N16},
                       {C,O5,N8},{REST,O5,N16},{E,O4,N16},{E,O5,N16},{DS,O5,N16},
                       {E,O5,N16},{DS,O5,N16},{E,O5,N16},{B,O4,N16},{D,O5,N16},{C,O5,N16},
                       {A,O4,N8},{REST,O4,N16},{C,O4,N16},{E,O4,N16},{A,O4,N16},
                       /* 7 */
                       {B,O4,N8},{REST,O4,N16},{E,O4,N16},{C,O5,N16},{B,O4,N16},
                       {A,O4,N4},
                       {A,O4,N8},{REST,O4,N16},{B,O4,N16},{C,O5,N16},{D,O5,N16},
                       {E,O5,N8DOT},{G,O4,N16},{F,O5,N16},{E,O5,N16},
                       {D,O5,N8DOT},{F,O4,N16},{E,O5,N16},{D,O4,N16},
                       {C,O5,N8DOT},{E,O4,N16},{D,O5,N16},{C,O5,N16},
                       {B,O4,N8},{REST,O4,N16},{E,O4,N16},{E,O5,N16},{REST,O5,N16},
                       /* 14 */
                       {REST,O5,N16},{E,O5,N16},{E,O6,N16},{REST,O6,N16},{REST,O6,N16},{DS,O5,N16},
                       {E,O5,N16},{REST,O5,N16},{REST,O5,N16},{DS,O5,N16},{E,O5,N16},{D,O5,N16},
                       {E,O5,N16},{DS,O5,N16},{E,O5,N16},{B,O4,N16},{D,O5,N16},{C,O5,N16},
                       {A,O4,N8},{REST,O4,N16},{C,O4,N16},{E,O4,N16},{A,O4,N16},
                       {B,O4,N8},{REST,O4,N16},{E,O4,N16},{GS,O4,N16},{B,O4,N16},
                       {C,O5,N8},{REST,O5,N16},{E,O4,N16},{E,O5,N16},{DS,O5,N16},
                       {E,O5,N16},{DS,O5,N16},{E,O5,N16},{B,O4,N16},{D,O5,N16},{C,O5,N16},
                       /* 21 */
                       {REST,O5,N1},
                       {REPEAT,O5,N2} 
                };


/* Saxana */
#define SD4 17
#define SR4 60
static AL_PLAY_NOTE s4[] = {{C,O4,N4},{A,O4,N4},{G,O4,N4},{REST,O4,N4}, 
                       {E,O4,N16},{E,O4,N8},{E,O4,N16},{E,O4,N64},{D,O4,N16},{C,O4,N8},{E,O4,N4},{D,O4,N4},
                       {C,O4,N4},{A,O4,N4},{G,O4,N4},{REST,O4,N4},
                       {E,O4,N8},{E,O4,N16},{E,O4,N16},{D,O4,N8},{D,O4,N8},{C,O4,N4},{REST,O4,N4},
                       {C,O4,N4},{A,O4,N4},{G,O4,N4},{REST,O4,N4},
                       {E,O4,N16},{E,O4,N8},{E,O4,N16},{E,O4,N64},{D,O4,N16},{C,O4,N8},{E,O4,N4},{D,O4,N4},
                       {C,O4,N4},{A,O4,N4},{G,O4,N4},{REST,O4,N4},
                       {E,O4,N8},{E,O4,N16},{E,O4,N16},{D,O4,N8},{D,O4,N8},
                       {C,O4,N4},{REST,O4,N4},{REST,O4,N2},
                       {C,O4,N16},{C,O4,N8},{C,O4,N16},{C,O4,N16},{C,O4,N8},{C,O4,N16},{E,O4,N16},{E,O4,N16},{E,O4,N8},{E,O4,N16},{E,O4,N8},{E,O4,N16},
                       {F,O4,N16},{F,O4,N16},{F,O4,N8},{F,O4,N16},{F,O4,N8},{F,O4,N16},{A,O4,N4},{A,O4,N16},{A,O4,N8},{B,O4,N16},
                       {B,O4,N2},{REST,O4,N16},{B,O4,N16},{B,O4,N8},
                       {B,O4,N1},
                       {C,O4,N16},{C,O4,N8},{C,O4,N16},{C,O4,N16},{C,O4,N8},{C,O4,N16},{E,O4,N16},{E,O4,N16},{E,O4,N8},{E,O4,N16},{E,O4,N8},{E,O4,N16},
                       {F,O4,N16},{F,O4,N16},{F,O4,N8},{F,O4,N16},{F,O4,N8},{F,O4,N16},{A,O4,N4},{A,O4,N16},{A,O4,N8},{B,O4,N16},
                       {B,O4,N2},{REST,O4,N16},{B,O4,N16},{B,O4,N8},
                       {B,O4,N1},
                       {REPEAT,O4,N32} 
                };


/* Dance of The Trolls */
#define SD5 17
#define SR5 60
static AL_PLAY_NOTE s5[] = {{F,O5,N8},{E,O5,N8},{C,O5,N8},{B,O4,N8},{A,O4,N4},{A,O4,N4},
                               {F,O5,N8},{E,O5,N8},{C,O5,N8},{B,O4,N8},{D,O5,N4},{D,O5,N8},{REST,O5,N8},
                               {F,O5,N8},{E,O5,N8},{C,O5,N8},{B,O4,N8},{A,O4,N4},{A,O4,N4},
                               {B,O4,N8},{C,O5,N8},{D,O5,N8},{G,O4,N8},{A,O4,N4},{A,O4,N8},{REST,O4,N8},
                               {A,O4,N4},{B,O4,N4},{C,O5,N8},{D,O5,N8},{E,O5,N4},
                               {E,O5,N8},{D,O5,N8},{C,O5,N4},{B,O4,N4},{B,O4,N4},
                               {A,O4,N4},{B,O4,N4},{C,O5,N8},{D,O5,N8},{E,O5,N4},
                               {E,O5,N8},{C,O5,N8},{B,O4,N8},{C,O5,N8},{A,O4,N4},{A,O4,N4},
                               {F,O5,N8},{E,O5,N8},{C,O5,N8},{B,O4,N8},{D,O5,N4},{D,O5,N8},{REST,O5,N8},
                               {F,O5,N8},{E,O5,N8},{C,O5,N8},{B,O4,N8},{A,O4,N4},{A,O4,N4},
                               {F,O5,N8},{E,O5,N8},{C,O5,N8},{B,O4,N8},{D,O5,N4},{D,O5,N8},{REST,O5,N8},
                               {B,O4,N8},{C,O5,N8},{D,O5,N8},{G,O4,N8},{A,O4,N4},{A,O4,N8},{REST,O5,N8},
                               {A,O4,N4},{B,O4,N4},{C,O5,N8},{D,O5,N8},{E,O5,N4},
                               {E,O5,N8},{D,O5,N8},{C,O5,N4},{B,O4,N4},{B,O4,N4},
                               {A,O4,N4},{B,O4,N4},{C,O5,N8},{D,O5,N8},{E,O5,N4},
                               {E,O5,N8},{C,O5,N8},{B,O4,N8},{C,O5,N8},{A,O4,N4},{E,O5,N8},{F,O5,N8},
                               {E,O5,N4},{E,O5,N8},{F,O5,N8},{D,O5,N4},{D,O5,N8},{E,O5,N8},
                               {C,O5,N4},{C,O5,N8},{D,O5,N8},{B,O4,N4},{B,O4,N8},{C,O5,N8},
                               {E,O5,N8},{C,O5,N8},{B,O4,N8},{C,O5,N8},{A,O4,N4},{A,O4,N4},
                               {F,O5,N8},{E,O5,N8},{C,O5,N8},{B,O4,N8},{D,O5,N4},{D,O5,N8},{REST,O5,N8},
                               {F,O5,N8},{E,O5,N8},{C,O5,N8},{B,O4,N8},{A,O4,N4},{A,O4,N4},
                               {F,O5,N8},{E,O5,N8},{C,O5,N8},{B,O4,N8},{D,O5,N4},{D,O5,N8},{REST,O5,N8},
                               {B,O4,N8},{C,O5,N8},{D,O5,N8},{G,O4,N8},{A,O4,N4},{A,O4,N8},{REST,O4,N8},
                               {REPEAT,O4,N16}
                };


#endif