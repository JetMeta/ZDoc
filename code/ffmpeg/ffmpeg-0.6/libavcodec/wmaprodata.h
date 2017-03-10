﻿/*
 * WMA 9/3/PRO compatible decoder
 * Copyright (c) 2007 Baptiste Coudurier, Benjamin Larsson, Ulion
 * Copyright (c) 2008 - 2009 Sascha Sommer
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

/**
 * @file
 * @brief tables for wmapro decoding
 */

#ifndef AVCODEC_WMAPRODATA_H
#define AVCODEC_WMAPRODATA_H

#include <stddef.h>
#include <stdint.h>

/**
 * @brief frequencies to divide the frequency spectrum into scale factor bands
 */
static const uint16_t critical_freq[] =
{
    100,   200,    300,    400,    510,    630,    770,
    920,  1080,   1270,   1480,   1720,   2000,   2320,
    2700,  3150,   3700,   4400,   5300,   6400,   7700,
    9500, 12000,  15500,  20675,  28575,  41375,  63875,
};


/**
 * @name Huffman tables for DPCM-coded scale factors
 * @{
 */
#define HUFF_SCALE_SIZE    121
#define HUFF_SCALE_MAXBITS  19
static const uint16_t scale_huffcodes[HUFF_SCALE_SIZE] =
{
    0xE639, 0xE6C2, 0xE6C1, 0xE6C0, 0xE63F, 0xE63E, 0xE63D, 0xE63C,
    0xE63B, 0xE63A, 0xE638, 0xE637, 0xE636, 0xE635, 0xE634, 0xE632,
    0xE633, 0xE620, 0x737B, 0xE610, 0xE611, 0xE612, 0xE613, 0xE614,
    0xE615, 0xE616, 0xE617, 0xE618, 0xE619, 0xE61A, 0xE61B, 0xE61C,
    0xE61D, 0xE61E, 0xE61F, 0xE6C3, 0xE621, 0xE622, 0xE623, 0xE624,
    0xE625, 0xE626, 0xE627, 0xE628, 0xE629, 0xE62A, 0xE62B, 0xE62C,
    0xE62D, 0xE62E, 0xE62F, 0xE630, 0xE631, 0x1CDF, 0x0E60, 0x0399,
    0x00E7, 0x001D, 0x0000, 0x0001, 0x0001, 0x0001, 0x0002, 0x0006,
    0x0002, 0x0007, 0x0006, 0x000F, 0x0038, 0x0072, 0x039A, 0xE6C4,
    0xE6C5, 0xE6C6, 0xE6C7, 0xE6C8, 0xE6C9, 0xE6CA, 0xE6CB, 0xE6CC,
    0xE6CD, 0xE6CE, 0xE6CF, 0xE6D0, 0xE6D1, 0xE6D2, 0xE6D3, 0xE6D4,
    0xE6D5, 0xE6D6, 0xE6D7, 0xE6D8, 0xE6D9, 0xE6DA, 0xE6DB, 0xE6DC,
    0xE6DD, 0xE6DE, 0xE6DF, 0xE6E0, 0xE6E1, 0xE6E2, 0xE6E3, 0xE6E4,
    0xE6E5, 0xE6E6, 0xE6E7, 0xE6E8, 0xE6E9, 0xE6EA, 0xE6EB, 0xE6EC,
    0xE6ED, 0xE6EE, 0xE6EF, 0xE6F0, 0xE6F1, 0xE6F2, 0xE6F3, 0xE6F4,
    0xE6F5,
};

static const uint8_t scale_huffbits[HUFF_SCALE_SIZE] =
{
    19, 19, 19, 19, 19, 19, 19, 19,
    19, 19, 19, 19, 19, 19, 19, 19,
    19, 19, 18, 19, 19, 19, 19, 19,
    19, 19, 19, 19, 19, 19, 19, 19,
    19, 19, 19, 19, 19, 19, 19, 19,
    19, 19, 19, 19, 19, 19, 19, 19,
    19, 19, 19, 19, 19, 16, 15, 13,
    11,  8,  5,  2,  1,  3,  5,  6,
    6,  7,  7,  7,  9, 10, 13, 19,
    19, 19, 19, 19, 19, 19, 19, 19,
    19, 19, 19, 19, 19, 19, 19, 19,
    19, 19, 19, 19, 19, 19, 19, 19,
    19, 19, 19, 19, 19, 19, 19, 19,
    19, 19, 19, 19, 19, 19, 19, 19,
    19, 19, 19, 19, 19, 19, 19, 19,
    19,
};
/** @} */


/**
 * @name Huffman, run and level tables for runlevel-coded scale factors
 * @{
 */
#define HUFF_SCALE_RL_SIZE    120
#define HUFF_SCALE_RL_MAXBITS  21
static const uint32_t scale_rl_huffcodes[HUFF_SCALE_RL_SIZE] =
{
    0x00010C, 0x000001, 0x10FE2A, 0x000003, 0x000003, 0x000001, 0x000013,
    0x000020, 0x000029, 0x000014, 0x000016, 0x000045, 0x000049, 0x00002F,
    0x000042, 0x00008E, 0x00008F, 0x000129, 0x000009, 0x00000D, 0x0004AC,
    0x00002C, 0x000561, 0x0002E6, 0x00087C, 0x0002E2, 0x00095C, 0x000018,
    0x000001, 0x000016, 0x000044, 0x00002A, 0x000007, 0x000159, 0x000143,
    0x000128, 0x00015A, 0x00012D, 0x00002B, 0x0000A0, 0x000142, 0x00012A,
    0x0002EF, 0x0004AF, 0x00087D, 0x004AE9, 0x0043F9, 0x000067, 0x000199,
    0x002B05, 0x001583, 0x0021FE, 0x10FE2C, 0x000004, 0x00002E, 0x00010D,
    0x00000A, 0x000244, 0x000017, 0x000245, 0x000011, 0x00010E, 0x00012C,
    0x00002A, 0x00002F, 0x000121, 0x000046, 0x00087E, 0x0000BA, 0x000032,
    0x0087F0, 0x0056DC, 0x0002EC, 0x0043FA, 0x002B6F, 0x004AE8, 0x0002B7,
    0x10FE2B, 0x000001, 0x000051, 0x000010, 0x0002EE, 0x000B9C, 0x002576,
    0x000198, 0x0056DD, 0x0000CD, 0x000AC0, 0x000170, 0x004AEF, 0x00002D,
    0x0004AD, 0x0021FF, 0x0005CF, 0x002B04, 0x10FE29, 0x10FE28, 0x0002ED,
    0x002E74, 0x021FC4, 0x004AEE, 0x010FE3, 0x087F17, 0x000000, 0x000097,
    0x0002E3, 0x000ADA, 0x002575, 0x00173B, 0x0043FB, 0x002E75, 0x10FE2D,
    0x0015B6, 0x00056C, 0x000057, 0x000123, 0x000120, 0x00021E, 0x000172,
    0x0002B1,
};

static const uint8_t scale_rl_huffbits[HUFF_SCALE_RL_SIZE] =
{
    9,  2, 21,  2,  4,  5,  5,
    6,  6,  7,  7,  7,  7,  6,
    7,  8,  8,  9, 10, 10, 11,
    12, 11, 12, 12, 12, 12, 11,
    4,  5,  7,  8,  9,  9,  9,
    9,  9,  9,  8,  8,  9,  9,
    12, 11, 12, 15, 15, 13, 15,
    14, 13, 14, 21,  5,  6,  9,
    10, 10, 11, 10, 11,  9,  9,
    6,  8,  9,  7, 12, 10, 12,
    16, 15, 12, 15, 14, 15, 10,
    21,  6,  7, 11, 12, 14, 14,
    15, 15, 14, 12, 11, 15, 12,
    11, 14, 13, 14, 21, 21, 12,
    16, 18, 15, 17, 20,  7,  8,
    12, 12, 14, 15, 15, 16, 21,
    13, 11,  7,  9,  9, 10, 11,
    10,
};


static const uint8_t scale_rl_run[HUFF_SCALE_RL_SIZE] =
{
    0,  0,  0,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
    16, 17, 18, 19, 20, 21, 22, 23, 24,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,
    10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,  0,  1,  2,  3,
    4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
    23, 24,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16,
    17, 18, 19, 20, 21, 22, 23, 24,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10,
    0,  1,  0,  1,  0,  1,
};

static const uint8_t scale_rl_level[HUFF_SCALE_RL_SIZE] =
{
    0,  0,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
    2,  2,  2,  2,  2,  2,  2,  2,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,
    3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,
    4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,
    4,  4,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,
    5,  5,  5,  5,  5,  5,  5,  5,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,
    7,  7,  8,  8,  9,  9,
};
/** @} */


/**
 * @name Huffman, run and level codes for runlevel-coded coefficients
 * @{
 */
#define HUFF_COEF0_SIZE    272
#define HUFF_COEF0_MAXBITS  21
static const uint32_t coef0_huffcodes[HUFF_COEF0_SIZE] =
{
    0x00004A, 0x00002B, 0x000000, 0x000003, 0x000006, 0x000009, 0x00000F,
    0x000010, 0x000016, 0x000011, 0x000016, 0x000028, 0x00002F, 0x000026,
    0x000029, 0x000045, 0x000055, 0x00005D, 0x000042, 0x00004E, 0x000051,
    0x00005E, 0x00008D, 0x0000A8, 0x0000AD, 0x000080, 0x000096, 0x00009F,
    0x0000AA, 0x0000BE, 0x00011C, 0x000153, 0x000158, 0x000170, 0x000104,
    0x00010D, 0x000105, 0x000103, 0x00012F, 0x000177, 0x000175, 0x000157,
    0x000174, 0x000225, 0x00023B, 0x00020D, 0x00021F, 0x000281, 0x00027B,
    0x000282, 0x0002AC, 0x0002FD, 0x00044F, 0x000478, 0x00044D, 0x0002EC,
    0x00044E, 0x000564, 0x000409, 0x00040B, 0x000501, 0x000545, 0x0004F3,
    0x000541, 0x00043B, 0x0004F1, 0x0004F4, 0x0008FD, 0x000A94, 0x000811,
    0x000B88, 0x000B91, 0x000B93, 0x0008EA, 0x000899, 0x000B8A, 0x000972,
    0x0009E5, 0x000A8F, 0x000A84, 0x000A8E, 0x000A00, 0x000830, 0x0008E8,
    0x000B95, 0x000871, 0x00083A, 0x000814, 0x000873, 0x000BFE, 0x001728,
    0x001595, 0x001712, 0x00102A, 0x001021, 0x001729, 0x00152E, 0x0013C3,
    0x001721, 0x001597, 0x00151B, 0x0010F2, 0x001403, 0x001703, 0x001503,
    0x001708, 0x0013C1, 0x00170E, 0x00170C, 0x0010E1, 0x0011EA, 0x001020,
    0x001500, 0x0017FA, 0x001704, 0x001705, 0x0017F0, 0x0017FB, 0x0021E6,
    0x002B2D, 0x0020C6, 0x002B29, 0x002E4A, 0x0023AC, 0x001519, 0x0023F3,
    0x002B2C, 0x0021C0, 0x0017FE, 0x0023D7, 0x0017F9, 0x0012E7, 0x0013C0,
    0x002261, 0x0023D3, 0x002057, 0x002056, 0x0021D2, 0x0020C7, 0x0023D2,
    0x0020EC, 0x0044C0, 0x002FE2, 0x00475B, 0x002A03, 0x002FE3, 0x0021E2,
    0x0021D0, 0x002A31, 0x002E13, 0x002E05, 0x0047E5, 0x00000E, 0x000024,
    0x000088, 0x0000B9, 0x00010C, 0x000224, 0x0002B3, 0x000283, 0x0002ED,
    0x00047B, 0x00041E, 0x00043D, 0x0004F5, 0x0005FD, 0x000A92, 0x000B96,
    0x000838, 0x000971, 0x000B83, 0x000B80, 0x000BF9, 0x0011D3, 0x0011E8,
    0x0011D7, 0x001527, 0x0011F8, 0x001073, 0x0010F0, 0x0010E4, 0x0017F8,
    0x001062, 0x001402, 0x0017E3, 0x00151A, 0x001077, 0x00152B, 0x00170D,
    0x0021D3, 0x002E41, 0x0013C2, 0x000029, 0x0000A9, 0x00025D, 0x000419,
    0x000544, 0x000B8B, 0x0009E4, 0x0011D2, 0x001526, 0x001724, 0x0012E6,
    0x00150B, 0x0017FF, 0x002E26, 0x002E4B, 0x002B28, 0x0021E3, 0x002A14,
    0x00475A, 0x002E12, 0x000057, 0x00023E, 0x000A90, 0x000BF0, 0x001072,
    0x001502, 0x0023D6, 0x0020ED, 0x002A30, 0x0044C7, 0x00008C, 0x00047F,
    0x00152A, 0x002262, 0x002E04, 0x0000A1, 0x0005F9, 0x000173, 0x000875,
    0x000171, 0x00152D, 0x0002E3, 0x0017E2, 0x0002AD, 0x0021C1, 0x000479,
    0x0021E7, 0x00041F, 0x005C4E, 0x000543, 0x005C4F, 0x000A91, 0x00898D,
    0x000B97, 0x008746, 0x000970, 0x008745, 0x000B85, 0x00A856, 0x00152F,
    0x010E8E, 0x0010E5, 0x00A857, 0x00170F, 0x021D11, 0x002A58, 0x010E8F,
    0x002E40, 0x021D13, 0x002A59, 0x043A25, 0x002A02, 0x043A21, 0x0044C1,
    0x087448, 0x0047E4, 0x043A20, 0x00542A, 0x087449, 0x00898C,
};

static const uint8_t coef0_huffbits[HUFF_COEF0_SIZE] =
{
    8,  7,  2,  3,  3,  4,  4,
    5,  5,  6,  6,  6,  6,  7,
    7,  7,  7,  7,  8,  8,  8,
    8,  8,  8,  8,  9,  9,  9,
    9,  9,  9,  9,  9,  9, 10,
    10, 10, 10, 10, 10, 10, 10,
    10, 10, 10, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11,
    11, 11, 12, 12, 12, 12, 12,
    12, 12, 12, 12, 12, 12, 13,
    12, 12, 12, 12, 12, 12, 13,
    13, 13, 13, 13, 13, 13, 12,
    12, 13, 13, 13, 13, 13, 13,
    13, 13, 14, 14, 13, 13, 14,
    13, 13, 14, 14, 14, 14, 14,
    14, 14, 14, 14, 14, 13, 14,
    14, 14, 14, 14, 14, 14, 15,
    14, 15, 14, 14, 14, 14, 14,
    14, 15, 14, 14, 14, 14, 14,
    14, 14, 15, 15, 15, 15, 14,
    15, 15, 15, 15, 15, 15, 15,
    15, 15, 15, 15, 15,  4,  7,
    8,  9, 10, 10, 10, 11, 11,
    11, 12, 12, 12, 12, 12, 12,
    13, 13, 13, 13, 13, 13, 13,
    13, 13, 13, 14, 14, 14, 14,
    14, 14, 14, 14, 14, 13, 14,
    15, 14, 14,  6,  9, 11, 12,
    12, 12, 13, 13, 13, 13, 14,
    14, 14, 14, 14, 14, 15, 15,
    15, 15,  7, 10, 12, 13, 14,
    14, 14, 15, 15, 15,  8, 11,
    13, 14, 15,  9, 12,  9, 13,
    10, 13, 10, 14, 11, 15, 11,
    15, 12, 15, 12, 15, 12, 16,
    12, 17, 13, 17, 13, 17, 13,
    18, 14, 17, 14, 19, 14, 18,
    14, 19, 14, 20, 15, 20, 15,
    21, 15, 20, 16, 21, 16,
};


#define HUFF_COEF1_SIZE    244
#define HUFF_COEF1_MAXBITS  22
static const uint32_t coef1_huffcodes[HUFF_COEF1_SIZE] =
{
    0x0001E2, 0x00007F, 0x000000, 0x000002, 0x000008, 0x00000E, 0x000019,
    0x00002F, 0x000037, 0x000060, 0x00006C, 0x000095, 0x0000C6, 0x0000F0,
    0x00012E, 0x000189, 0x0001A5, 0x0001F8, 0x000253, 0x00030A, 0x000344,
    0x00034D, 0x0003F2, 0x0004BD, 0x0005D7, 0x00062A, 0x00068B, 0x000693,
    0x000797, 0x00097D, 0x000BAB, 0x000C52, 0x000C5E, 0x000D21, 0x000D20,
    0x000F1A, 0x000FCE, 0x000FD1, 0x0012F1, 0x001759, 0x0018AC, 0x0018A7,
    0x0018BF, 0x001A2B, 0x001E52, 0x001E50, 0x001E31, 0x001FB8, 0x0025E6,
    0x0025E7, 0x002EB4, 0x002EB7, 0x003169, 0x00315B, 0x00317C, 0x00316C,
    0x0034CA, 0x00348D, 0x003F40, 0x003CA2, 0x003F76, 0x004BC3, 0x004BE5,
    0x003F73, 0x004BF8, 0x004BF9, 0x006131, 0x00628B, 0x006289, 0x0062DA,
    0x00628A, 0x0062D4, 0x006997, 0x0062B4, 0x006918, 0x00794D, 0x007E7B,
    0x007E87, 0x007EEA, 0x00794E, 0x00699D, 0x007967, 0x00699F, 0x0062DB,
    0x007E7A, 0x007EEB, 0x00BAC0, 0x0097C9, 0x00C537, 0x00C5AB, 0x00D233,
    0x00D338, 0x00BAC1, 0x00D23D, 0x012F91, 0x00D339, 0x00FDC8, 0x00D23C,
    0x00FDDC, 0x00FDC9, 0x00FDDD, 0x00D33C, 0x000003, 0x000016, 0x00003E,
    0x0000C3, 0x0001A1, 0x000347, 0x00062E, 0x000BAA, 0x000F2D, 0x001A2A,
    0x001E58, 0x00309B, 0x003CA3, 0x005D6A, 0x00629A, 0x006996, 0x00794F,
    0x007EE5, 0x00BAD7, 0x00C5AA, 0x00C5F4, 0x00FDDF, 0x00FDDE, 0x018A20,
    0x018A6D, 0x01A67B, 0x01A464, 0x025F21, 0x01F9E2, 0x01F9E3, 0x00000A,
    0x00003D, 0x000128, 0x0003C7, 0x000C24, 0x0018A3, 0x002EB1, 0x003CB2,
    0x00691F, 0x007E79, 0x000013, 0x0000BB, 0x00034E, 0x000D14, 0x0025FD,
    0x004BE7, 0x000024, 0x000188, 0x0007EF, 0x000035, 0x000308, 0x0012F2,
    0x00005C, 0x0003F6, 0x0025E0, 0x00006D, 0x000698, 0x000096, 0x000C25,
    0x0000C7, 0x000F1B, 0x0000F3, 0x0012FF, 0x000174, 0x001A66, 0x0001A0,
    0x003099, 0x0001E4, 0x00316B, 0x000252, 0x003F31, 0x00030B, 0x004BE6,
    0x000346, 0x0062FB, 0x00034F, 0x007966, 0x0003F5, 0x007E86, 0x0005D4,
    0x00C511, 0x00062C, 0x00C5F5, 0x000692, 0x00F299, 0x000795, 0x00F298,
    0x0007E9, 0x018A21, 0x00097E, 0x0175AD, 0x000C27, 0x01A67A, 0x000C57,
    0x02EB59, 0x000D22, 0x0314D9, 0x000F19, 0x03F3C2, 0x000FCD, 0x0348CB,
    0x0012F8, 0x04BE41, 0x0018A0, 0x03F3C1, 0x0018A1, 0x04BE40, 0x0018B7,
    0x0629B0, 0x001A64, 0x0D2329, 0x001E30, 0x03F3C3, 0x001F9F, 0x0BAD62,
    0x001F99, 0x0FCF00, 0x00309A, 0x0629B1, 0x002EB6, 0x175AC3, 0x00314C,
    0x069195, 0x003168, 0x0BAD63, 0x00348E, 0x175AC1, 0x003F30, 0x07E781,
    0x003F41, 0x0D2328, 0x003F42, 0x1F9E03, 0x004BC2, 0x175AC2, 0x003F74,
    0x175AC0, 0x005D61, 0x3F3C05, 0x006130, 0x3F3C04, 0x0062B5,
};

static const uint8_t coef1_huffbits[HUFF_COEF1_SIZE] =
{
    9,  7,  2,  3,  4,  4,  5,
    6,  6,  7,  7,  8,  8,  8,
    9,  9,  9,  9, 10, 10, 10,
    10, 10, 11, 11, 11, 11, 11,
    11, 12, 12, 12, 12, 12, 12,
    12, 12, 12, 13, 13, 13, 13,
    13, 13, 13, 13, 13, 13, 14,
    14, 14, 14, 14, 14, 14, 14,
    14, 14, 14, 14, 14, 15, 15,
    14, 15, 15, 15, 15, 15, 15,
    15, 15, 15, 15, 15, 15, 15,
    15, 15, 15, 15, 15, 15, 15,
    15, 15, 16, 16, 16, 16, 16,
    16, 16, 16, 17, 16, 16, 16,
    16, 16, 16, 16,  3,  5,  6,
    8,  9, 10, 11, 12, 12, 13,
    13, 14, 14, 15, 15, 15, 15,
    15, 16, 16, 16, 16, 16, 17,
    17, 17, 17, 18, 17, 17,  4,
    6,  9, 10, 12, 13, 14, 14,
    15, 15,  5,  8, 10, 12, 14,
    15,  6,  9, 11,  6, 10, 13,
    7, 10, 14,  7, 11,  8, 12,
    8, 12,  8, 13,  9, 13,  9,
    14,  9, 14, 10, 14, 10, 15,
    10, 15, 10, 15, 10, 15, 11,
    16, 11, 16, 11, 16, 11, 16,
    11, 17, 12, 17, 12, 17, 12,
    18, 12, 18, 12, 18, 12, 18,
    13, 19, 13, 18, 13, 19, 13,
    19, 13, 20, 13, 18, 13, 20,
    13, 20, 14, 19, 14, 21, 14,
    19, 14, 20, 14, 21, 14, 19,
    14, 20, 14, 21, 15, 21, 14,
    21, 15, 22, 15, 22, 15,
};


static const uint16_t coef0_run[HUFF_COEF0_SIZE] =
{
    0,   0,   0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,
    12,  13,  14,  15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25,
    26,  27,  28,  29,  30,  31,  32,  33,  34,  35,  36,  37,  38,  39,
    40,  41,  42,  43,  44,  45,  46,  47,  48,  49,  50,  51,  52,  53,
    54,  55,  56,  57,  58,  59,  60,  61,  62,  63,  64,  65,  66,  67,
    68,  69,  70,  71,  72,  73,  74,  75,  76,  77,  78,  79,  80,  81,
    82,  83,  84,  85,  86,  87,  88,  89,  90,  91,  92,  93,  94,  95,
    96,  97,  98,  99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109,
    110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123,
    124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137,
    138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149,   0,   1,
    2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14,  15,
    16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,
    30,  31,  32,  33,  34,  35,  36,  37,  38,  39,   0,   1,   2,   3,
    4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14,  15,  16,  17,
    18,  19,   0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   1,
    2,   3,   4,   0,   1,   0,   1,   0,   1,   0,   1,   0,   1,   0,
    1,   0,   1,   0,   1,   0,   1,   0,   1,   0,   1,   0,   1,   0,
    1,   0,   1,   0,   1,   0,   1,   0,   1,   0,   1,   0,   1,   0,
    1,   0,   1,   0,   1,   0,
};

static const float coef0_level[HUFF_COEF0_SIZE] =
{
    0,   0,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
    1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
    1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
    1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
    1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
    1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
    1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
    1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
    1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
    1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
    1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   2,   2,
    2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
    2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
    2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   3,   3,   3,   3,
    3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,
    3,   3,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   5,   5,
    5,   5,   5,   6,   6,   7,   7,   8,   8,   9,   9,  10,  10,  11,
    11,  12,  12,  13,  13,  14,  14,  15,  15,  16,  16,  17,  17,  18,
    18,  19,  19,  20,  20,  21,  21,  22,  22,  23,  23,  24,  24,  25,
    25,  26,  26,  27,  27,  28,
};


static const uint16_t coef1_run[HUFF_COEF1_SIZE] =
{
    0,  0,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
    16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33,
    34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,
    52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
    70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87,
    88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99,  0,  1,  2,  3,  4,  5,
    6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23,
    24, 25, 26, 27, 28, 29,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,
    2,  3,  4,  5,  0,  1,  2,  0,  1,  2,  0,  1,  2,  0,  1,  0,  1,  0,
    1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,
    1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,
    1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,
    1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,
    1,  0,  1,  0,  1,  0,  1,  0,  0,  0,
};

static const float coef1_level[HUFF_COEF1_SIZE] =
{
    0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,
    2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
    2,  2,  2,  2,  2,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  4,  4,
    4,  4,  4,  4,  5,  5,  5,  6,  6,  6,  7,  7,  7,  8,  8,  9,  9, 10,
    10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15, 16, 16, 17, 17, 18, 18, 19,
    19, 20, 20, 21, 21, 22, 22, 23, 23, 24, 24, 25, 25, 26, 26, 27, 27, 28,
    28, 29, 29, 30, 30, 31, 31, 32, 32, 33, 33, 34, 34, 35, 35, 36, 36, 37,
    37, 38, 38, 39, 39, 40, 40, 41, 41, 42, 42, 43, 43, 44, 44, 45, 45, 46,
    46, 47, 47, 48, 48, 49, 49, 50, 51, 52,
};
/** @} */


/**
 * @name Huffman and vector lookup tables for vector-coded coefficients
 * @{
 */
#define HUFF_VEC4_SIZE    127
#define HUFF_VEC4_MAXBITS  14
static const uint16_t vec4_huffcodes[HUFF_VEC4_SIZE] =
{
    0x0019, 0x0027, 0x00F2, 0x03BA, 0x0930, 0x1267, 0x0031, 0x0030,
    0x0097, 0x0221, 0x058B, 0x0124, 0x00EB, 0x01D4, 0x03D8, 0x0584,
    0x0364, 0x045F, 0x0F66, 0x0931, 0x24CD, 0x002F, 0x0039, 0x00E8,
    0x02C3, 0x078A, 0x0037, 0x0029, 0x0084, 0x01B1, 0x00ED, 0x0086,
    0x00F9, 0x03AB, 0x01EB, 0x08BC, 0x011E, 0x00F3, 0x0220, 0x058A,
    0x00EC, 0x008E, 0x012B, 0x01EA, 0x0119, 0x04B0, 0x04B1, 0x03B8,
    0x0691, 0x0365, 0x01ED, 0x049A, 0x0EA9, 0x0EA8, 0x08BD, 0x24CC,
    0x0026, 0x0035, 0x00DB, 0x02C4, 0x07B2, 0x0038, 0x002B, 0x007F,
    0x01B3, 0x00F4, 0x0091, 0x0116, 0x03BB, 0x0215, 0x0932, 0x002D,
    0x002A, 0x008A, 0x01DE, 0x0028, 0x0020, 0x005C, 0x0090, 0x0068,
    0x01EE, 0x00E9, 0x008D, 0x012A, 0x0087, 0x005D, 0x0118, 0x0349,
    0x01EF, 0x01E3, 0x08B9, 0x00F0, 0x00D3, 0x0214, 0x049B, 0x00DA,
    0x0089, 0x0125, 0x0217, 0x012D, 0x0690, 0x0094, 0x007D, 0x011F,
    0x007E, 0x0059, 0x0127, 0x01A5, 0x0111, 0x00F8, 0x045D, 0x03B9,
    0x0259, 0x0580, 0x02C1, 0x01DF, 0x0585, 0x0216, 0x0163, 0x01B0,
    0x03C4, 0x08B8, 0x078B, 0x0755, 0x0581, 0x0F67, 0x0000,
};

static const uint8_t vec4_huffbits[HUFF_VEC4_SIZE] =
{
    5,  6,  8, 10, 12, 13,  6,  6,
    8, 10, 11,  9,  8,  9, 10, 11,
    10, 11, 12, 12, 14,  6,  6,  8,
    10, 11,  6,  6,  8,  9,  8,  8,
    8, 10,  9, 12,  9,  8, 10, 11,
    8,  8,  9,  9,  9, 11, 11, 10,
    11, 10,  9, 11, 12, 12, 12, 14,
    6,  6,  8, 10, 11,  6,  6,  7,
    9,  8,  8,  9, 10, 10, 12,  6,
    6,  8,  9,  6,  6,  7,  8,  7,
    9,  8,  8,  9,  8,  7,  9, 10,
    9,  9, 12,  8,  8, 10, 11,  8,
    8,  9, 10,  9, 11,  8,  7,  9,
    7,  7,  9,  9,  9,  8, 11, 10,
    10, 11, 10,  9, 11, 10,  9,  9,
    10, 12, 11, 11, 11, 12,  1,
};


#define HUFF_VEC2_SIZE    137
#define HUFF_VEC2_MAXBITS  12
static const uint16_t vec2_huffcodes[HUFF_VEC2_SIZE] =
{
    0x055, 0x01C, 0x01A, 0x02B, 0x028, 0x067, 0x08B, 0x039,
    0x170, 0x10D, 0x2A5, 0x047, 0x464, 0x697, 0x523, 0x8CB,
    0x01B, 0x00E, 0x000, 0x010, 0x012, 0x036, 0x048, 0x04C,
    0x0C2, 0x09B, 0x171, 0x03B, 0x224, 0x34A, 0x2D6, 0x019,
    0x00F, 0x002, 0x014, 0x017, 0x006, 0x05D, 0x054, 0x0C7,
    0x0B4, 0x192, 0x10E, 0x233, 0x043, 0x02C, 0x00F, 0x013,
    0x006, 0x02F, 0x02C, 0x068, 0x077, 0x0DF, 0x111, 0x1A4,
    0x16A, 0x2A4, 0x027, 0x011, 0x018, 0x02D, 0x00F, 0x04A,
    0x040, 0x097, 0x01F, 0x11B, 0x022, 0x16D, 0x066, 0x035,
    0x005, 0x02B, 0x049, 0x009, 0x075, 0x0CB, 0x0AA, 0x187,
    0x106, 0x08A, 0x047, 0x060, 0x06E, 0x01D, 0x074, 0x0C4,
    0x01E, 0x118, 0x1A7, 0x038, 0x042, 0x053, 0x076, 0x0A8,
    0x0CA, 0x082, 0x110, 0x18D, 0x12D, 0x0B9, 0x0C8, 0x0DE,
    0x01C, 0x0AB, 0x113, 0x18C, 0x10F, 0x09A, 0x0A5, 0x0B7,
    0x11A, 0x186, 0x1A6, 0x259, 0x153, 0x18A, 0x193, 0x020,
    0x10C, 0x046, 0x03A, 0x107, 0x149, 0x16C, 0x2D7, 0x225,
    0x258, 0x316, 0x696, 0x317, 0x042, 0x522, 0x290, 0x8CA,
    0x001,
};

static const uint8_t vec2_huffbits[HUFF_VEC2_SIZE] =
{
    7,  6,  6,  6,  7,  7,  8,  9,
    9, 10, 10, 11, 11, 11, 12, 12,
    6,  4,  5,  5,  6,  6,  7,  8,
    8,  9,  9, 10, 10, 10, 11,  6,
    4,  5,  5,  6,  7,  7,  8,  8,
    9,  9, 10, 10, 11,  6,  5,  5,
    6,  6,  7,  7,  8,  8,  9,  9,
    10, 10,  7,  6,  6,  6,  7,  7,
    8,  8,  9,  9, 10, 10,  7,  6,
    7,  7,  7,  8,  8,  8,  9,  9,
    10,  8,  7,  7,  7,  8,  8,  8,
    9,  9,  9,  9,  8,  8,  8,  8,
    8,  9,  9,  9,  9,  8,  8,  8,
    9,  9,  9,  9, 10,  9,  9,  9,
    9,  9,  9, 10,  9,  9,  9, 10,
    10, 11, 10, 10, 10, 10, 11, 10,
    10, 10, 11, 10, 11, 12, 11, 12,
    3,
};


#define HUFF_VEC1_SIZE    101
#define HUFF_VEC1_MAXBITS  11
static const uint16_t vec1_huffcodes[HUFF_VEC1_SIZE] =
{
    0x01A, 0x003, 0x017, 0x010, 0x00C, 0x009, 0x005, 0x000,
    0x00D, 0x00A, 0x009, 0x00C, 0x00F, 0x002, 0x004, 0x007,
    0x00B, 0x00F, 0x01C, 0x006, 0x010, 0x015, 0x01C, 0x022,
    0x03B, 0x00E, 0x019, 0x023, 0x034, 0x036, 0x03A, 0x047,
    0x008, 0x00A, 0x01E, 0x031, 0x037, 0x050, 0x053, 0x06B,
    0x06F, 0x08C, 0x0E8, 0x0EA, 0x0EB, 0x016, 0x03E, 0x03F,
    0x06C, 0x089, 0x08A, 0x0A3, 0x0A4, 0x0D4, 0x0DD, 0x0EC,
    0x0EE, 0x11A, 0x1D2, 0x024, 0x025, 0x02E, 0x027, 0x0C2,
    0x0C0, 0x0DA, 0x0DB, 0x111, 0x144, 0x116, 0x14A, 0x145,
    0x1B8, 0x1AB, 0x1DA, 0x1DE, 0x1DB, 0x1DF, 0x236, 0x237,
    0x3A6, 0x3A7, 0x04D, 0x04C, 0x05E, 0x05F, 0x183, 0x182,
    0x186, 0x221, 0x187, 0x220, 0x22E, 0x22F, 0x296, 0x354,
    0x297, 0x355, 0x372, 0x373, 0x016,
};

static const uint8_t vec1_huffbits[HUFF_VEC1_SIZE] =
{
    7,  6,  5,  5,  5,  5,  5,  5,
    4,  4,  4,  4,  4,  5,  5,  5,
    5,  5,  5,  6,  6,  6,  6,  6,
    6,  7,  7,  7,  7,  7,  7,  7,
    8,  8,  8,  8,  8,  8,  8,  8,
    8,  8,  8,  8,  8,  9,  9,  9,
    9,  9,  9,  9,  9,  9,  9,  9,
    9,  9,  9, 10, 10, 10, 10, 10,
    10, 10, 10, 10, 10, 10, 10, 10,
    10, 10, 10, 10, 10, 10, 10, 10,
    10, 10, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11,  5,
};


static const uint16_t symbol_to_vec4[HUFF_VEC4_SIZE] =
{
    0,    1,      2,     3,     4,     5,    16,    17,    18,    19,
    20,   32,     33,    34,    35,    48,    49,    50,    64,    65,
    80,   256,   257,   258,   259,   260,   272,   273,   274,   275,
    288,   289,   290,   304,   305,   320,   512,   513,   514,   515,
    528,   529,   530,   544,   545,   560,   768,   769,   770,   784,
    785,   800,  1024,  1025,  1040,  1280,  4096,  4097,  4098,  4099,
    4100,  4112,  4113,  4114,  4115,  4128,  4129,  4130,  4144,  4145,
    4160,  4352,  4353,  4354,  4355,  4368,  4369,  4370,  4384,  4385,
    4400,  4608,  4609,  4610,  4624,  4625,  4640,  4864,  4865,  4880,
    5120,  8192,  8193,  8194,  8195,  8208,  8209,  8210,  8224,  8225,
    8240,  8448,  8449,  8450,  8464,  8465,  8480,  8704,  8705,  8720,
    8960, 12288, 12289, 12290, 12304, 12305, 12320, 12544, 12545, 12560,
    12800, 16384, 16385, 16400, 16640, 20480,     0,
};


static const uint8_t symbol_to_vec2[HUFF_VEC2_SIZE] =
{
    0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14,
    15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,
    30,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,
    48,  49,  50,  51,  52,  53,  54,  55,  56,  57,  58,  59,  60,  64,  65,
    66,  67,  68,  69,  70,  71,  72,  73,  74,  75,  80,  81,  82,  83,  84,
    85,  86,  87,  88,  89,  90,  96,  97,  98,  99, 100, 101, 102, 103, 104,
    105, 112, 113, 114, 115, 116, 117, 118, 119, 120, 128, 129, 130, 131, 132,
    133, 134, 135, 144, 145, 146, 147, 148, 149, 150, 160, 161, 162, 163, 164,
    165, 176, 177, 178, 179, 180, 192, 193, 194, 195, 208, 209, 210, 224, 225,
    240,   0,
};
/** @} */


/**
 * @brief decorrelation matrix for multichannel streams
 **/
static const float default_decorrelation_matrices[] =
{
    1.000000,  0.707031, -0.707031,  0.707031,  0.707031,  0.578125,  0.707031,
    0.410156,  0.578125, -0.707031,  0.410156,  0.578125,  0.000000, -0.816406,
    0.500000,  0.652344,  0.500000,  0.269531,  0.500000,  0.269531, -0.500000,
    -0.652344,  0.500000, -0.269531, -0.500000,  0.652344,  0.500000, -0.652344,
    0.500000, -0.269531,  0.445312,  0.601562,  0.511719,  0.371094,  0.195312,
    0.445312,  0.371094, -0.195312, -0.601562, -0.511719,  0.445312,  0.000000,
    -0.632812,  0.000000,  0.632812,  0.445312, -0.371094, -0.195312,  0.601562,
    -0.511719,  0.445312, -0.601562,  0.511719, -0.371094,  0.195312,  0.410156,
    0.558594,  0.500000,  0.410156,  0.289062,  0.148438,  0.410156,  0.410156,
    0.000000, -0.410156, -0.578125, -0.410156,  0.410156,  0.148438, -0.500000,
    -0.410156,  0.289062,  0.558594,  0.410156, -0.148438, -0.500000,  0.410156,
    0.289062, -0.558594,  0.410156, -0.410156,  0.000000,  0.410156, -0.578125,
    0.410156,  0.410156, -0.558594,  0.500000, -0.410156,  0.289062, -0.148438,
};

/**
 * @brief default decorrelation matrix offsets
 */
static const float * const default_decorrelation[] =
{
    NULL,
    &default_decorrelation_matrices[0],
    &default_decorrelation_matrices[1],
    &default_decorrelation_matrices[5],
    &default_decorrelation_matrices[14],
    &default_decorrelation_matrices[30],
    &default_decorrelation_matrices[55]
};

#endif /* AVCODEC_WMAPRODATA_H */
