/*
*       adli_tc.c
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

/*

Ports
=====

The sound card is programmed by sending data to its internal registers via 
its two I/O ports:

    0388 (hex) - Address/Status port (R/W)
    0389 (hex) - Data port (W/O)

After writing to the register port, you must wait twelve cycles before sending 
the data; 

Wait after update
=================

After writing the data, eighty-four cycles must elapse before any other sound 
card operation may be performed.

The AdLib manual gives the wait times in microseconds: 
        three point three (3.3) microseconds for the address, 
        and twenty-three (23) microseconds for the data.
        
AdLib suggested that the delays be produced by reading the register port 
      * six times after writing to the register port, and 
      * reading the register port thirty-five times after writing to the data 
        port.   

Reading status
==============

The sound card registers are write-only.
The address port also functions as a sound card status byte. 

To retrieve the sound card's status, simply read port 388. 
The status byte has the following structure:

        Bit 7 - 	set if either timer has expired.
        Bit 6 - 	set if timer 1 has expired.
        Bit 5 - 	set if timer 2 has expired.
        Rest is unused
        
The Registers
=============

Address	Function
01	Test LSI / Enable waveform control
02	Timer 1 data
03	Timer 2 data
04	Timer control flags
08	Speech synthesis mode / Keyboard split note select
20..35	Amp Mod / Vibrato / EG type / Key Scaling / Multiple
40..55	Key scaling level / Operator output level
60..75	Attack Rate / Decay Rate
80..95	Sustain Level / Release Rate
A0..A8	Frequency (low 8 bits)
B0..B8	Key On / Octave / Frequency (high 2 bits)
BD	AM depth / Vibrato depth / Rhythm control
C0..C8	Feedback strength / Connection type
E0..F5	Wave Select

The groupings of twenty-two registers (20-35, 40-55, etc.) have an odd order 
due to the use of two operators for each FM voice. The following table shows 
the offsets within each group of registers for each operator.

Channel	       1      2      3      4      5      6      7      8      9
Operator 1    00     01     02     08     09     0A     10     11     12
Operator 2    03     04     05     0B     0C     0D     13     14     15

Thus, the addresses of the attack/decay bytes for channel 3 are 62 for 
the first operator, and 65 for the second. (The address of the second operator 
is always the address of the first operator plus three).


To further illustrate the relationship, the addresses needed to control 
channel 5 are:

    29	Operator 1	AM/VIB/EG/KSR/Multiplier
    2C	Operator 2	AM/VIB/EG/KSR/Multiplier
    49	Operator 1	KSL/Output Level
    4C	Operator 2	KSL/Output Level
    69	Operator 1	Attack/Decay
    6C	Operator 2	Attack/Decay
    89	Operator 1	Sustain/Release
    8C	Operator 2	Sustain/Release
    A4	  		Frequency (low 8 bits)
    B4	  		Key On/Octave/Frequency (high 2 bits)
    C4	  		Feedback/Connection Type
    E9	Operator 1	Waveform
    EC	Operator 2	Waveform

Explanations of Registers
=========================

Byte 01
------- 	
This byte is normally used to test the LSI device. All bits should normally 
be zero. Bit 5, if enabled, allows the FM chips to control the waveform of 
each operator.

7 	6 	5 	4 	3 	2 	1 	0
unused         WS 	unused

Byte 02
-------
Timer 1 Data. If Timer 1 is enabled, the value in this register will be 
incremented until it overflows. Upon overflow, the sound card will signal 
a TIMER interrupt (INT 08) and set bits 7 and 6 in its status byte. The value 
for this timer is incremented every eighty (80) microseconds.

Byte 03
-------
Timer 2 Data. If Timer 2 is enabled, the value in this register will be 
incremented until it overflows. Upon overflow, the sound card will signal 
a TIMER interrupt (INT 08) and set bits 7 and 5 in its status byte. The value 
for this timer is incremented every three hundred twenty (320) microseconds.

Byte 04 
-------
Timer Control Byte

bit 7 - Resets the flags for timers 1 & 2. If set, all other bits are ignored.
bit 6 - Masks Timer 1. If set, bit 0 is ignored.
bit 5 - Masks Timer 2. If set, bit 1 is ignored.
bit 1 - When clear, Timer 2 does not operate. When set, the value from byte 03 
        is loaded into Timer 2, and incrementation begins.
bit 0 - When clear, Timer 1 does not operate. When set, the value from byte 02 
        is loaded into Timer 1, and incrementation begins.

Byte 08
------- 
CSM Mode / Keyboard Split.

bit 7 - When set, selects composite sine-wave speech synthesis mode (all KEY-ON 
        bits must be clear). When clear, selects FM music mode.
bit 6 - Selects the keyboard split point (in conjunction with the F-Number 
        data). The documentation in the Sound Blaster manual is utterly 
        incomprehensible on this; I can't reproduce it without violating their 
        copyright. 

Bytes 20-35
-----------
Amplitude Modulation / Vibrato / Envelope Generator Type / 
Keyboard Scaling Rate / Modulator Frequency Multiple

bit 7 - Apply amplitude modulation when set; AM depth is controlled by the 
        AM-Depth flag in address BD.
bit 6 - Apply vibrato when set; vibrato depth is controlled by the Vib-Depth 
        flag in address BD.
bit 5 - When set, the sustain level of the voice is maintained until released; 
        when clear, the sound begins to decay immediately after hitting 
        the SUSTAIN phase.
bit 4 - Keyboard scaling rate. This is another incomprehensible bit in 
        the Sound Blaster manual. From experience, if this bit is set, 
        the sound's envelope is foreshortened as it rises in pitch.
bits 3-0 - These bits indicate which harmonic the operator will produce sound 
           (or modulation) in relation to the voice's specified frequency:
           
                0 - one octave below
                1 - at the voice's specified frequency
                2 - one octave above
                3 - an octave and a fifth above
                4 - two octaves above
                5 - two octaves and a major third above
                6 - two octaves and a fifth above
                7 - two octaves and a minor seventh above
                8 - three octaves above
                9 - three octaves and a major second above
                A - three octaves and a major third above
                B - three octaves and a major third above
                C - three octaves and a fifth above
                D - three octaves and a fifth above
                E - three octaves and a major seventh above
                F - three octaves and a major seventh above

Bytes 40-55
----------- 
Level Key Scaling / Total Level

7       6       5       4       3       2       1       0
Scaling        24      12       6       3     1.5     .75
Level 	       dB      dB      dB      dB      dB      dB

        bits 7-6 - causes output levels to decrease as the frequency rises:
                00 - no change
                10 - 1.5 dB/8ve
                01 - 3 dB/8ve
                11 - 6 dB/8ve
        bits 5-0 - controls the total output level of the operator. All bits 
                CLEAR is loudest; all bits SET is the softest. Don't ask me why.

Bytes 60-75
----------- 
Attack Rate / Decay Rate

        bits 7-4 - Attack rate. 0 is the slowest, F is the fastest.
        bits 3-0 - Decay rate. 0 is the slowest, F is the fastest. 

Bytes 80-95
----------- 
Sustain Level / Release Rate

        bits 7-4 - Sustain Level. 0 is the loudest, F is the softest.
         	Bit 7 -	24 dB
         	Bit 6 -	12 dB
         	Bit 5 -	6 dB
         	Bit 4 -	3 dB
        bits 3-0 - Release rate. 0 is the slowest, F is the fastest. 

Bytes A0-B8
----------- 
Octave / F-Number / Key-On


7 	6 	5 	4 	3 	2 	1 	0
F-Number (least significant byte)
(A0-A8)


7 	6 	5 	4 	3 	2 	1 	0
Unused 	        Key On 	Octave 	                F-Number most sig.
(B0-B8)

        bit 5 - Channel is voiced when set, silent when clear.
        bits 4-2 - Octave (0-7). 0 is lowest, 7 is highest.
        bits 1-0 - Most significant bits of F-number.
        
In octave 4, the F-number values for the chromatic scale and their 
corresponding frequencies would be:

F Number        Frequency (decimal)     Note
16B             277.2                   C#
181             293.7                   D
198             311.1                   D#
1B0             329.6                   E
1CA             349.2                   F
1E5             370.0                   F#
202             392.0                   G
220             415.3                   G#
241             440.0                   A
263             466.2                   A#
287             493.9                   B
2AE             523.3                   C

Bytes C0-C8
----------- 
Feedback / Algorithm

bits 3-1 - Feedback strength. If all three bits are set to zero, no feedback 
           is present. With values 1-7, operator 1 will send a portion of its 
           output back into itself. 1 is the least amount of feedback, 7 is 
           the most.
bit  0   - If set to 0, operator 1 modulates operator 2. In this case, operator 
           2 is the only one producing sound. If set to 1, both operators 
           produce sound directly. Complex sounds are more easily created if 
           the algorithm is set to 0.

Byte BD
-------
Amplitude Modulation Depth / Vibrato Depth / Rhythm

bit 7 - Set: AM depth is 4.8 dB
        Clear: AM depth is 1 dB
bit 6 - Set: Vibrato depth is 14 cent
        Clear: Vibrato depth is 7 cent
bit 5 -	Set: Rhythm enabled (6 melodic voices)
        Clear: Rhythm disabled (9 melodic voices)
bit 4 - Bass drum on/off
bit 3 - Snare drum on/off
bit 2 - Tom tom on/off
bit 1 - Cymbal on/off
bit 0 - Hi Hat on/off
 
Note: 	KEY-ON registers for channels 06, 07, and 08 must be OFF in order to 
        use the rhythm section. Other parameters such as attack/decay/sustain
        /release must also be set appropriately.            

Bytes E0-F5
-----------
Waveform Select

00 - 2PI
01 - PI
10 - ABS(2PI)
11 - ABS(2PI) (quoter-wave)


*/

#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adli_tc.h"


#define SB_ENV "BLASTER"


/* adlib default ports */
static unsigned int addr_port = 0x0388;
static unsigned int data_port = 0x0389;


/* instruments */
static AL_SND_SHAPE al_shape_1[] = 
        {{5, 2, 1, 0, 0, 0, 13, 0, 0, 11, 4, 4, 6, 0, 2, 0, 0, 0, 0, 0},
         {8, 1, 1, 1, 1, 2, 4, 1, 13, 15, 2, 1, 3, 0, 0, 0, 0, 0, 0, 1},
         {15, 3, 2, 3, 0, 0, 0, 0, 0, 15, 4, 2, 5, 0, 0, 0, 0, 0, 0, 1},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 2, 3, 5, 0, 2, 0, 0, 0, 0, 0},
         {15, 4, 6, 3, 1, 1, 0, 3, 0, 15, 3, 3, 5, 0, 2, 0, 1, 0, 0, 0},
         {15, 11, 7, 0, 2, 3, 0, 1, 14, 15, 3, 6, 4, 0, 1, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 2, 3, 5, 0, 2, 0, 0, 0, 0, 0}
         };

/* Song for play */           
static AL_SONG *song = NULL;

/* Active channel */           
static int achannel = 0;

static int al_test_al(void);
static unsigned char adlibjam(unsigned char c);
static void soundport(char index, char value);
static void al_play(unsigned channel, unsigned octave, unsigned freq);


/*
*  External functions
*/


int al_init(int verbose) {
        char *p;
        
        /* search for Adlib */
        if (al_test_al() == 0) {
                if (verbose) {
                        printf("%s\n", "Adlib sound card found.");
                        printf("addr port is 0x%x \n", addr_port);
                        printf("data port is 0x%x \n", data_port);
                }
                return 0;
        }
        
        /* search for SoundBlaster */
        p = getenv(SB_ENV);
        if (p == NULL) {
                if (verbose) {
                        printf("%s\n", "Sound card was not found.");
                        printf("%s %s\n", "Please set variable ", SB_ENV);
                }
                return -1;
        }
        
        p = strchr(p, 'A');
        if (p == NULL) {
                if (verbose) {
                        printf("%s\n", "Sound card was not found.");
                        printf("Please set Axxx in %s \n", SB_ENV);
                }
                return -1;
        }
        
        sscanf(p, "A%x", &addr_port);
        data_port = addr_port + 1; 
        if (verbose) {
                printf("%s\n", "Sound card found.");
                printf("addr port is 0x%x \n", addr_port);
                printf("data port is 0x%x \n", data_port);
        }
        
        al_setallch(al_getinstr(0));
        
        return 0;
}


AL_SND_SHAPE *al_getinstr(int i) {
        if (i < 7) {
                return &(al_shape_1[i]);
        } else {
                return &(al_shape_1[0]);
        }
}


void al_setonech(unsigned char ch, AL_SND_SHAPE *s) {
        soundport(0xc0 + ch, (s->fb << 1) + s->c);

        ch = adlibjam(ch);

        soundport(0x60 + ch, (s->ar0 << 4) + s->dr0);
        soundport(0x80 + ch, (s->sl0 << 4) + s->rr0);
        soundport(0x20 + ch, (s->avek0 << 4) + s->ml0);
        soundport(0x40 + ch, (s->ks0 << 6) + s->tl0);
        soundport(0xE0 + ch, s->ws0);

        ch += 3;

        soundport(0x60 + ch, (s->ar1 << 4) + s->dr1);
        soundport(0x80 + ch, (s->sl1 << 4) + s->rr1);
        soundport(0x20 + ch, (s->avek1 << 4) + s->ml1);
        soundport(0x40 + ch, (s->ks1 << 6) + s->tl1);
        soundport(0xE0 + ch, s->ws1);
}


void al_setallch(AL_SND_SHAPE *s) {
        int i;
        for(i = 0; i < 9; i++) {	
                al_setonech(i, s);
        }
}


void al_playnote(enum AL_NOTE n, enum AL_OCTAVE o, enum AL_CHANNEL c) {
        if ((n == REST) || (n == REPEAT)) {
                al_play(c, 0, 0);
        } else {
                if (n == C) {
                        if (o == 0) {
                                n = 0;
                        } else {
                                o--;
                        }
                }
                al_play(c, o, n);
        }
}


void al_setsong(AL_SONG *s) {
        song = s;
        al_play_sound(RESET);
}


long al_play_sound(enum W_ACTION a) {
        long i;
        static int pause = 0;
        static AL_PLAY_NOTE *p = NULL;
        static paused = 0;
        
        if (song == NULL)
                return 0;
                                        
        if (a == RESET) {
                p = song->song;
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
                        
                if (p == NULL) {
                        p = song->song;
                }
                        
                if (pause == 0) {
                        achannel++;
                        if (achannel > 2)
                                achannel = 0;
                        
                        al_playnote(p->note, p->octave, achannel);
                        i = p->duration;
                        switch (p->note) {
                                case REPEAT:
                                        p = song->song;
                                        break;
                                case STOP:
                                        /* unregister job */
                                        return -1;
                                default:
                                        p++;
                        }
                        pause = 1;
                } else {
                        al_playnote(REST, O1, achannel);
                        pause = 0;
                }

                return (pause == 1) ? w_mstotck(song->duration*i) : w_mstotck(song->rest);
        }
        
        return 0;
}

/*
*  Static functions
*/

int al_test_al(void) {
        unsigned char i, r1, r2;
        /* 1. Reset T1 and T2: write 60h to register 4. */
        soundport(0x04, 0x60);
        /* 2. Reset the IRQ: write 80h to register 4. */
        soundport(0x04, 0x80);
        /* 3. Read status register: read at 388h. Save the result. */
        r1 = inportb(addr_port);
        /* 4. Set timer 1 to FFh: write FFh to register 2. */
        soundport(0x02, 0xff);
        /* 5. Unmask and start timer 1: write 21h to register 4. */
        soundport(0x04, 0x21);
        /* 6. Wait in a delay loop for at least 80 µsec. */
        for (i = 0; i < 80; i++)
                inportb(addr_port);
        /* 7. Read status register: read at 388h. Save the result. */
        r2 = inportb(addr_port);
        /* 8. Reset T1,T2 and IRQ as in steps 1 and 2. */
        soundport(0x04, 0x60);
        soundport(0x04, 0x80);
        /* 9. Test the results of the two reads: the first should
              be 0, the second should be C0h. If either is incorrect,
              then the ALMSC is not presents.
              
              NOTE1: You should AND the result bytes with E0h because
              the unused bits are undefined.
              NOTE2: This testing method doesn't work in SoundBlaster. 
        */
        if ((r1 & 0xe0) != 0x00)
                return -1;
        if ((r2 & 0xe0) != 0xc0)
                return -1;
        
        return 0;
}


void al_play(unsigned channel, unsigned octave, unsigned freq) {
        soundport(0xB0 + channel, 0);
        soundport(0xA0 + channel, freq & 255);
        soundport(0xB0 + channel, 0x20 + (octave << 2) + (freq >> 8));
}


unsigned char adlibjam(unsigned char c) {
        if (c < 3) return c;
        if(c < 6) return 5 + c;
        return 10 + c;
}


/*  
        Dont have ASM compiler :-(
        
void soundport(char index, char value)
{       asm{
                mov             dx, 0388h
                mov             al, index
                out             dx, al

                mov             cx, 6
        }
        loop1:
        asm{
                in              al, dx
                loop    loop1

                inc             dx

                mov             al, value
                out             dx, al

                mov             cx, 36
                dec     dx
        }
        loop2:
        asm{
                in              al, dx
                loop    loop2
        }
}
*/


void soundport(char index, char value) {
        int i;
        
        outportb(addr_port, index);
        for (i = 0; i < 6; i++)
                inportb(addr_port);
                
        outportb(data_port, value);
        for (i = 0; i < 36; i++)
                inportb(addr_port);
}
