/*
	C-code file header, constructed by Cyanosis (AKA Dragon Trance)
	No licensing. Permission is allowed to make open-source / creative commons.

	Used between projects, may not be up-to-date.
	Last Update: April 2nd, 2024
*/

#ifndef _DEF_STRING_H
#define _DEF_STRING_H

#include <stdio.h>
#include <Windows.h>
#include "../IncludeBasic/unicode.h"	//IncludeBasic/unicode.h

#define _NUMBERSTRING(contents) #contents
#define NUMBERSTRING(contents) _NUMBERSTRING(contents)

LPSTR StringIfNotPointedToNullA(LPSTR ref);
LPWSTR StringIfNotPointedToNullW(LPWSTR ref);
#ifdef _UNICODE
/// <summary>
/// <para>If <c>ref</c> is NULL, or if the first character is a null-byte, this function returns NULL. Otherwise, it will return the <c>ref</c>.</para>
/// <para>Primarily for printing, as trying to format a NULL string will print "(null)".</para>
/// <para> See Also: <seealso cref="StringIfNotPointedToNullA"/>, <seealso cref="StringIfNotPointedToNullW"/>, <seealso cref="StringOrNothing"/></para>
/// </summary>
/// <param name="ref">The pointer to the string.</param>
/// <returns>NULL if <c>ref</c> is NULL, or if the first byte of <c>ref</c> is zero. Otherwise, returns <c>ref</c>.</returns>
#define StringIfNotPointedToNull StringIfNotPointedToNullW
#else
/// <summary>
/// <para>If <c>ref</c> is NULL, or if the first character is a null-byte, this function returns NULL. Otherwise, it will return the <c>ref</c>.</para>
/// <para>Primarily for printing, as trying to format a NULL string will print "(null)".</para>
/// <para> See Also: <seealso cref="StringIfNotPointedToNullA"/>, <seealso cref="StringIfNotPointedToNullW"/>, <seealso cref="StringOrNothing"/></para>
/// </summary>
/// <param name="ref">The pointer to the string.</param>
/// <returns>NULL if <c>ref</c> is NULL, or if the first byte of <c>ref</c> is zero. Otherwise, returns <c>ref</c>.</returns>
#define StringIfNotPointedToNull StringIfNotPointedToNullA
#endif

LPSTR StringOrNothingA(LPSTR ref);
LPWSTR StringOrNothingW(LPWSTR ref);
#ifdef _UNICODE
/// <summary>
/// <para>If <c>ref</c> is NULL, or if the first character is a null-byte, this function will return a string with a single null character. Otherwise, it will return the <c>ref</c>.</para>
/// <para>Primarily for printing, as trying to format a NULL string will print "(null)".</para>
/// <para> See Also: <seealso cref="StringOrNothingA"/>, <seealso cref="StringOrNothingW"/>, <seealso cref="StringIfNotPointedToNull"/></para>
/// </summary>
/// <param name="ref">The pointer to the string.</param>
/// <returns>A pointer to a single null-byte character if <c>ref</c> is NULL, or if the first byte of <c>ref</c> is zero. Otherwise, returns <c>ref</c>.</returns>
#define StringOrNothing StringOrNothingW
#else
/// <summary>
/// <para>If <c>ref</c> is NULL, or if the first character is a null-byte, this function will return a string with a single null character. Otherwise, it will return the <c>ref</c>.</para>
/// <para>Primarily for printing, as trying to format a NULL string will print "(null)".</para>
/// <para> See Also: <seealso cref="StringOrNothingA"/>, <seealso cref="StringOrNothingW"/>, <seealso cref="StringIfNotPointedToNull"/></para>
/// </summary>
/// <param name="ref">The pointer to the string.</param>
/// <returns>A pointer to a single null-byte character if <c>ref</c> is NULL, or if the first byte of <c>ref</c> is zero. Otherwise, returns <c>ref</c>.</returns>
#define StringOrNothing StringOrNothingA
#endif

void PrintStringArrayA(LPSTR* starr, size_t stsize, LPSTR delimiter, BOOL newline);
void PrintStringArrayW(LPWSTR* starr, size_t stsize, LPWSTR delimiter, BOOL newline);
#ifdef _UNICODE
/// <summary>
/// <para>Prints an array of strings to the console, with an optional separator.</para>
/// </summary>
/// <param name="starr">The array of strings. Any item can be NULL.</param>
/// <param name="stsize">The size of the array.</param>
/// <param name="delimiter">An optional string to separate each item in the array.</param>
/// <param name="newline">If TRUE, there will be an extra newline in the console after the list was printed.</param>
#define PrintStringArray PrintStringArrayW
#else
/// <summary>
/// <para>Prints an array of strings to the console, with an optional separator.</para>
/// </summary>
/// <param name="starr">The array of strings. Any item can be NULL.</param>
/// <param name="stsize">The size of the array.</param>
/// <param name="delimiter">An optional string to separate each item in the array.</param>
/// <param name="newline">If TRUE, there will be an extra newline in the console after the list was printed.</param>
#define PrintStringArray PrintStringArrayA
#endif

LPSTR StringAppendA(LPSTR src, LPSTR appending);
LPWSTR StringAppendW(LPWSTR src, LPWSTR appending);
#ifdef _UNICODE
/// <summary>
/// <para>!! Allocation Function !!</para>
/// <para>Allocates a new string, where <c>src</c> is at the beginning of the string, and <c>appending</c> is placed thereafter.</para>
/// </summary>
/// <param name="src">The string to place at the beginning of the newly-allocated string.</param>
/// <param name="appending">The string to place at the end of the newly-allocated string.</param>
/// <returns>
/// A new string, which has <c>src</c> at the front, with <c>appending</c> appended after. If ONLY src, or ONLY appending is not NULL, the string will still be duplicated, unless
/// both parameters are NULL. If there is not enough memory, this returns NULL.
/// </returns>
#define StringAppend StringAppendW
#else
/// <summary>
/// <para>!! Allocation Function !!</para>
/// <para>Allocates a new string, where <c>src</c> is at the beginning of the string, and <c>appending</c> is placed thereafter.</para>
/// </summary>
/// <param name="src">The string to place at the beginning of the newly-allocated string.</param>
/// <param name="appending">The string to place at the end of the newly-allocated string.</param>
/// <returns>
/// A new string, which has <c>src</c> at the front, with <c>appending</c> appended after. If ONLY src, or ONLY appending is not NULL, the string will still be duplicated, unless
/// both parameters are NULL. If there is not enough memory, this returns NULL.
/// </returns>
#define StringAppend StringAppendA
#endif

#endif