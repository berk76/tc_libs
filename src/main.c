/*      
*       main.c
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


#include <stdio.h>
#include <assert.h>
#include <conio.h>
#include <time.h>
#include "sound_tc.h"
#include "tui_tc.h"
#include "wait_tc.h"
#include "res_tc.h"

#define BUFF_LEN 512
#define TUI_COL LIGHTGRAY
#define TUI_BKCOL BLACK


typedef enum {
        EMPTY,
        QUIT,
        HOLKA,
        SAXANA,
        DANCE,
        CANCAN
} OPTION_T;

static WINDOW_T *mainw = NULL;

static JOB_T *j2;       /* floating text */
#define j2p -1
static JOB_T *j3;       /* sound */
#define j3p 1
static JOB_T *j4;       /* animations */
#define j4p -1

static SND_SONG song;
static int play_sound;


static OPTION_T draw_mainscreen(void);
static void draw_goodbye(void);
static void draw_holka(void);
static void draw_saxana(void);
static void draw_dance(void);
static void draw_cancan(void);
static long draw_floating_text(enum W_ACTION a);


int main() {
        OPTION_T option;
        
        mainw = tui_create_win(1, 1, TUI_SCR_X_SIZE, TUI_SCR_Y_SIZE, TUI_COL, TUI_BKCOL, ' ');
        srand(time(NULL) % 37);
        j2 = w_register_job(4, j2p, &draw_floating_text);
        j3 = NULL;
        j4 = NULL;

        do {
                option = draw_mainscreen();
                         
                switch (option) {
                        case QUIT:
                                if (j3 != NULL)
                                        w_unregister_job(j3);
                                if (j4 != NULL)
                                        w_unregister_job(j4);
                                snd_speaker(0);
                                draw_goodbye();
                                w_unregister_job(j2);
                                tui_delete_win(mainw);
                                return 0;
                        case HOLKA:
                                draw_holka();
                                break;
                        case SAXANA:
                                draw_saxana();
                                break; 
                        case DANCE:
                                draw_dance();
                                break;
                        case CANCAN:
                                draw_cancan();
                                break;
                }       
        } while (1);
}


OPTION_T draw_mainscreen(void) {
        OPTION_T result;
        int i, c;
        char buff[BUFF_LEN];

        do {
                tui_cls_win(mainw, FALSE);
                tui_draw_box(1, 1, TUI_COL, TUI_BKCOL, gfx_tclibs, FALSE);
        
                sprintf(buff, "\x01\x0f\n"
                               " 1) Holka modrooka \n\n" \
                               " 2) Saxana \n\n" \
                               " 3) Dance of The Trolls \n\n" \
                               " 4) CanCan \n\n" \
                               " Q) Quit \n", \
                               (play_sound == 0) ? "off" : "on");
                assert(strlen(buff) < BUFF_LEN);
                
                c = tui_option(buff, "1234Qq", LIGHTCYAN, TUI_BKCOL);
                        
                switch (c) {
                        case '1':
                                result = HOLKA;
                                break;
                        case '2':
                                result = SAXANA;
                                break;
                        case '3':
                                result = DANCE;
                                break;
                        case '4':
                                result = CANCAN;
                                break;
                        case 'Q':
                        case 'q':
                                result = QUIT;
                                break;
                        default:
                                result = EMPTY;
                }
        } while (result == EMPTY);

        return result;
}


void draw_goodbye(void) {
        tui_cls_win(mainw, FALSE);
        tui_message("\n\x01\x0f Good Bye! \n", LIGHTCYAN, TUI_BKCOL);
}


void draw_holka(void) {
        tui_cls_win(mainw, FALSE);
        
        song.duration = SD2;
        song.rest = SR2;
        song.song = s2;
        snd_setsong(&song);
        j3 = w_register_job(6, j3p, &snd_play_sound);
        
        tui_message("\n\x01\x0f Press any key \n", LIGHTCYAN, TUI_BKCOL);
        
        w_unregister_job(j3);
        j3 = NULL;
        snd_speaker(0);
}


void draw_saxana(void) {
        tui_cls_win(mainw, FALSE);
        
        song.duration = SD4;
        song.rest = SR4;
        song.song = s4;
        snd_setsong(&song);
        j3 = w_register_job(6, j3p, &snd_play_sound);
        
        tui_message("\n\x01\x0f Press any key \n", LIGHTCYAN, TUI_BKCOL);
        
        w_unregister_job(j3);
        j3 = NULL;
        snd_speaker(0);
}


void draw_dance(void) {
        tui_cls_win(mainw, FALSE);
        
        song.duration = SD5;
        song.rest = SR5;
        song.song = s5;
        snd_setsong(&song);
        j3 = w_register_job(6, j3p, &snd_play_sound);
        
        tui_message("\n\x01\x0f Press any key \n", LIGHTCYAN, TUI_BKCOL);
        
        w_unregister_job(j3);
        j3 = NULL;
        snd_speaker(0);
}


void draw_cancan(void) {
        tui_cls_win(mainw, FALSE);
        
        song.duration = SD6;
        song.rest = SR6;
        song.song = s6;
        snd_setsong(&song);
        j3 = w_register_job(6, j3p, &snd_play_sound);
        
        tui_message("\n\x01\x0f Press any key \n", LIGHTCYAN, TUI_BKCOL);
        
        w_unregister_job(j3);
        j3 = NULL;
        snd_speaker(0);
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
