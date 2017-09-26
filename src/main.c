/*      main.c
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
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <assert.h>
#include "tui_tc.h"
#include "wait_tc.h"
#include "adli_tc.h"
#include "bnk_file.h"
#include "res_snd.h"


#define TUI_COL LIGHTGRAY
#define TUI_BKCOL BLACK
static WINDOW_T *mainw = NULL;


static int load_instrument(AL_SND_SHAPE *instr, char *bnk_filename, int index);
                

int main(int argc, char **argv) {
        AL_SONG song;
        JOB_T *j1;
        char fname[] = "Standard.bnk";
        AL_SND_SHAPE instr;
        int i, c; 
        
        
        if (argc == 2) {
                i = atoi(argv[1]);
        } else {
                i = 37;
        }
        
        if (al_init(1) != 0) {
                return -1;
        }
                
        load_instrument(&instr, fname, i);
        al_setallch(&instr);
        
        mainw = tui_create_win(1, 1, TUI_SCR_X_SIZE, TUI_SCR_Y_SIZE, TUI_COL, TUI_BKCOL, ' ');
                
        song.duration = SD5;
        song.rest = SR5;
        song.song = s5;
        al_setsong(&song);
                
        j1 = w_register_job(6, 0, &al_play_sound);
        
        c = 0;
        while (c != '3') {
                c = tui_option("1) play Adlib\n2) play Speaker\n3) end", "123",  TUI_COL, TUI_BKCOL);
                
                switch (c) {
                        case '1' :
                                w_unregister_job(j1);
                                song.duration = SD5;
                                song.rest = SR5;
                                song.song = s5;
                                al_setsong(&song);
                                j1 = w_register_job(6, 0, &al_play_sound);
                                break;
                        case '2' :
                                w_unregister_job(j1);
                                song.duration = SD5;
                                song.rest = SR5;
                                song.song = s5;
                                al_setsong(&song);
                                j1 = w_register_job(6, 0, &al_play_sound);
                                break;
                }
        }
        
        w_unregister_job(j1);
        tui_delete_win(mainw);
        return 0;
}


int load_instrument(AL_SND_SHAPE *instr, char *bnk_filename, int index) {
        int result;
        BNK_HDR hdr;
        BNK_INSTR_HDR *n_hdr;
        BNK_INSTR_DATA dta;
        
        result = 0;
        
        /* Read BNK file */
        printf("Reading BNK file\n");
        bnk_read_hdr(&hdr, bnk_filename);
        printf("Version\t%d.%d\n", hdr.verMajor, hdr.verMinor);
        printf("Instruments used\t%d\n", hdr.numUsed);
        printf("Instruments count\t%d\n", hdr.numInstruments);
        
        n_hdr = (BNK_INSTR_HDR *) malloc(sizeof(BNK_INSTR_HDR) * hdr.numInstruments);
        assert(n_hdr != NULL);
        bnk_read_instr_hdr(n_hdr, hdr.numInstruments, bnk_filename, hdr.offsetName);
        
        printf("%d - %s (%d)\n", index, n_hdr[index].name, n_hdr[index].index);
        bnk_read_instr_data(&dta, n_hdr[index].index, bnk_filename, hdr.offsetData);
        free((void *) n_hdr);

        instr->ar0 = dta.oplModulator.attack;
        instr->dr0 = dta.oplModulator.decay;
        instr->sl0 = dta.oplModulator.sustain;
        instr->rr0 = dta.oplModulator.releaseRate;
        instr->ml0 = dta.oplModulator.multiple;
        instr->ks0 = dta.oplModulator.ksl;
        instr->tl0 = dta.oplModulator.totalLevel;
        instr->ws0 = dta.iModWaveSel;
        instr->avek1 = (dta.oplModulator.am << 7) + 
                       (dta.oplModulator.vib << 6) + 
                       (dta.oplModulator.eg << 5) + 
                       (dta.oplModulator.ksr << 4);
        instr->ar1 = dta.oplCarrier.attack;
        instr->dr1 = dta.oplCarrier.decay;
        instr->sl1 = dta.oplCarrier.sustain;
        instr->rr1 = dta.oplCarrier.releaseRate;
        instr->ml1 = dta.oplCarrier.multiple;
        instr->ks1 = dta.oplCarrier.ksl;
        instr->tl1 = dta.oplCarrier.totalLevel;
        instr->ws1 = dta.iCarWaveSel;
        instr->avek1 = (dta.oplCarrier.am << 7) + 
                       (dta.oplCarrier.vib << 6) + 
                       (dta.oplCarrier.eg << 5) + 
                       (dta.oplCarrier.ksr << 4);
        instr->fb = dta.oplModulator.feedback;
        instr->c = dta.oplModulator.con;
        
        return result;
}