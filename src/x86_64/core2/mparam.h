/* Various Thresholds of MPFR, not exported.  -*- mode: C -*-

Copyright 2005-2020 Free Software Foundation, Inc.

This file is part of the GNU MPFR Library.

The GNU MPFR Library is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or (at your
option) any later version.

The GNU MPFR Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
License for more details.

You should have received a copy of the GNU Lesser General Public License
along with the GNU MPFR Library; see the file COPYING.LESSER.  If not, see
https://www.gnu.org/licenses/ or write to the Free Software Foundation, Inc.,
51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA. */

/* Generated by MPFR's tuneup.c, 2011-07-31, gcc 4.3.2 */
/* gcc14.fsffrance.org (Intel(R) Xeon(R) CPU X5450 @ 3.00GHz) with gmp 5.0.2 */

/* very similar timings were obtained on 2012-01-25 with gcc 4.1.3
   on gcc70.fsffrance.org (Intel(R) Xeon(TM) CPU 3.20GHz) with gmp 5.0.2,
   where GMP defines -mtune=nocona, thus we share the parameters */

#define MPFR_MULHIGH_TAB  \
 -1,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,9, \
 10,10,12,12,13,13,13,13,14,16,16,17,18,19,20,24, \
 24,24,24,24,26,26,26,26,28,28,28,30,30,32,32,28, \
 28,30,30,32,32,32,32,32,32,32,32,34,36,48,38,36, \
 40,46,48,48,48,48,48,48,48,48,48,48,48,56,56,56, \
 56,48,48,48,56,60,60,60,64,64,56,56,56,60,60,60, \
 64,69,64,64,64,69,69,69,69,69,69,69,64,64,75,81, \
 81,80,80,80,81,81,81,81,81,81,87,81,87,87,92,93, \
 92,87,93,92,87,90,93,92,93,92,90,93,92,93,92,93, \
 92,93,93,93,104,93,99,93,99,104,105,104,105,104,105,104, \
 111,104,111,110,104,117,117,117,117,117,117,104,105,141,141,140, \
 141,141,141,141,141,141,141,141,141,141,141,141,141,140,141,141, \
 141,141,141,141,141,141,141,141,140,141,141,141,141,138,140,141, \
 141,141,140,141,141,141,141,141,141,141,141,141,165,141,153,141, \
 153,165,188,188,188,188,188,188,188,188,188,188,188,188,188,188, \
 188,188,188,188,188,188,188,188,188,188,188,188,188,188,188,188, \
 188,188,188,188,188,188,188,188,188,188,188,188,188,188,188,188, \
 188,188,204,204,188,203,188,188,204,204,188,188,216,220,220,220, \
 220,204,204,220,220,220,220,220,220,220,220,220,220,220,220,220, \
 220,220,220,235,236,219,220,220,236,236,236,236,236,236,236,236, \
 236,236,236,236,236,236,236,282,282,282,282,282,282,282,282,282, \
 282,282,282,282,282,282,282,282,282,281,282,280,282,282,282,282, \
 282,282,282,282,282,282,282,281,281,282,281,281,282,282,282,282, \
 282,282,282,282,282,282,282,282,282,282,282,281,282,280,281,282, \
 282,282,282,282,306,282,306,330,330,306,281,330,282,282,330,330, \
 330,282,330,329,330,330,330,330,330,330,330,330,330,330,330,330, \
 330,330,330,330,330,330,330,330,330,330,354,354,330,330,330,329, \
 330,330,330,330,330,330,330,329,330,330,354,354,330,330,330,330, \
 330,330,378,330,354,330,354,354,354,354,354,377,378,354,354,354, \
 378,354,378,378,354,353,354,378,354,378,378,377,378,378,378,408, \
 408,408,378,408,408,408,378,416,408,408,377,378,378,408,408,407, \
 408,408,408,408,408,408,408,440,408,440,440,440,439,440,440,440, \
 432,439,440,440,440,439,440,440,440,439,440,439,440,439,440,440, \
 440,440,440,439,440,440,440,440,440,439,440,440,440,440,439,440, \
 440,440,440,439,471,440,440,440,440,440,440,439,440,440,440,440, \
 440,440,440,440,440,440,472,440,440,439,440,440,440,439,440,440, \
 440,472,439,440,440,440,472,440,471,472,472,472,472,472,472,471, \
 471,472,471,472,472,472,504,504,504,504,504,504,504,504,472,471, \
 472,472,504,472,471,472,504,504,504,504,504,503,504,504,504,504, \
 504,503,504,504,504,504,503,504,504,504,504,504,503,504,504,504, \
 504,504,503,504,504,504,504,504,504,504,504,504,504,504,504,504, \
 504,504,504,504,544,544,544,544,544,544,544,544,544,544,544,544, \
 542,543,544,544,544,544,544,544,544,544,544,544,544,544,544,544, \
 543,544,544,544,544,544,544,544,544,544,544,544,544,544,544,544, \
 544,592,544,544,592,592,544,592,592,591,592,592,632,631,592,592, \
 592,592,592,592,592,640,640,640,640,640,616,616,616,616,616,616, \
 632,592,616,616,632,630,631,632,632,632,616,632,640,632,632,640, \
 640,640,640,640,640,640,639,640,632,632,639,640,640,640,632,632, \
 640,639,640,640,632,640,640,640,640,640,640,640,640,640,640,640, \
 640,640,640,640,640,640,632,640,640,640,640,640,640,640,640,640, \
 640,640,640,640,640,640,640,640,640,640,632,688,640,640,632,632, \
 640,640,640,640,639,640,640,640,688,632,687,640,712,688,640,640, \
 640,640,640,712,640,640,640,712,736,640,640,640,711,712,736,736, \
 640,640,688,712,712,712,712,712,728,736,728,728,736,736,736,736, \
 736,736,736,736,734,736,728,736,736,736,728,736,736,736,736,736, \
 736,736,736,736,735,712,736,736,736,712,736,736,736,736,736,736, \
 736,736,736,712,736,736,712,736,728,712,736,712,736,736,736,736, \
 728,712,736,736,735,736,736,736,735,736,736,736,736,735,736,736, \
 736,736,736,736,736,736,736,736,736,736,736,736,736,734,736,736, \
 736,736,735,736,736,736,735,736,736,736,736,736,736,736,736,736, \
 736,736,736,736,736,736,736,736,736,736,736,736,736,736,736,736, \
 736,736,736,736,736,736,736,736,736,736,736,736,736,736,735,736, \
 736,736,736,736,736,736,736,736,736,736,736,736,736,736,736,736, \
 824,824,832,832,832,832,824,832,832,832,832,832,824,831,832,832 \

#define MPFR_SQRHIGH_TAB  \
 -1,0,0,0,0,0,0,5,6,6,7,8,8,8,10,9, \
 10,11,11,11,12,13,13,13,14,16,16,17,17,17,17,17, \
 18,19,20,21,20,23,24,21,26,23,23,24,24,24,25,28, \
 26,28,28,34,32,34,32,32,34,34,32,34,34,34,34,34, \
 34,36,40,38,38,36,42,42,40,40,40,40,42,42,42,42, \
 46,42,48,48,48,46,52,52,52,52,52,52,56,56,56,56, \
 64,56,64,64,64,64,68,56,64,64,64,68,63,64,64,68, \
 68,68,68,68,64,68,68,68,72,64,68,68,68,64,67,68, \
 68,68,68,68,68,68,72,84,80,72,72,72,72,72,76,76, \
 76,76,80,80,76,76,80,84,80,80,80,84,84,84,84,84, \
 84,84,84,96,84,84,92,92,96,96,96,99,92,92,92,95, \
 96,105,111,105,104,105,104,104,105,105,105,105,104,105,104,105, \
 99,114,105,116,117,117,117,123,117,123,116,123,116,111,123,123, \
 123,123,123,123,123,117,117,117,123,123,123,117,123,117,123,123, \
 123,123,123,123,117,123,123,123,156,123,123,141,123,123,135,135, \
 123,148,123,141,141,156,156,129,156,163,156,164,156,156,156,135, \
 156,141,155,164,156,156,164,148,148,147,141,164,164,164,164,156, \
 164,164,164,164,163,164,164,164,164,164,164,164,164,164,164,164, \
 164,156,164,164,156,164,164,164,188,163,164,164,164,164,187,188, \
 180,164,204,204,164,188,196,188,188,204,196,180,196,204,188,196, \
 220,187,204,220,204,180,220,220,204,204,196,204,220,204,220,220, \
 220,220,204,220,220,220,220,220,220,220,220,220,220,220,220,220, \
 252,220,220,220,220,220,252,220,252,220,220,220,220,252,252,252, \
 252,252,252,252,252,252,252,252,252,252,252,252,267,268,252,252, \
 252,250,252,252,252,268,251,252,268,252,268,268,268,252,252,252, \
 265,268,268,268,268,268,268,268,268,268,268,268,268,268,268,268, \
 268,267,268,268,268,267,268,268,268,267,268,268,268,268,268,268, \
 268,268,252,268,252,268,268,268,268,268,268,265,268,268,268,268, \
 268,268,268,268,268,268,268,268,268,268,268,268,265,268,268,268, \
 252,268,268,266,268,268,268,328,265,282,312,268,268,268,268,268, \
 268,268,268,268,268,268,268,311,310,282,282,294,312,282,281,294, \
 282,268,312,312,268,311,312,268,268,312,268,312,312,268,312,327, \
 268,312,328,268,328,268,328,328,328,312,328,312,327,328,328,312, \
 327,328,328,327,325,327,327,359,328,328,327,328,328,328,328,328, \
 311,328,360,360,360,360,360,360,360,360,360,360,328,360,360,360, \
 328,312,328,360,327,328,328,359,360,328,359,328,312,360,360,327, \
 312,408,328,440,328,328,328,328,328,392,328,328,408,408,408,392, \
 407,408,408,408,392,407,408,408,407,407,408,408,408,392,408,408, \
 407,408,392,408,408,440,406,408,408,408,440,408,408,408,440,440, \
 440,440,440,392,440,392,440,440,440,440,440,440,440,440,440,440, \
 408,392,440,440,440,438,439,440,440,440,440,440,440,439,440,439, \
 440,440,440,504,408,504,408,408,408,472,408,408,407,408,440,439, \
 439,440,440,440,440,440,440,440,437,440,440,440,439,504,503,504, \
 504,503,504,504,440,502,504,503,503,504,504,503,504,504,504,504, \
 504,503,504,504,499,503,502,504,504,536,502,504,504,504,536,504, \
 504,504,503,504,504,503,536,504,502,536,503,504,504,504,536,536, \
 504,504,504,536,536,535,504,536,535,504,504,504,504,504,504,536, \
 536,536,503,536,504,503,536,536,504,535,536,536,504,535,520,536, \
 504,504,504,536,535,536,520,536,535,520,536,535,535,536,536,535, \
 504,536,536,535,536,535,535,536,536,536,536,536,535,504,536,536, \
 536,536,536,536,536,536,536,536,536,535,536,536,536,535,504,536, \
 536,536,536,536,504,535,536,536,536,535,535,536,536,536,536,536, \
 536,535,536,504,536,535,536,536,536,536,536,504,504,536,504,535, \
 536,504,536,535,536,504,504,504,536,536,504,536,504,536,504,536, \
 536,504,535,536,632,535,536,536,535,536,536,536,536,536,632,632, \
 536,631,536,536,535,536,536,536,536,535,536,536,536,631,632,632, \
 536,536,630,535,536,536,600,632,631,600,536,536,536,536,535,632, \
 536,598,536,600,536,631,600,568,632,568,568,568,568,568,664,566, \
 568,568,632,632,664,568,664,663,632,629,632,535,600,536,536,536, \
 632,536,536,599,536,630,536,632,631,632,600,600,600,664,600,664, \
 664,632,600,599,664,600,662,663,664,599,598,616,632,625,632,630, \
 628,627,630,631,632,663,632,631,632,630,632,631,632,626,632,632, \
 632,663,631,631,632,632,632,664,632,632,600,632,632,600,632,632, \
 600,600,632,632,632,662,663,663,663,600,664,632,664,663,664,632 \

#define MPFR_DIVHIGH_TAB  \
 0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,13, \
 14,15,16,13,14,14,14,15,15,17,17,17,19,19,19,19, \
 23,23,19,25,23,25,23,25,25,22,26,28,25,28,25,25, \
 28,27,31,27,29,28,33,31,32,33,31,32,33,33,35,35, \
 35,39,37,43,39,37,39,41,39,40,39,40,41,45,41,47, \
 45,45,47,43,44,45,50,54,49,46,53,47,55,56,52,55, \
 52,60,60,52,60,64,62,55,55,62,55,58,56,64,61,59, \
 63,63,64,59,60,60,63,64,64,63,64,64,68,68,66,66, \
 68,69,71,71,70,71,71,72,78,74,74,71,72,78,78,74, \
 76,77,78,79,78,80,79,79,84,83,80,80,82,95,96,83, \
 92,92,88,91,92,84,95,95,92,96,94,91,94,92,96,94, \
 96,96,96,104,94,94,112,112,104,112,112,112,96,112,112,112, \
 112,112,110,104,112,112,112,111,112,108,110,120,112,112,112,112, \
 112,112,120,112,120,120,112,120,120,120,120,120,128,120,120,116, \
 128,128,124,128,120,128,128,120,120,120,128,120,128,120,124,128, \
 128,128,128,127,128,128,126,128,128,128,128,127,136,128,138,137, \
 137,135,138,138,138,137,135,138,150,150,138,147,150,138,150,150, \
 150,150,160,160,156,150,156,148,150,158,162,160,161,160,150,160, \
 160,160,168,156,156,160,168,173,162,156,180,160,160,157,168,160, \
 160,160,162,168,168,160,184,162,184,162,160,160,174,160,184,180, \
 184,184,180,184,184,186,180,184,184,184,184,184,186,188,188,192, \
 185,184,184,186,192,192,192,186,182,192,192,185,184,184,192,208, \
 192,184,184,180,192,184,192,186,186,184,192,186,186,191,186,185, \
 192,216,192,192,208,192,191,192,192,192,204,192,207,192,216,208, \
 208,216,216,197,196,216,216,208,216,222,216,222,208,222,208,222, \
 224,208,209,216,216,209,224,207,216,222,224,224,208,223,224,224, \
 224,216,222,222,224,224,224,216,224,216,222,221,222,224,224,224, \
 224,224,224,232,224,222,224,232,225,233,224,240,224,232,256,240, \
 256,256,240,255,240,256,256,240,232,240,232,232,240,232,256,256, \
 256,256,256,256,256,256,255,256,256,240,256,240,256,240,254,252, \
 256,256,256,256,256,256,256,256,254,256,256,282,276,256,254,256, \
 256,255,282,256,255,256,255,256,255,288,256,264,264,256,274,276, \
 276,269,273,273,282,269,276,276,276,276,273,282,276,282,276,277, \
 280,312,282,281,288,282,276,282,276,276,288,312,276,288,300,276, \
 304,276,288,300,304,312,312,312,312,312,306,312,312,312,316,300, \
 324,312,320,320,300,312,312,312,312,324,312,330,300,320,312,312, \
 316,318,324,324,318,312,312,324,336,336,324,312,312,336,324,320, \
 312,336,312,324,336,336,336,368,324,348,312,336,368,312,312,320, \
 368,372,368,312,324,376,372,312,368,376,376,372,370,372,318,376, \
 320,372,372,368,372,324,376,376,376,376,368,372,376,376,376,376, \
 372,372,376,376,376,372,384,376,372,368,384,376,376,370,376,376, \
 376,371,372,368,384,336,370,370,376,372,376,376,368,376,376,372, \
 376,370,376,368,376,372,376,376,368,376,376,368,368,376,368,368, \
 370,370,372,368,372,376,376,376,376,368,370,368,368,372,376,376, \
 372,376,368,376,376,376,372,376,376,372,376,376,368,376,372,376, \
 372,368,376,370,376,372,376,372,376,376,372,370,376,376,370,372, \
 372,373,376,376,384,384,384,376,376,376,376,384,376,376,384,384, \
 384,416,384,384,408,384,416,384,384,384,384,408,416,416,416,432, \
 408,408,416,408,408,416,408,416,416,416,416,416,416,408,407,440, \
 432,408,416,408,416,440,416,408,416,416,432,416,416,440,416,416, \
 416,440,432,440,408,448,448,408,408,432,440,432,448,416,416,416, \
 440,432,432,416,448,432,465,440,432,440,480,448,416,448,432,432, \
 480,432,448,440,466,448,432,440,432,440,440,440,480,430,448,448, \
 448,439,440,432,438,447,448,440,440,440,448,448,480,432,448,448, \
 448,448,448,447,448,448,448,447,448,448,440,465,448,467,448,448, \
 448,448,464,464,448,448,466,480,480,480,468,480,448,464,480,464, \
 466,466,464,479,480,480,512,480,540,480,496,480,552,512,480,479, \
 504,480,552,552,512,480,504,552,564,512,480,480,504,561,564,564, \
 512,552,560,564,564,480,564,480,552,480,564,564,564,564,536,564, \
 540,564,552,564,564,564,564,552,564,552,564,480,564,552,552,564, \
 512,564,546,564,564,564,512,552,552,559,560,561,564,564,560,560, \
 552,561,564,564,560,564,561,564,564,564,564,564,564,564,564,560, \
 561,560,564,564,560,564,564,552,564,564,564,552,564,564,564,564, \
 564,563,564,564,564,564,560,564,564,564,564,552,564,564,560,564 \

#define MPFR_MUL_THRESHOLD 7 /* limbs */
#define MPFR_SQR_THRESHOLD 12 /* limbs */
#define MPFR_DIV_THRESHOLD 20 /* limbs */
#define MPFR_EXP_2_THRESHOLD 1024 /* bits */
#define MPFR_EXP_THRESHOLD 9670 /* bits */
#define MPFR_SINCOS_THRESHOLD 23808 /* bits */
#define MPFR_AI_THRESHOLD1 -13250 /* threshold for negative input of mpfr_ai */
#define MPFR_AI_THRESHOLD2 1430
#define MPFR_AI_THRESHOLD3 21190
/* Tuneup completed successfully, took 770 seconds */
