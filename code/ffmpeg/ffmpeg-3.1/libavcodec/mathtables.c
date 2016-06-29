﻿/*
 * Copyright (c) 2002-2004 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include <stdint.h>

#include "mathops.h"

/* a*inverse[b]>>32 == a/b for all 0<=a<=16909558 && 2<=b<=256
 * for a>16909558, is an overestimate by less than 1 part in 1<<24 */
const uint32_t ff_inverse[257]=
{
    0, 4294967295U,2147483648U,1431655766, 1073741824,  858993460,  715827883,  613566757,
    536870912,  477218589,  429496730,  390451573,  357913942,  330382100,  306783379,  286331154,
    268435456,  252645136,  238609295,  226050911,  214748365,  204522253,  195225787,  186737709,
    178956971,  171798692,  165191050,  159072863,  153391690,  148102321,  143165577,  138547333,
    134217728,  130150525,  126322568,  122713352,  119304648,  116080198,  113025456,  110127367,
    107374183,  104755300,  102261127,   99882961,   97612894,   95443718,   93368855,   91382283,
    89478486,   87652394,   85899346,   84215046,   82595525,   81037119,   79536432,   78090315,
    76695845,   75350304,   74051161,   72796056,   71582789,   70409300,   69273667,   68174085,
    67108864,   66076420,   65075263,   64103990,   63161284,   62245903,   61356676,   60492498,
    59652324,   58835169,   58040099,   57266231,   56512728,   55778797,   55063684,   54366675,
    53687092,   53024288,   52377650,   51746594,   51130564,   50529028,   49941481,   49367441,
    48806447,   48258060,   47721859,   47197443,   46684428,   46182445,   45691142,   45210183,
    44739243,   44278014,   43826197,   43383509,   42949673,   42524429,   42107523,   41698712,
    41297763,   40904451,   40518560,   40139882,   39768216,   39403370,   39045158,   38693400,
    38347923,   38008561,   37675152,   37347542,   37025581,   36709123,   36398028,   36092163,
    35791395,   35495598,   35204650,   34918434,   34636834,   34359739,   34087043,   33818641,
    33554432,   33294321,   33038210,   32786010,   32537632,   32292988,   32051995,   31814573,
    31580642,   31350127,   31122952,   30899046,   30678338,   30460761,   30246249,   30034737,
    29826162,   29620465,   29417585,   29217465,   29020050,   28825284,   28633116,   28443493,
    28256364,   28071682,   27889399,   27709467,   27531842,   27356480,   27183338,   27012373,
    26843546,   26676816,   26512144,   26349493,   26188825,   26030105,   25873297,   25718368,
    25565282,   25414008,   25264514,   25116768,   24970741,   24826401,   24683721,   24542671,
    24403224,   24265352,   24129030,   23994231,   23860930,   23729102,   23598722,   23469767,
    23342214,   23216040,   23091223,   22967740,   22845571,   22724695,   22605092,   22486740,
    22369622,   22253717,   22139007,   22025474,   21913099,   21801865,   21691755,   21582751,
    21474837,   21367997,   21262215,   21157475,   21053762,   20951060,   20849356,   20748635,
    20648882,   20550083,   20452226,   20355296,   20259280,   20164166,   20069941,   19976593,
    19884108,   19792477,   19701685,   19611723,   19522579,   19434242,   19346700,   19259944,
    19173962,   19088744,   19004281,   18920561,   18837576,   18755316,   18673771,   18592933,
    18512791,   18433337,   18354562,   18276457,   18199014,   18122225,   18046082,   17970575,
    17895698,   17821442,   17747799,   17674763,   17602325,   17530479,   17459217,   17388532,
    17318417,   17248865,   17179870,   17111424,   17043522,   16976156,   16909321,   16843010,
    16777216
};

const uint8_t ff_sqrt_tab[256]=
{
    0, 16, 23, 28, 32, 36, 40, 43, 46, 48, 51, 54, 56, 58, 60, 62, 64, 66, 68, 70, 72, 74, 76, 77, 79, 80, 82, 84, 85, 87, 88, 90,
    91, 92, 94, 95, 96, 98, 99,100,102,103,104,105,107,108,109,110,111,112,114,115,116,117,118,119,120,121,122,123,124,125,126,127,
    128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,144,145,146,147,148,149,150,151,151,152,153,154,155,156,156,
    157,158,159,160,160,161,162,163,164,164,165,166,167,168,168,169,170,171,171,172,173,174,174,175,176,176,177,178,179,179,180,181,
    182,182,183,184,184,185,186,186,187,188,188,189,190,190,191,192,192,193,194,194,195,196,196,197,198,198,199,200,200,201,202,202,
    203,204,204,205,205,206,207,207,208,208,209,210,210,211,212,212,213,213,214,215,215,216,216,217,218,218,219,219,220,220,221,222,
    222,223,223,224,224,225,226,226,227,227,228,228,229,230,230,231,231,232,232,233,233,234,235,235,236,236,237,237,238,238,239,239,
    240,240,241,242,242,243,243,244,244,245,245,246,246,247,247,248,248,249,249,250,250,251,251,252,252,253,253,254,254,255,255,255
};

#define times4(x) x, x, x, x
#define times256(x) times4(times4(times4(times4(times4(x)))))

const uint8_t ff_crop_tab[256 + 2 * MAX_NEG_CROP] =
{
    times256(0x00),
    0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,
    0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,
    0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,0x2E,0x2F,
    0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x3D,0x3E,0x3F,
    0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,
    0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5A,0x5B,0x5C,0x5D,0x5E,0x5F,
    0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6A,0x6B,0x6C,0x6D,0x6E,0x6F,
    0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7A,0x7B,0x7C,0x7D,0x7E,0x7F,
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x8E,0x8F,
    0x90,0x91,0x92,0x93,0x94,0x95,0x96,0x97,0x98,0x99,0x9A,0x9B,0x9C,0x9D,0x9E,0x9F,
    0xA0,0xA1,0xA2,0xA3,0xA4,0xA5,0xA6,0xA7,0xA8,0xA9,0xAA,0xAB,0xAC,0xAD,0xAE,0xAF,
    0xB0,0xB1,0xB2,0xB3,0xB4,0xB5,0xB6,0xB7,0xB8,0xB9,0xBA,0xBB,0xBC,0xBD,0xBE,0xBF,
    0xC0,0xC1,0xC2,0xC3,0xC4,0xC5,0xC6,0xC7,0xC8,0xC9,0xCA,0xCB,0xCC,0xCD,0xCE,0xCF,
    0xD0,0xD1,0xD2,0xD3,0xD4,0xD5,0xD6,0xD7,0xD8,0xD9,0xDA,0xDB,0xDC,0xDD,0xDE,0xDF,
    0xE0,0xE1,0xE2,0xE3,0xE4,0xE5,0xE6,0xE7,0xE8,0xE9,0xEA,0xEB,0xEC,0xED,0xEE,0xEF,
    0xF0,0xF1,0xF2,0xF3,0xF4,0xF5,0xF6,0xF7,0xF8,0xF9,0xFA,0xFB,0xFC,0xFD,0xFE,0xFF,
    times256(0xFF)
};

const uint8_t ff_zigzag_direct[64] =
{
    0,   1,  8, 16,  9,  2,  3, 10,
    17, 24, 32, 25, 18, 11,  4,  5,
    12, 19, 26, 33, 40, 48, 41, 34,
    27, 20, 13,  6,  7, 14, 21, 28,
    35, 42, 49, 56, 57, 50, 43, 36,
    29, 22, 15, 23, 30, 37, 44, 51,
    58, 59, 52, 45, 38, 31, 39, 46,
    53, 60, 61, 54, 47, 55, 62, 63
};

const uint8_t ff_zigzag_scan[16+1] =
{
    0 + 0 * 4, 1 + 0 * 4, 0 + 1 * 4, 0 + 2 * 4,
    1 + 1 * 4, 2 + 0 * 4, 3 + 0 * 4, 2 + 1 * 4,
    1 + 2 * 4, 0 + 3 * 4, 1 + 3 * 4, 2 + 2 * 4,
    3 + 1 * 4, 3 + 2 * 4, 2 + 3 * 4, 3 + 3 * 4,
};
