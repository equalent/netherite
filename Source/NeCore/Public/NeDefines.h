/*
    This file is part of Netherite.

    Netherite is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Netherite is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Netherite.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#pragma region Platform

#define NE_STR( s ) #s

#if defined( _WIN32 )
#	define NE_WINDOWS 1

#	if defined( _WIN64 )
#		define NE_WINDOWS64 1
#		define NE_AMD64 1
#	else
#		define NE_WINDOWS32 1
#	endif

#	define NE_X86 1
#endif

#if defined( __linux__ )
#	define NE_LINUX 1
#	define NE_POSIX 1
#endif

#if defined( __APPLE__ )
#	define NE_APPLE 1
#	define NE_POSIX 1
#endif

#if defined( __FreeBSD__ )
#	define NE_FREEBSD 1
#endif

#if defined( __TOS_MVS__ )
#	define NE_ZOS 1
#endif

#pragma endregion PLATFORM DEFINITIONS


#pragma region Compiler

#if defined( _MSC_VER )
#	define NE_MSVC 1
#elif defined( __GNUC__ )
#	define NE_GCC 1
#elif defined( __clang__ )
#	define NE_CLANG 1
#endif

#if defined( __MINGW32__ ) || defined( __MINGW64__ )
#	error MinGW is not supported
#endif

#pragma endregion COMPILER DEFINITIONS


#pragma region Symbol Visibility

#if NE_WINDOWS
#	if NE_GCC
#		define NE_DLL_EXPORT __attribute__ ( ( dllexport ) )
#		define NE_DLL_IMPORT __attribute__ ( ( dllimport ) )
#		define NE_DLL_LOCAL
#	else
#		define NE_DLL_EXPORT __declspec( dllexport )
#		define NE_DLL_IMPORT __declspec( dllimport )
#		define NE_DLL_LOCAL
#	endif
#elif
#	if defined( NE_GCC ) && ( __GNUC__ >= 4 )
#		define NE_DLL_EXPORT __attribute__ ( ( visibility ( "default" ) ) )
#		define NE_DLL_IMPORT
#		define NE_DLL_LOCAL __attribute__ ( ( visibility ( "hidden" ) ) )
#	else
#		define NE_DLL_EXPORT
#		define NE_DLL_IMPORT
#		define NE_DLL_LOCAL
#	endif
#endif

#pragma endregion SYMBOL VISIBILITY DEFINITIONS