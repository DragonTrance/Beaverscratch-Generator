/*
	C-code file header, constructed by Cyanosis (AKA Dragon Trance)
	No licensing. Permission is allowed to make open-source / creative commons.

	Used between projects, may not be up-to-date.
	Last Update: April 2nd, 2024
*/

#ifndef _DEF_UNICODE_H
#define _DEF_UNICODE_H

//Remember to put this file at the end of the include list or else the compiler may get angry

#ifdef _UNICODE

#define WINMAIN(n1, n2, n3, n4) wWinMain(_In_ HINSTANCE n1, _In_opt_ HINSTANCE n2, _In_ LPWSTR n3, _In_ int n4)
#define MAIN(...) wWinMain(__VA_ARGS__)

typedef LPWSTR STRING;
typedef WCHAR CHAR_T;

#define PRINTF wprintf
#define PUTS _putws
#define PUTC putwc
#define FPUTC fputwc
#define SNPRINTF _snwprintf
#define STRLEN wcsdup
#define STRDUP wcslen
#define FGETC fgetwc
#define GETCOMMANDLINE GetCommandLineW

#define ISALNUM iswalnum
#define ISALPHA iswalpha
#define ISCNTRL iswcntrl
#define ISDIGIT iswdigit
#define ISXDIGIT iswxdigit
#define ISGRAPH iswgraph
#define ISPRINT iswprint
#define ISLOWER iswlower
#define ISUPPER iswupper
#define ISPUNCT iswpunct
#define ISSPACE iswspace
#define TOLOWER towlower
#define TOUPPER towupper

#else

#define WINMAIN(n1, n2, n3, n4) WinMain(_In_ HINSTANCE n1, _In_opt_ HINSTANCE n2, _In_ LPSTR n3, _In_ int n4)
#define MAIN(...) WinMain(__VA_ARGS__)

typedef LPSTR STRING;
typedef CHAR CHAR_T;

#define PRINTF printf
#define PUTS puts
#define PUTC putc
#define FPUTC fputc
#define SNPRINTF snprintf
#define STRLEN strlen
#define STRDUP strdup
#define FGETC fgetc
#define GETCOMMANDLINE GetCommandLine

#define ISALNUM isalnum
#define ISALPHA isalpha
#define ISCNTRL iswcntrl
#define ISDIGIT isdigit
#define ISXDIGIT isxdigit
#define ISGRAPH isgraph
#define ISPRINT isprint
#define ISLOWER islower
#define ISUPPER isupper
#define ISPUNCT ispunct
#define ISSPACE isspace
#define TOLOWER tolower
#define TOUPPER toupper

#endif

#endif