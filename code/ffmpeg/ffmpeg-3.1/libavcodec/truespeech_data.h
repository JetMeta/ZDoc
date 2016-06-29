﻿/*
 * DSP Group TrueSpeech compatible decoder
 * copyright (c) 2005 Konstantin Shishkov
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

#ifndef AVCODEC_TRUESPEECH_DATA_H
#define AVCODEC_TRUESPEECH_DATA_H

#include <stdint.h>

/* codebooks fo expanding input filter */
static const int16_t ts_cb_0[32] =
{
    0x8240, 0x8364, 0x84CE, 0x865D, 0x8805, 0x89DE, 0x8BD7, 0x8DF4,
    0x9051, 0x92E2, 0x95DE, 0x990F, 0x9C81, 0xA079, 0xA54C, 0xAAD2,
    0xB18A, 0xB90A, 0xC124, 0xC9CC, 0xD339, 0xDDD3, 0xE9D6, 0xF893,
    0x096F, 0x1ACA, 0x29EC, 0x381F, 0x45F9, 0x546A, 0x63C3, 0x73B5,
};

static const int16_t ts_cb_1[32] =
{
    0x9F65, 0xB56B, 0xC583, 0xD371, 0xE018, 0xEBB4, 0xF61C, 0xFF59,
    0x085B, 0x1106, 0x1952, 0x214A, 0x28C9, 0x2FF8, 0x36E6, 0x3D92,
    0x43DF, 0x49BB, 0x4F46, 0x5467, 0x5930, 0x5DA3, 0x61EC, 0x65F9,
    0x69D4, 0x6D5A, 0x709E, 0x73AD, 0x766B, 0x78F0, 0x7B5A, 0x7DA5,
};

static const int16_t ts_cb_2[16] =
{
    0x96F8, 0xA3B4, 0xAF45, 0xBA53, 0xC4B1, 0xCECC, 0xD86F, 0xE21E,
    0xEBF3, 0xF640, 0x00F7, 0x0C20, 0x1881, 0x269A, 0x376B, 0x4D60,
};

static const int16_t ts_cb_3[16] =
{
    0xC654, 0xDEF2, 0xEFAA, 0xFD94, 0x096A, 0x143F, 0x1E7B, 0x282C,
    0x3176, 0x3A89, 0x439F, 0x4CA2, 0x557F, 0x5E50, 0x6718, 0x6F8D,
};

static const int16_t ts_cb_4[16] =
{
    0xABE7, 0xBBA8, 0xC81C, 0xD326, 0xDD0E, 0xE5D4, 0xEE22, 0xF618,
    0xFE28, 0x064F, 0x0EB7, 0x17B8, 0x21AA, 0x2D8B, 0x3BA2, 0x4DF9,
};

static const int16_t ts_cb_5[8] =
{
    0xD51B, 0xF12E, 0x042E, 0x13C7, 0x2260, 0x311B, 0x40DE, 0x5385,
};

static const int16_t ts_cb_6[8] =
{
    0xB550, 0xC825, 0xD980, 0xE997, 0xF883, 0x0752, 0x1811, 0x2E18,
};

static const int16_t ts_cb_7[8] =
{
    0xCEF0, 0xE4F9, 0xF6BB, 0x0646, 0x14F5, 0x23FF, 0x356F, 0x4A8D,
};

static const int16_t * const ts_codebook[8] =
{
    ts_cb_0, ts_cb_1, ts_cb_2, ts_cb_3, ts_cb_4, ts_cb_5, ts_cb_6, ts_cb_7
};

/* table used for decoding pulse positions */
static const int16_t ts_pulse_values[120] =
{
    0x0E46, 0x0CCC, 0x0B6D, 0x0A28, 0x08FC, 0x07E8, 0x06EB, 0x0604,
    0x0532, 0x0474, 0x03C9, 0x0330, 0x02A8, 0x0230, 0x01C7, 0x016C,
    0x011E, 0x00DC, 0x00A5, 0x0078, 0x0054, 0x0038, 0x0023, 0x0014,
    0x000A, 0x0004, 0x0001, 0x0000, 0x0000, 0x0000,

    0x0196, 0x017A, 0x015F, 0x0145, 0x012C, 0x0114, 0x00FD, 0x00E7,
    0x00D2, 0x00BE, 0x00AB, 0x0099, 0x0088, 0x0078, 0x0069, 0x005B,
    0x004E, 0x0042, 0x0037, 0x002D, 0x0024, 0x001C, 0x0015, 0x000F,
    0x000A, 0x0006, 0x0003, 0x0001, 0x0000, 0x0000,

    0x001D, 0x001C, 0x001B, 0x001A, 0x0019, 0x0018, 0x0017, 0x0016,
    0x0015, 0x0014, 0x0013, 0x0012, 0x0011, 0x0010, 0x000F, 0x000E,
    0x000D, 0x000C, 0x000B, 0x000A, 0x0009, 0x0008, 0x0007, 0x0006,
    0x0005, 0x0004, 0x0003, 0x0002, 0x0001, 0x0000,

    0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001,
    0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001,
    0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001,
    0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001
};

/* filter for correlated input filter */
static const int16_t ts_decay_994_1000[8] =
{ 0x7F3B, 0x7E78, 0x7DB6, 0x7CF5, 0x7C35, 0x7B76, 0x7AB8, 0x79FC };

/* two-point filters table */
static const int16_t ts_order2_coeffs[25 * 2] =
{
    0xED2F, 0x5239,
    0x54F1, 0xE4A9,
    0x2620, 0xEE3E,
    0x09D6, 0x2C40,
    0xEFB5, 0x2BE0,

    0x3FE1, 0x3339,
    0x442F, 0xE6FE,
    0x4458, 0xF9DF,
    0xF231, 0x43DB,
    0x3DB0, 0xF705,

    0x4F7B, 0xFEFB,
    0x26AD, 0x0CDC,
    0x33C2, 0x0739,
    0x12BE, 0x43A2,
    0x1BDF, 0x1F3E,

    0x0211, 0x0796,
    0x2AEB, 0x163F,
    0x050D, 0x3A38,
    0x0D1E, 0x0D78,
    0x150F, 0x3346,

    0x38A4, 0x0B7D,
    0x2D5D, 0x1FDF,
    0x19B7, 0x2822,
    0x0D99, 0x1F12,
    0x194C, 0x0CE6
};

/* possible pulse values */
static const int16_t ts_pulse_scales[64] =
{
    0x0002, 0x0006, 0xFFFE, 0xFFFA,
    0x0004, 0x000C, 0xFFFC, 0xFFF4,
    0x0006, 0x0012, 0xFFFA, 0xFFEE,
    0x000A, 0x001E, 0xFFF6, 0xFFE2,
    0x0010, 0x0030, 0xFFF0, 0xFFD0,
    0x0019, 0x004B, 0xFFE7, 0xFFB5,
    0x0028, 0x0078, 0xFFD8, 0xFF88,
    0x0040, 0x00C0, 0xFFC0, 0xFF40,
    0x0065, 0x012F, 0xFF9B, 0xFED1,
    0x00A1, 0x01E3, 0xFF5F, 0xFE1D,
    0x0100, 0x0300, 0xFF00, 0xFD00,
    0x0196, 0x04C2, 0xFE6A, 0xFB3E,
    0x0285, 0x078F, 0xFD7B, 0xF871,
    0x0400, 0x0C00, 0xFC00, 0xF400,
    0x0659, 0x130B, 0xF9A7, 0xECF5,
    0x0A14, 0x1E3C, 0xF5EC, 0xE1C4
};

/* filters used in final output calculations */
static const int16_t ts_decay_35_64[8] =
{ 0x4666, 0x26B8, 0x154C, 0x0BB6, 0x0671, 0x038B, 0x01F3, 0x0112 };
static const int16_t ts_decay_3_4[8] =
{ 0x6000, 0x4800, 0x3600, 0x2880, 0x1E60, 0x16C8, 0x1116, 0x0CD1 };

#endif /* AVCODEC_TRUESPEECH_DATA_H */
