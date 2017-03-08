﻿// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.


/****************************************************************************
						Microsoft RPC

                   Discriminated Union Example

    FILE:       unionp.c

    PURPOSE:    Remote procedures that are linked with the server
                side of RPC distributed application

    FUNCTIONS:  UnionParamProc()  - union, discriminant are parameters
                UnionStructProc() - union, discriminant in structure

    COMMENTS:   This distributed application illustrates distriminated
                union.

****************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "dunion.h"    // header file generated by MIDL compiler


void UnionParamProc(IN RPC_BINDING_HANDLE hBinding,
                    DISCRIM_UNION_PARAM_TYPE *up,
                    short                    sDiscrim)
{
    printf_s("sDiscrim = %d, data = ", sDiscrim);
    switch(sDiscrim)
    {
    case 0:
        printf_s("short %d\n", up->sVal);
        break;
    case 1:
        printf_s("float %f\n", up->fVal);
        break;
    case 2:
        printf_s("char %c\n", up->chVal);
        break;
    default:
        printf_s("invalid\n");
        break;
    }
}

void UnionStructProc(IN RPC_BINDING_HANDLE hBinding,
                     DISCRIM_UNION_STRUCT_TYPE *u)
{
    printf_s("sDiscrim = %d, data = ", u->sDiscrim);
    switch(u->sDiscrim)
    {
    case 0:
        printf_s("short %d\n", u->u.sVal);
        break;
    case 1:
        printf_s("float %f\n", u->u.fVal);
        break;
    case 2:
        printf_s("char %c\n", u->u.chVal);
        break;
    default:
        printf_s("invalid\n");
        break;
    }
}

void Shutdown(IN RPC_BINDING_HANDLE hBinding)
{
    RPC_STATUS status;

    printf_s("Calling RpcMgmtStopServerListening\n");
    status = RpcMgmtStopServerListening(NULL);
    printf_s("RpcMgmtStopServerListening returned: 0x%x\n", status);
    if (status)
    {
        exit(status);
    }

    printf_s("Calling RpcServerUnregisterIf\n");
    status = RpcServerUnregisterIf(NULL, NULL, FALSE);
    printf_s("RpcServerUnregisterIf returned 0x%x\n", status);
    if (status)
    {
        exit(status);
    }
}

/* end file dunionp.c */