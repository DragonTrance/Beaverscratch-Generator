/*
	C-code file header, constructed by Cyanosis (AKA Dragon Trance)
	No licensing. Permission is allowed to make open-source / creative commons.

	Used between projects, may not be up-to-date.
	Last Update: March 30th, 2024
*/

#ifndef _DEF_CONSOLE_H
#define _DEF_CONSOLE_H

#include <stdio.h>
#include <inttypes.h>
#include <Windows.h>	//can just be wincon.h but compiler may not enjoy that
#include "../Utils/string.h"
#include "../Utils/debug.h"


/// <summary>
/// <para>If a console was allocated with Console_Allocate, this will contain the file stream of the console. Otherwise, it will be NULL.</para>
/// <para>See Also: <seealso cref="Console_Allocate"/>, <seealso cref="Console_Free"/></para>
/// </summary>
extern FILE* ConsoleStream;

/// <summary>
/// <para>Requests Windows to allocate a new console, and opens the filestream to the new console if it was successful.</para>
/// <para>See Also: <seealso cref="Console_Free"/></para>
/// </summary>
/// 
/// <returns>
/// <para>A pointer to the new console stream, or NULL if the process was unable to allocate/attach a console.</para>
/// <para><c>FILE* ConsoleStream</c> should also contain the pointer; it can be used instead of this return to see if a console was ever allocated.</para>
/// </returns>
FILE* Console_Allocate();

#ifdef _DEBUG
#define CONSOLE_ALLOC() Console_Allocate()
#else
#define CONSOLE_ALLOC()
#endif

/// <summary>
/// <para>Closes the console stream and requests Windows to remove the console attatched to the program.</para>
/// <para>See Also: <seealso cref="Console_Allocate"/></para>
/// </summary>
void Console_Free();

#ifdef _DEBUG
#define CONSOLE_FREE() Console_Free()
#else
#define CONSOLE_FREE()
#endif

#endif