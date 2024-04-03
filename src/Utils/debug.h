/*
	C-code file header, constructed by Cyanosis (AKA Dragon Trance)
	No licensing. Permission is allowed to make open-source / creative commons and distribution

	Used between projects, may not be up-to-date.
	Last Update: March 30th, 2024
*/

#ifndef _DEF_DEBUG_H
#define _DEF_DEBUG_H

#define _DEBUG_EXIT
#define _DEBUG_ENTER

#include <stdlib.h>
#include <stdio.h>
#include "string.h"	//Utils/string.h

#define EXIT_WAIT 15

#if defined(_DEBUG) || defined(_DEBUG_ENTER)
#pragma warning(suppress: 4005)
#define _CONSOLE
#define _CONSOLE_FREE() Console_Free()
#define DEBUG_ENTER(Code) Code = 0; Console_Allocate();
#else
#define _CONSOLE_FREE()
#define DEBUG_ENTER(Code) Code = 0;
#endif

#ifdef _CONSOLE
#define PRINT(...) PRINTF(__VA_ARGS__)

#define WARNINGA(message) puts(message)
#define WARNINGW(message) _putws(message)

#define WARNINGFA(message, ...) printf(message, __VA_AGRS__)
#define WARNINGFW(message, ...) wprintf(message, __VA_ARGS__)

#define ALERTA(message, title) puts(message)
#define ALERTW(message, title) _putws(message)

#define ALERTFA_SAFE(message, title, ...) printf(message, __VA_ARGS__)
#define ALERTFW_SAFE(message, title, ...) wprintf(message, __VA_ARGS__)

#define ALERTFA_UNSAFE ALERTFA_SAFE
#define ALERTFW_UNSAFE ALERTFW_SAFE

#else
#include <malloc.h>
#include <math.h>
#define PRINT(...)
#define ALERT_MAXSIZE 255	//0xFF seems safe for an unsafe function lol
#define ALERT_SAFESIZE 1024

#define WARNINGA(message)
#define WARNINGW(message)

#define WARNINGFA(message, ...)
#define WARNINGFW(message, ...)

#define ALERTA(message, title) MessageBoxA(NULL, message, title, 0)
#define ALERTW(message, title) MessageBoxW(NULL, message, title, 0)

///<summary>
/// <para> Edit the ALERT_SAFESIZE macro if you wish for the allocated memory to be larger. </para>
///</summary>
#define ALERTFA_SAFE(message, title, ...) { \
		CHAR* __TEMP__STR__PTR__ = malloc(ALERT_SAFESIZE); \
		int ALERTF_R = 0; \
		if (__TEMP__STR__PTR__) { \
			ALERTF_R = snprintf(__TEMP__STR__PTR__, ALERT_SAFESIZE, message, __VA_ARGS__); \
			ALERTA(__TEMP__STR__PTR__, title); \
			free(__TEMP__STR__PTR__); \
		} \
	}

///<summary>
/// <para> Edit the ALERT_SAFESIZE macro if you wish for the allocated memory to be larger. </para>
///</summary>
#define ALERTFW_SAFE(message, title, ...) { \
		WCHAR* __TEMP__STR__PTR__ = malloc(ALERT_SAFESIZE); \
		int ALERTF_R = 0; \
		if (__TEMP__STR__PTR__) { \
			ALERTF_R = snprintf(__TEMP__STR__PTR__, ALERT_SAFESIZE, message, __VA_ARGS__); \
			ALERTW(__TEMP__STR__PTR__, title); \
			free(__TEMP__STR__PTR__); \
		} \
	}


///<summary>
/// <para> Edit the ALERT_MAXSIZE macro if you wish for the allocated memory to be larger (or just append null bytes). </para>
/// <para> This can be used instead of ALERTF_SAFE if you're desperate for speed, or if you just wanna show off your niche knowledge. </para>
///</summary>
#define ALERTFA_UNSAFE(message, title, ...) { \
		__pragma(warning(suppress: 6255 6386)) \
		CHAR* __TEMP__STR__PTR__ = alloca(min(sizeof(message), ALERT_MAXSIZE)); \
		int ALERTF_R = SNPRINTF(__TEMP__STR__PTR__, min(sizeof(message), ALERT_MAXSIZE), message, __VA_ARGS__); \
		ALERTA(__TEMP__STR__PTR__, title); \
	}

///<summary>
/// <para> Edit the ALERT_MAXSIZE macro if you wish for the allocated memory to be larger (or just append null bytes). </para>
/// <para> This can be used instead of ALERTF_SAFE if you're desperate for speed, or if you just wanna show off your niche knowledge. </para>
///</summary>
#define ALERTFW_UNSAFE(message, title, ...) { \
		__pragma(warning(suppress: 6255 6386)) \
		WCHAR* __TEMP__STR__PTR__ = alloca(min(sizeof(message), ALERT_MAXSIZE)); \
		int ALERTF_R = SNPRINTF(__TEMP__STR__PTR__, min(sizeof(message), ALERT_MAXSIZE), message, __VA_ARGS__); \
		ALERTW(__TEMP__STR__PTR__, title); \
	}
#endif

#ifdef _UNICODE
#define WARNING WARNINGW
#define ALERT ALERTW
#define ALERTF_SAFE ALERTFW_SAFE
///<summary>
/// <para> For info on alloca, see debug.h (where this macro is defined) </para>
///</summary>
#define ALERTF_UNSAFE ALERTFW_UNSAFE
#else
#define WARNING WARNINGA
#define ALERT ALERTA
#define ALERTF_SAFE ALERTFA_SAFE
///<summary>
/// <para> For info on alloca, see debug.h (where this macro is defined) </para>
///</summary>
#define ALERTF_UNSAFE ALERTFA_UNSAFE
#endif

/**** ALERTF MACRO ****\
If _CONSOLE is defined, this is simply a macro for printf().
If _CONSOLE is undefined, this formats a temporary message with snprintf for a new MessageBox alert, and SHOULD NOT be used excessively.
For the safe version, use ALERTF_SAFE instead.

ALERTF_UNSAFE relies on the CPU / stack instead of RAM to allocate temporary memory.
This is almost always safe, however precaution must be met to ensure there's no segmentation fault.
If you're feeling rebellious, increase ALERT_MAXSIZE. Just know that most modern CPUs have around 1mb of stack space.

For more info on alloca, see below:
	https://man7.org/linux/man-pages/man3/alloca.3.html
	https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/alloca
	https://stackoverflow.com/questions/1018853
	https://www.reddit.com/r/C_Programming/comments/g60u8b
*/

///<summary>
/// <para> For info on alloca, see debug.h (where this macro is defined) </para>
///</summary>
#define ALERTFA(message, title, ...) ALERTFA_UNSAFE(message, title, __VA_ARGS__)
///<summary>
/// <para> For info on alloca, see debug.h (where this macro is defined) </para>
///</summary>
#define ALERTFW(message, title, ...) ALERTFW_UNSAFE(message, title, __VA_ARGS__)
#ifdef _UNICODE
///<summary>
/// <para> For info on alloca, see debug.h (where this macro is defined) </para>
///</summary>
#define ALERTF ALERTFW
#else
///<summary>
/// <para> For info on alloca, see debug.h (where this macro is defined) </para>
///</summary>
#define ALERTF ALERTFA
#endif

#if defined(_DEBUG) || defined(_DEBUG_EXIT)
#define DEBUG_EXIT(exit_code) {\
		ALERTF(TEXT("Reached the end of the program with code %d (%016X). The program will automatically exit in ") TEXT(NUMBERSTRING(EXIT_WAIT)) TEXT(" seconds.\n"), \
			TEXT("Program Status"), exit_code, exit_code); \
		Sleep(EXIT_WAIT * 1000); \
		_CONSOLE_FREE(); \
		return exit_code; \
	}
#else
#define DEBUG_EXIT(exit_code) { _CONSOLE_FREE(); return exit_code; }
#endif

#endif
