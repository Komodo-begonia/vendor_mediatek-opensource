/*
 * Copyright (C) 2021 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _OS_DEP_H
#define _OS_DEP_H

#include <errno.h>
#include <unistd.h>
#include <stdbool.h>


#ifndef FALSE
#define FALSE    0
#endif
#ifndef TRUE
#define TRUE     1
#endif
#ifndef BOOL
#define BOOL     bool
#endif

typedef unsigned char BYTE;
typedef unsigned char UCHAR;
typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef unsigned int UINT32;
typedef unsigned long long UINT64;
typedef unsigned char* PBYTE;
typedef unsigned char* PUCHAR;
typedef char INT8;
typedef short INT16;
typedef int INT32;
typedef long long INT64;
typedef void VOID;
typedef void* PVOID;


/* LOG_TAG must be defined before log.h */
#ifdef  LOG_TAG
#undef  LOG_TAG
#endif
#define LOG_TAG               "[BT]"

#if defined(MTK_LINUX)

#if defined(MTK_COMMON) && (MTK_COMMON == TRUE)
#define LOGWRAPPER(tag, fmt, args...) printf("%s: " fmt "\n", tag, ## args)
#else
#define LOGWRAPPER(tag, fmt, args...) fprintf(stderr, "%s: " fmt "\n", tag, ## args)
#endif

#define BT_DRIVER_DEBUG       1

#define LOG_ERR(...)       LOGWRAPPER(LOG_TAG,__VA_ARGS__)
#define LOG_WAN(...)       LOGWRAPPER(LOG_TAG,__VA_ARGS__)
#if BT_DRIVER_DEBUG
#define LOG_DBG(...)       LOGWRAPPER(LOG_TAG,__VA_ARGS__)
#define LOG_TRC(f)         ((void)0)
#define LOG_PER(...)       LOGWRAPPER(LOG_TAG,__VA_ARGS__)
#else
#define LOG_DBG(...)          ((void)0)
#define LOG_TRC(f)            ((void)0)
#define LOG_PER(f, ...)       ((void)0)
#endif

#else /* MTK_LINUX */
#include <log/log.h>

#define BT_DRIVER_DEBUG       1
#define LOG_ERR(f, ...)       ALOGE("%s: " f, __FUNCTION__, ##__VA_ARGS__)
#define LOG_WAN(f, ...)       ALOGW("%s: " f, __FUNCTION__, ##__VA_ARGS__)
#if BT_DRIVER_DEBUG
#define LOG_DBG(f, ...)       ALOGD("%s: " f,  __FUNCTION__, ##__VA_ARGS__)
#define LOG_TRC(f)            ALOGW("%s #%d", __FUNCTION__, __LINE__)
#define LOG_PER(f, ...)       ALOGD("" f, ##__VA_ARGS__)
#else
#define LOG_DBG(...)          ((void)0)
#define LOG_TRC(f)            ((void)0)
#define LOG_PER(f, ...)       ((void)0)
#endif
#endif /* MTK_LINUX */
#endif
