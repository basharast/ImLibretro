/* Copyright  (C) 2010-2020 The RetroArch team
*
* ---------------------------------------------------------------------------------------
* The following license statement only applies to this file (file_stream_transforms.h).
* ---------------------------------------------------------------------------------------
*
* Permission is hereby granted, free of charge,
* to any person obtaining a copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation the rights to
* use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
* and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef __LIBRETRO_SDK_FILE_STREAM_TRANSFORMS_H
#define __LIBRETRO_SDK_FILE_STREAM_TRANSFORMS_H

#include <stdint.h>
#include <string.h>
#include <retro_common_api.h>
#include <streams/file_stream.h>

RETRO_BEGIN_DECLS

#ifndef SKIP_STDIO_REDEFINES

#define FILE RFILE

#undef fopen
#undef fclose
#undef ftell
#undef fseek
#undef fread
#undef fgets
#undef fgetc
#undef fwrite
#undef fputc
#undef fflush
#undef fprintf
#undef ferror
#undef feof
#undef fscanf

#define fopen rfopen
#define fclose rfclose
#define ftell rftell
#define fseek rfseek
#define fread rfread
#define fgets rfgets
#define fgetc rfgetc
#define fwrite rfwrite
#define fputc rfputc
#define fflush rfflush
#define fprintf rfprintf
#define ferror rferror
#define feof rfeof
#define fscanf rfscanf

#endif

__declspec(dllexport) RFILE* rfopen(const char *path, const char *mode);

__declspec(dllexport) int rfclose(RFILE* stream);

__declspec(dllexport) int64_t rftell(RFILE* stream);

__declspec(dllexport) int64_t rfseek(RFILE* stream, int64_t offset, int origin);

__declspec(dllexport) int64_t rfread(void* buffer,
   size_t elem_size, size_t elem_count, RFILE* stream);

__declspec(dllexport) char *rfgets(char *buffer, int maxCount, RFILE* stream);

__declspec(dllexport) int rfgetc(RFILE* stream);

__declspec(dllexport) int64_t rfwrite(void const* buffer,
   size_t elem_size, size_t elem_count, RFILE* stream);

__declspec(dllexport) int rfputc(int character, RFILE * stream);

__declspec(dllexport) int64_t rfflush(RFILE * stream);

__declspec(dllexport) int rfprintf(RFILE * stream, const char * format, ...);

__declspec(dllexport) int rferror(RFILE* stream);

__declspec(dllexport) int rfeof(RFILE* stream);

__declspec(dllexport) int rfscanf(RFILE * stream, const char * format, ...);

RETRO_END_DECLS

#endif
