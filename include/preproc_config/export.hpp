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

#ifndef PREPROC_CONFIG_EXPORT_HPP
#define PREPROC_CONFIG_EXPORT_HPP

#if defined _WIN32 || defined __CYGWIN__
#  ifdef WINDOWS_EXPORT_SYMBOLS
#    ifdef __GNUC__
#      define API_EXPORT __attribute__((dllexport))
#      define API_IMPORT __attribute__((dllimport))
#    else // __GNUC__
#      define API_EXPORT __declspec(dllexport)
#      define API_IMPORT __declspec(dllimport)
#    endif // __GNUC__
#  else    // WINDOWS_EXPORT_SYMBOLS
#    ifdef __GNUC__
#      define API_EXPORT __attribute__((dllimport))
#      define API_IMPORT __attribute__((dllimport))
#    else // __GNUC__
#      define API_EXPORT __declspec(dllimport)
#      define API_IMPORT __declspec(dllimport)
#    endif // __GNUC__
#  endif   // WINDOWS_EXPORT_SYMBOLS
#else      // _WIN32 || __CYGWIN__
#  if __GNUC__ >= 4
#    define API_EXPORT __attribute__((visibility("default")))
#    define API_IMPORT __attribute__((visibility("hidden")))
#  else // __GNUC__ >= 4
#    define API_EXPORT
#    define API_IMPORT
#  endif // __GNUC__ >= 4
#endif   // _WIN32 || __CYGWIN__

#endif // PREPROC_CONFIG_EXPORT_HPP