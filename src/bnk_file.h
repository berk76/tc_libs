/*
*       bnk_file.h
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

/*
*       See http://www.shikadi.net/moddingwiki/AdLib_Instrument_Bank_Format
*/

#ifndef _BNK_FILE_H_
#define _BNK_FILE_H_


typedef struct {
        unsigned char verMajor;         /* major version number */
        unsigned char verMinor;         /* minor version number */
        unsigned char signature[6];     /* "ADLIB-" */
        unsigned int numUsed;           /* number of instruments in use */
        unsigned int numInstruments;    /* number of instruments in file */
        unsigned long offsetName;       /* offset where instr. names begin */
        unsigned long offsetData;       /* offset where instr. data begin */
        unsigned char pad[8];           /* padded with 0x00 */
} BNK_HDR;


typedef struct {
        unsigned int index;             /* index into data section */
        unsigned char flags;            /* 0 if record is not used else 1 */
        unsigned char name[9];          /* NULL terminated name */
} BNK_INSTR_HDR;


typedef struct {
        unsigned char ksl;              /* key scaling level    reg. 0x40 */
        unsigned char multiple;         /* frequency multiplier reg. 0x20 */
        unsigned char feedback;         /* feedback (op 0 only) reg. 0xc0 */
        unsigned char attack;           /* attack rate          reg. 0x60 */
        unsigned char sustain;          /* sustain level        reg. 0x80 */
        unsigned char eg;               /* envelope gain        reg. 0x20 */
        unsigned char decay;            /* decay rate           reg. 0x60 */
        unsigned char releaseRate;      /* release rate         reg. 0x80 */
        unsigned char totalLevel;       /* total output level   reg. 0x40 */
        unsigned char am;               /* amplitude modulation reg. 0x20 */
        unsigned char vib;              /* frequency vibrato    reg. 0x20 */
        unsigned char ksr;              /* key scal/envelo rate reg. 0x20 */
        unsigned char con;              /* connector (op 0 only)reg. 0xc0 */
} BNK_OPLREGS;


typedef struct {
        unsigned char iPercussive;      /* 0/1 melodic/percussive instrument */
        unsigned char iVoiceNum;        /* voice number (percussive only)  */
        BNK_OPLREGS oplModulator;       /* values for the Modulator (op 0) */
        BNK_OPLREGS oplCarrier;         /* values for the Carrier (op 1) */
        unsigned char iModWaveSel;      /* modulator wave select reg. 0xe0 */
        unsigned char iCarWaveSel;      /* carrier wave select reg. 0xe0 */
} BNK_INSTR_DATA;


extern int bnk_read_hdr(BNK_HDR *h, char *filename);
extern int bnk_read_instr_hdr(BNK_INSTR_HDR *h, int n, char *filename, unsigned long offsetName);
extern int bnk_read_instr_data(BNK_INSTR_DATA *d, int i, char *filename, unsigned long offsetData); 

#endif
