/*      
*       xmas.c
*
*       This file is part of Turbo C Libraries.
*       https://github.com/berk76/tc_libs
*       
*       Turbo C Libs is free software; you can redistribute it and/or modify
*       it under the terms of the GNU General Public License as published by
*       the Free Software Foundation; either version 3 of the License, or
*       (at your option) any later version. <http://www.gnu.org/licenses/>
*       
*       Written by Jaroslav Beran <jaroslav.beran@gmail.com>, on 25.12.2017        
*/


#include <stdio.h>
#include <assert.h>
#include <conio.h>
#include <time.h>
#include "sound_tc.h"
#include "tui_tc.h"
#include "wait_tc.h"


static char *floating_text = "Vesele Vanoce! ";

static char *betlem = "                            -\n" 
                      "                          /\\O/\\\n"
                      "                         {_/-\\_}\n"
                      "                           /_\\\n"
                      "\n"
                      ".-----------------------------------------------------.\n"
                      "| __  ___________________   |   _________________  __ |\n"
                      "|| / /                    '.|.'                  \\ \\ ||\n"
                      "||/ /            ___     -= + =-                  \\ \\||\n"
                      "|  /           *******    .'|'.      ___           \\  |\n"
                      "| /            /-====)      |      *******          \\ |\n"
                      "||             | / -(       |      (_.- ))           ||\n"
                      "||            / /  _/               )- ) ))          ||\n"
                      "||            | |-(    _            \\_(  ((          ||\n"
                      "||            / |  \\  //|        _    )) ) )         ||\n"
                      "||           /  \\   \\/\\/        |\\\\  /'-( (          ||\n"
                      "||          |   |\\    /    ***   \\/\\/  / ) )         ||\n"
                      "||          `-;/==;--'     .=.    \\   / (  (         ||\n"
                      "||            |    \\    _\\/(_)\\/_  '-;==)   )        ||\n"
                      "||            |     \\    |'---'|    /  (   (         ||\n"
                      "||            |      \\  _|:.   |_  /   )    )        ||\n"
                      "||          _/        |  /\\:. /\\  |   (     (        ||\n"
                      "||       .-/         /     '='    \\    (     )-.     ||\n"
                      "||jgs   `\"\"---`-----`              `----`----`\"\"`    ||";

static char *candle = "            _...._\n"
                      "          .:::\\::::.\n"
                      "         :::::)`\\::::\n"
                      "         ::::/  /::::\n"
                      "         :::| , |::::\n"
                      "          '::\\;/:::'\n"
                      "         /`\"'-:___\n"
                      "        |        _`\\\n"
                      "        | .-.   ( \\ ;   ,    ,\n"
                      " ,  ,   \\_)  '--' | (   |\\_.'/\n"
                      " )`-'\\__,|:.      \\_)|\\_/ .`(_\n"
                      " / `.   (|::.     _|  . '_.-'`\n"
                      "'--. `'. |:::.   (_)_'  (\n"
                      "   /.-. `\\::::._(_)(_)`--'\n"
                      "    `   \\/ jgs _). '-.  '--._\n"
                      "     _.-'  . `)  :  ( `-.   <\n"
                      "    )    . <'-. ' .-',  _'._'.\n"
                      "   '-.  '.-'`  )'/    \\/ \\(\n"
                      "      `\\(      `;";
                      
static char *candl1 = "            _...._\n"
                      "          .:::\\::::.\n"
                      "         :::::)`\\::::\n"
                      "         ::::/  /::::";

static char *candl2 = "            _...._\n"
                      "          .:::/::::.\n"
                      "         :::/`(::::::\n"
                      "         :::\\  \\:::::";


/* Pujdem spolu do betlema */
#define SD1 23
#define SR1 60
static SND_PLAY_NOTE s1[] = {{F4,N8},{F4,N8},{C4,N8},{C4,N8},
                             {B4,N8},{B4,N8},{F4,N8},{F4,N8},
                             {A4S,N16},{C5,N16},{D5,N16},{C5,N16},{A4,N16},{C5,N16},{D5,N16},{C5,N16},
                             {A4S,N16},{C5,N16},{D5,N16},{A4,N16},{C5,N4},
                             {A4,N8},{A4,N16},{D5,N16},{G4,N4},
                             {B4,N8},{B4,N16},{C5,N16},{F4,N4},
                             {G4,N8},{G4,N8},{F4,N16},{E4,N16},{D4,N16},{C4,N16},
                             {F4,N8},{B4,N8},{F4,N8},{B4,N8},
                             {A4,N8},{A4,N16},{D5,N16},{G4,N4},
                             {B4,N8},{B4,N16},{C5,N16},{F4,N4},
                             {G4,N8},{G4,N8},{F4,N16},{E4,N16},{D4,N16},{C4,N16},
                             {F4,N8},{B4,N8},{F4,N8},{REST,N8},
                             {REPEAT,N1}
                };
                
/* Ticha noc */
#define SD2 17
#define SR2 60
static SND_PLAY_NOTE s2[] = {{F4,N4DOT},{G4,N8},{F4,N4},{D4,N2DOT},
                             {F4,N4DOT},{G4,N8},{F4,N4},{D4,N2DOT},
                             {C5,N2},{C5,N4},{B4,N2DOT},
                             {A4,N2},{A4,N4},{F4,N2DOT},
                             {G4,N2},{G4,N4},{A4,N4},{B4,N4},{G4,N4},
                             {F4,N4DOT},{G4,N8},{F4,N4},{D4,N2DOT},
                             {G4,N2},{G4,N4},{A4,N4DOT},{B4,N8},{G4,N4},
                             {F4,N4DOT},{G4,N8},{F4,N4},{D4,N2DOT},
                             {C5,N4},{C5,N4},{C5,N4},{E5,N4DOT},{C5,N8},{B4,N4},
                             {B4,N2DOT},{D5,N2DOT},
                             {B4,N4DOT},{F4,N8},{D4,N4},{F4,N4DOT},{E4,N8},{C4,N4},
                             {A3,N2DOT},{A3,N2},{REST,N2},
                             {REPEAT,N1}
                };


#define BUFF_LEN 512
#define TUI_COL LIGHTGRAY
#define TUI_BKCOL BLACK


static WINDOW_T *mainw = NULL;

static JOB_T *j2;       /* floating text */
#define j2p -1
static JOB_T *j3;       /* sound */
#define j3p 1
static JOB_T *j4;       /* animations */
#define j4p -1

static int candle_x, candle_y;

static SND_SONG song;
static int play_sound;

static long animate_scr(enum W_ACTION a);
static long draw_floating_text(enum W_ACTION a);


int main() {    
        mainw = tui_create_win(1, 1, TUI_SCR_X_SIZE, TUI_SCR_Y_SIZE, TUI_COL, TUI_BKCOL, ' ');
        srand(time(NULL) % 37);
        j2 = w_register_job(4, j2p, &draw_floating_text);
        j3 = NULL;
        j4 = NULL;
        
        
        /* play */ 
        tui_cls_win(mainw, FALSE);
        tui_draw_box(13, 1, TUI_COL, TUI_BKCOL, betlem, FALSE);
        
        song.duration = SD1;
        song.rest = SR1;
        song.song = s1;
        snd_setsong(&song);
        j3 = w_register_job(6, j3p, &snd_play_sound);
        tui_wait_for_any_key();
        
        w_unregister_job(j3);
        j3 = NULL;
        snd_speaker(0);
        
        candle_x = 25;
        candle_y = 4;        
        tui_cls_win(mainw, FALSE);
        tui_draw_box(candle_x, candle_y, TUI_COL, TUI_BKCOL, candle, FALSE);
        j4 = w_register_job(18, j4p, &animate_scr);
        
        song.duration = SD2;
        song.rest = SR2;
        song.song = s2;
        snd_setsong(&song);
        j3 = w_register_job(6, j3p, &snd_play_sound);
        tui_wait_for_any_key();
        
        w_unregister_job(j3);
        j3 = NULL;
        snd_speaker(0);
        
        w_unregister_job(j4);
        j4 = NULL;
        
        

        /* quit */
        if (j3 != NULL)
                w_unregister_job(j3);
        if (j4 != NULL)
                w_unregister_job(j4);
        snd_speaker(0);
        w_unregister_job(j2);
        tui_delete_win(mainw);
        return 0;
}


long animate_scr(enum W_ACTION a) {
        static int step = -1;
        static int paused = 0;
        int r;
        
        
        if ((a == RESET) || (step == -1)) {
                step = 0;
                paused = 0;
                return 0;        
        }
        
        if (a == PAUSE) {
                paused = 1;
        }
        
        if (a == UNPAUSE) {
                paused = 0;
        }            
        
        if (a == RUN) {
                if (paused != 0)
                        return 0;
                        
                switch (step) {
                        case 0:
                                tui_draw_box(candle_x, candle_y, TUI_COL, TUI_BKCOL, candl2, FALSE);
                                tui_flush();
                                step = 1;
                                r = 5;
                                break;
                        case 1:
                                tui_draw_box(candle_x, candle_y, TUI_COL, TUI_BKCOL, candl1, FALSE);
                                tui_flush();
                                step = 0;
                                r = 30;
                                break;
                }        
        }
        return r;
}


long draw_floating_text(enum W_ACTION a) {
        #define FT_X 5
        #define FT_Y 25
        #define FT_LEN 70
        
        static char b[(FT_LEN - 1) * 2];
        static char *p = NULL;
        static i;
        
        if ((a == RESET) || (p == NULL)) {
                tui_set_attr(0, TUI_COL, TUI_BKCOL);
                gotoxy(FT_X, FT_Y);
                for(i = 0; i < FT_LEN; i++)
                        putch(' ');
                p = floating_text;
                i = 0;
                
                return 0;
        }
        
        if (a == RUN) {
                gotoxy(FT_X,FT_Y);
                tui_set_attr(0, DARKGRAY, TUI_BKCOL);
                
                gettext(FT_X + 1 , FT_Y, FT_X + 1 + (FT_LEN - 2), FT_Y, b);
                puttext(FT_X, FT_Y, FT_X + (FT_LEN - 2), FT_Y, b);
                
                gotoxy(FT_X + FT_LEN - 1, FT_Y);
                
                if (*p == '\0') {
                        putch(' ');
                        i++;
                        if (i == FT_LEN) {
                                p = NULL;
                                i = 0;
                        } 
                } else {
                        putch(*p);
                        p++;
                }
                
                tui_flush();
        }
        return 0;
}
