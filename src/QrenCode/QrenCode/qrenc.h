/**
 * qrencode - QR Code encoder
 *
 * QR Code encoding tool
 * Copyright (C) 2006-2017 Kentaro Fukuchi <kentaro@fukuchi.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 */
#define HAVE_CONFIG_H 1
#if HAVE_CONFIG_H
# include "config.h"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <errno.h>
#define HAVE_PNG 1
#if HAVE_PNG
#include <png.h>
#endif

#include "qrencode.h"

#include <windows.h>
#include <tchar.h>

//-------------------------------------------------------
//  DEFines
//-------------------------------------------------------

#define QRCODE_TEXT                 "http://www.ppsbbs.tech/"; // Text to encode into QRCode
#define OUT_FILE                    "ppsbbs.bmp" // Output file name
#define OUT_FILE_PIXEL_PRESCALER    8 // Prescaler (number of pixels in bmp file for each QRCode pixel, on each dimension)

#define PIXEL_COLOR_R               0 // Color of bmp pixels
#define PIXEL_COLOR_G               0
#define PIXEL_COLOR_B               0xFF

//-------------------------------------------------------
// BMP defines
typedef unsigned short  WORD;
typedef unsigned long   DWORD;
typedef signed long     LONG;

#define BI_RGB    0L
/*
//#if !definde(BITMAPFILEHEADER) || !definde(BITMAPINFOHEADER)
#pragma pack(push, 2)
typedef struct
{
    WORD    bfType;
    DWORD   bfSize;
    WORD    bfReserved1;
    WORD    bfReserved2;
    DWORD   bfOffBits;
} BITMAPFILEHEADER;

typedef struct
{
    DWORD      biSize;
    LONG       biWidth;
    LONG       biHeight;
    WORD       biPlanes;
    WORD       biBitCount;
    DWORD      biCompression;
    DWORD      biSizeImage;
    LONG       biXPelsPerMeter;
    LONG       biYPelsPerMeter;
    DWORD      biClrUsed;
    DWORD      biClrImportant;
} BITMAPINFOHEADER;

#pragma pack(pop)
//#endif //#if !definde(BITMAPFILEHEADER) || !definde(BITMAPINFOHEADER)
*/
//-------------------------------------------------------

int qrencode_tmain_bmp(int argc, _TCHAR ** argv);

int qrencode_tmain(int argc, _TCHAR ** argv);

