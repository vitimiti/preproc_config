//================================================================================================//
// The MIT License (MIT)
//
// Copyright (c) 2023 Victor Matia <vmatir@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the “Software”), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//================================================================================================//

#ifndef PREPROC_CONFIG_DECLARATION_HPP
#define PREPROC_CONFIG_DECLARATION_HPP

#if defined _WIN32 || defined __CYGWIN__
#  define FAT_POTATO_SOFT_C_DECL      __cdecl
#  define FAT_POTATO_SOFT_CLR_CALL    __clrcall
#  define FAT_POTATO_SOFT_STD_CALL    __stdcall
#  define FAT_POTATO_SOFT_FAST_CALL   __fastcall
#  define FAT_POTATO_SOFT_THIS_CALL   __thiscall
#  define FAT_POTATO_SOFT_VECTOR_CALL __vectorcall
#else // _WIN32 || __CYGWIN__
#  define FAT_POTATO_SOFT_C_DECL
#  define FAT_POTATO_SOFT_CLR_CALL
#  define FAT_POTATO_SOFT_STD_CALL
#  define FAT_POTATO_SOFT_FAST_CALL
#  define FAT_POTATO_SOFT_THIS_CALL
#  define FAT_POTATO_SOFT_VECTOR_CALL
#endif // _WIN32 || __CYGWIN__

#endif // PREPROC_CONFIG_DECLARATION_HPP