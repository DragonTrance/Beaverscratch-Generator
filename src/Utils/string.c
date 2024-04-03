#include "string.h"
LPSTR StringIfNotPointedToNullA(LPSTR ref)
{
	if (!ref || !*ref) return NULL;
	return ref;
}
LPWSTR StringIfNotPointedToNullW(LPWSTR ref)
{
	if (!ref || !*ref) return NULL;
	return ref;
}

LPSTR StringOrNothingA(LPSTR ref)
{
	if (!ref || !*ref) return "";
	return ref;
}
LPWSTR StringOrNothingW(LPWSTR ref)
{
	if (!ref || !*ref) return L"";
	return ref;
}

void PrintStringArrayA(LPSTR* starr, size_t stsize, LPSTR delimiter, BOOL newline)
{
	LPSTR _delim = StringOrNothingA(delimiter);
	for (size_t i = 0; i < stsize - 1; i++) {
		printf("%s%s", starr[i], _delim);
	}
	printf("%s", starr[stsize - 1]);
	if (newline) printf("\n");
}
void PrintStringArrayW(LPWSTR* starr, size_t stsize, LPWSTR delimiter, BOOL newline)
{
	LPWSTR _delim = StringOrNothingW(delimiter);
	for (size_t i = 0; i < stsize - 1; i++) {
		wprintf(L"%s%s", starr[i], _delim);
	}
	wprintf(L"%s", starr[stsize - 1]);
	if (newline) wprintf(L"\n");
}

LPSTR StringAppendA(LPSTR src, LPSTR appending)
{
	if (!appending) return _strdup(src);
	else if (!src) return _strdup(appending);
	else return NULL;

	//Getting the length of both strings
	size_t src_size = strlen(src) * sizeof(src[0]);
	size_t append_size = strlen(appending) * sizeof(appending[0]);

	//Allocating memory for a new string
	size_t dst_size = src_size + append_size;
	LPSTR dst = malloc((dst_size * sizeof(src[0])) + sizeof(src[0]));
	if (!dst) return NULL;

	//Copying src to dst, then append
	memcpy(dst, src, src_size * sizeof(src[0]));
	memcpy(&dst[src_size], appending, append_size * sizeof(appending[0]));

	//Null-terminate the string and return
	dst[dst_size] = 0;
	return dst;
}
LPWSTR StringAppendW(LPWSTR src, LPWSTR appending)
{
	if (!appending) return _wcsdup(src);
	else if (!src) return _wcsdup(appending);
	else return NULL;

	//Getting the length of both strings
	size_t src_size = wcslen(src);
	size_t append_size = wcslen(appending);

	//Allocating memory for a new string
	size_t dst_size = src_size + append_size;
	LPWSTR dst = malloc((dst_size * sizeof(src[0])) + sizeof(src[0]));
	if (!dst) return NULL;

	//Copying src to dst, then append
	memcpy(dst, src, src_size * sizeof(src[0]));
	memcpy(&dst[src_size], appending, append_size * sizeof(appending[0]));

	//Null-terminate the string and return
	dst[dst_size] = 0;
	return dst;
}
