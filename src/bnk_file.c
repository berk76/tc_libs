/*
*       bnk_file.c
*
*       This file is part of Turbo C Libraries.
*       https://github.com/berk76/tc_libs
*       
*       Turbo C Libs is free software; you can redistribute it and/or modify
*       it under the terms of the GNU General Public License as published by
*       the Free Software Foundation; either version 3 of the License, or
*       (at your option) any later version. <http://www.gnu.org/licenses/>
*       
*       Written by Jaroslav Beran <jaroslav.beran@gmail.com>, on 28.8.2017        
*/


#include <stdio.h>
#include <assert.h>
#include "bnk_file.h"


int bnk_read_hdr(BNK_HDR *h, char *filename) {
        FILE *f;
        
        assert(h != NULL);
        f = fopen(filename, "rb");
        assert(f != NULL);
        fread(h, sizeof(BNK_HDR), 1, f);
        fclose(f);
        return 0;
}


int bnk_read_instr_hdr(BNK_INSTR_HDR *h, int n, char *filename, unsigned long offsetName) {
        FILE *f;
        
        assert(h != NULL);
        f = fopen(filename, "rb");
        assert(f != NULL);
        fseek(f, offsetName, SEEK_SET);
        fread(h, sizeof(BNK_INSTR_HDR), n, f);
        fclose(f);
        return 0;
}


int bnk_read_instr_data(BNK_INSTR_DATA *d, int i, char *filename, unsigned long offsetData) {
        FILE *f;
        
        assert(d != NULL);
        f = fopen(filename, "rb");
        assert(f != NULL);
        fseek(f, offsetData + sizeof(BNK_INSTR_DATA) * i, SEEK_SET);
        fread(d, sizeof(BNK_INSTR_DATA), 1, f);
        fclose(f);
        return 0;
}
