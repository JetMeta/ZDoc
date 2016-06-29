/*
 * Header file for hardcoded AAC SBR windows
 *
 * Copyright (c) 2014 Reimar Döffinger <Reimar.Doeffinger@gmx.de>
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

#ifndef AVCODEC_AACSBR_TABLEGEN_COMMON_H
#define AVCODEC_AACSBR_TABLEGEN_COMMON_H
#include "aac_defines.h"
#include "libavutil/mem.h"

///< window coefficients for analysis/synthesis QMF banks
static DECLARE_ALIGNED(32, INTFLOAT, sbr_qmf_window_ds)[320];
static DECLARE_ALIGNED(32, INTFLOAT, sbr_qmf_window_us)[640] =
{
    Q31( 0.0000000000f), Q31(-0.0005525286f), Q31(-0.0005617692f), Q31(-0.0004947518f),
    Q31(-0.0004875227f), Q31(-0.0004893791f), Q31(-0.0005040714f), Q31(-0.0005226564f),
    Q31(-0.0005466565f), Q31(-0.0005677802f), Q31(-0.0005870930f), Q31(-0.0006132747f),
    Q31(-0.0006312493f), Q31(-0.0006540333f), Q31(-0.0006777690f), Q31(-0.0006941614f),
    Q31(-0.0007157736f), Q31(-0.0007255043f), Q31(-0.0007440941f), Q31(-0.0007490598f),
    Q31(-0.0007681371f), Q31(-0.0007724848f), Q31(-0.0007834332f), Q31(-0.0007779869f),
    Q31(-0.0007803664f), Q31(-0.0007801449f), Q31(-0.0007757977f), Q31(-0.0007630793f),
    Q31(-0.0007530001f), Q31(-0.0007319357f), Q31(-0.0007215391f), Q31(-0.0006917937f),
    Q31(-0.0006650415f), Q31(-0.0006341594f), Q31(-0.0005946118f), Q31(-0.0005564576f),
    Q31(-0.0005145572f), Q31(-0.0004606325f), Q31(-0.0004095121f), Q31(-0.0003501175f),
    Q31(-0.0002896981f), Q31(-0.0002098337f), Q31(-0.0001446380f), Q31(-0.0000617334f),
    Q31( 0.0000134949f), Q31( 0.0001094383f), Q31( 0.0002043017f), Q31( 0.0002949531f),
    Q31( 0.0004026540f), Q31( 0.0005107388f), Q31( 0.0006239376f), Q31( 0.0007458025f),
    Q31( 0.0008608443f), Q31( 0.0009885988f), Q31( 0.0011250155f), Q31( 0.0012577884f),
    Q31( 0.0013902494f), Q31( 0.0015443219f), Q31( 0.0016868083f), Q31( 0.0018348265f),
    Q31( 0.0019841140f), Q31( 0.0021461583f), Q31( 0.0023017254f), Q31( 0.0024625616f),
    Q31( 0.0026201758f), Q31( 0.0027870464f), Q31( 0.0029469447f), Q31( 0.0031125420f),
    Q31( 0.0032739613f), Q31( 0.0034418874f), Q31( 0.0036008268f), Q31( 0.0037603922f),
    Q31( 0.0039207432f), Q31( 0.0040819753f), Q31( 0.0042264269f), Q31( 0.0043730719f),
    Q31( 0.0045209852f), Q31( 0.0046606460f), Q31( 0.0047932560f), Q31( 0.0049137603f),
    Q31( 0.0050393022f), Q31( 0.0051407353f), Q31( 0.0052461166f), Q31( 0.0053471681f),
    Q31( 0.0054196775f), Q31( 0.0054876040f), Q31( 0.0055475714f), Q31( 0.0055938023f),
    Q31( 0.0056220643f), Q31( 0.0056455196f), Q31( 0.0056389199f), Q31( 0.0056266114f),
    Q31( 0.0055917128f), Q31( 0.0055404363f), Q31( 0.0054753783f), Q31( 0.0053838975f),
    Q31( 0.0052715758f), Q31( 0.0051382275f), Q31( 0.0049839687f), Q31( 0.0048109469f),
    Q31( 0.0046039530f), Q31( 0.0043801861f), Q31( 0.0041251642f), Q31( 0.0038456408f),
    Q31( 0.0035401246f), Q31( 0.0032091885f), Q31( 0.0028446757f), Q31( 0.0024508540f),
    Q31( 0.0020274176f), Q31( 0.0015784682f), Q31( 0.0010902329f), Q31( 0.0005832264f),
    Q31( 0.0000276045f), Q31(-0.0005464280f), Q31(-0.0011568135f), Q31(-0.0018039472f),
    Q31(-0.0024826723f), Q31(-0.0031933778f), Q31(-0.0039401124f), Q31(-0.0047222596f),
    Q31(-0.0055337211f), Q31(-0.0063792293f), Q31(-0.0072615816f), Q31(-0.0081798233f),
    Q31(-0.0091325329f), Q31(-0.0101150215f), Q31(-0.0111315548f), Q31(-0.0121849995f),
    Q31( 0.0132718220f), Q31( 0.0143904666f), Q31( 0.0155405553f), Q31( 0.0167324712f),
    Q31( 0.0179433381f), Q31( 0.0191872431f), Q31( 0.0204531793f), Q31( 0.0217467550f),
    Q31( 0.0230680169f), Q31( 0.0244160992f), Q31( 0.0257875847f), Q31( 0.0271859429f),
    Q31( 0.0286072173f), Q31( 0.0300502657f), Q31( 0.0315017608f), Q31( 0.0329754081f),
    Q31( 0.0344620948f), Q31( 0.0359697560f), Q31( 0.0374812850f), Q31( 0.0390053679f),
    Q31( 0.0405349170f), Q31( 0.0420649094f), Q31( 0.0436097542f), Q31( 0.0451488405f),
    Q31( 0.0466843027f), Q31( 0.0482165720f), Q31( 0.0497385755f), Q31( 0.0512556155f),
    Q31( 0.0527630746f), Q31( 0.0542452768f), Q31( 0.0557173648f), Q31( 0.0571616450f),
    Q31( 0.0585915683f), Q31( 0.0599837480f), Q31( 0.0613455171f), Q31( 0.0626857808f),
    Q31( 0.0639715898f), Q31( 0.0652247106f), Q31( 0.0664367512f), Q31( 0.0676075985f),
    Q31( 0.0687043828f), Q31( 0.0697630244f), Q31( 0.0707628710f), Q31( 0.0717002673f),
    Q31( 0.0725682583f), Q31( 0.0733620255f), Q31( 0.0741003642f), Q31( 0.0747452558f),
    Q31( 0.0753137336f), Q31( 0.0758008358f), Q31( 0.0761992479f), Q31( 0.0764992170f),
    Q31( 0.0767093490f), Q31( 0.0768173975f), Q31( 0.0768230011f), Q31( 0.0767204924f),
    Q31( 0.0765050718f), Q31( 0.0761748321f), Q31( 0.0757305756f), Q31( 0.0751576255f),
    Q31( 0.0744664394f), Q31( 0.0736406005f), Q31( 0.0726774642f), Q31( 0.0715826364f),
    Q31( 0.0703533073f), Q31( 0.0689664013f), Q31( 0.0674525021f), Q31( 0.0657690668f),
    Q31( 0.0639444805f), Q31( 0.0619602779f), Q31( 0.0598166570f), Q31( 0.0575152691f),
    Q31( 0.0550460034f), Q31( 0.0524093821f), Q31( 0.0495978676f), Q31( 0.0466303305f),
    Q31( 0.0434768782f), Q31( 0.0401458278f), Q31( 0.0366418116f), Q31( 0.0329583930f),
    Q31( 0.0290824006f), Q31( 0.0250307561f), Q31( 0.0207997072f), Q31( 0.0163701258f),
    Q31( 0.0117623832f), Q31( 0.0069636862f), Q31( 0.0019765601f), Q31(-0.0032086896f),
    Q31(-0.0085711749f), Q31(-0.0141288827f), Q31(-0.0198834129f), Q31(-0.0258227288f),
    Q31(-0.0319531274f), Q31(-0.0382776572f), Q31(-0.0447806821f), Q31(-0.0514804176f),
    Q31(-0.0583705326f), Q31(-0.0654409853f), Q31(-0.0726943300f), Q31(-0.0801372934f),
    Q31(-0.0877547536f), Q31(-0.0955533352f), Q31(-0.1035329531f), Q31(-0.1116826931f),
    Q31(-0.1200077984f), Q31(-0.1285002850f), Q31(-0.1371551761f), Q31(-0.1459766491f),
    Q31(-0.1549607071f), Q31(-0.1640958855f), Q31(-0.1733808172f), Q31(-0.1828172548f),
    Q31(-0.1923966745f), Q31(-0.2021250176f), Q31(-0.2119735853f), Q31(-0.2219652696f),
    Q31(-0.2320690870f), Q31(-0.2423016884f), Q31(-0.2526480309f), Q31(-0.2631053299f),
    Q31(-0.2736634040f), Q31(-0.2843214189f), Q31(-0.2950716717f), Q31(-0.3059098575f),
    Q31(-0.3168278913f), Q31(-0.3278113727f), Q31(-0.3388722693f), Q31(-0.3499914122f),
    Q31( 0.3611589903f), Q31( 0.3723795546f), Q31( 0.3836350013f), Q31( 0.3949211761f),
    Q31( 0.4062317676f), Q31( 0.4175696896f), Q31( 0.4289119920f), Q31( 0.4402553754f),
    Q31( 0.4515996535f), Q31( 0.4629308085f), Q31( 0.4742453214f), Q31( 0.4855253091f),
    Q31( 0.4967708254f), Q31( 0.5079817500f), Q31( 0.5191234970f), Q31( 0.5302240895f),
    Q31( 0.5412553448f), Q31( 0.5522051258f), Q31( 0.5630789140f), Q31( 0.5738524131f),
    Q31( 0.5845403235f), Q31( 0.5951123086f), Q31( 0.6055783538f), Q31( 0.6159109932f),
    Q31( 0.6261242695f), Q31( 0.6361980107f), Q31( 0.6461269695f), Q31( 0.6559016302f),
    Q31( 0.6655139880f), Q31( 0.6749663190f), Q31( 0.6842353293f), Q31( 0.6933282376f),
    Q31( 0.7022388719f), Q31( 0.7109410426f), Q31( 0.7194462634f), Q31( 0.7277448900f),
    Q31( 0.7358211758f), Q31( 0.7436827863f), Q31( 0.7513137456f), Q31( 0.7587080760f),
    Q31( 0.7658674865f), Q31( 0.7727780881f), Q31( 0.7794287519f), Q31( 0.7858353120f),
    Q31( 0.7919735841f), Q31( 0.7978466413f), Q31( 0.8034485751f), Q31( 0.8087695004f),
    Q31( 0.8138191270f), Q31( 0.8185776004f), Q31( 0.8230419890f), Q31( 0.8272275347f),
    Q31( 0.8311038457f), Q31( 0.8346937361f), Q31( 0.8379717337f), Q31( 0.8409541392f),
    Q31( 0.8436238281f), Q31( 0.8459818469f), Q31( 0.8480315777f), Q31( 0.8497805198f),
    Q31( 0.8511971524f), Q31( 0.8523047035f), Q31( 0.8531020949f), Q31( 0.8535720573f),
    Q31( 0.8537385600f),
};

static av_cold void aacsbr_tableinit(void)
{
    int n;
    for (n = 1; n < 320; n++)
        sbr_qmf_window_us[320 + n] = sbr_qmf_window_us[320 - n];
    sbr_qmf_window_us[384] = -sbr_qmf_window_us[384];
    sbr_qmf_window_us[512] = -sbr_qmf_window_us[512];

    for (n = 0; n < 320; n++)
        sbr_qmf_window_ds[n] = sbr_qmf_window_us[2*n];
}

#endif /* AVCODEC_AACSBR_TABLEGEN_COMMON_H */
