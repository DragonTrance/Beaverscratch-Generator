#include "console.h"

FILE* ConsoleStream = NULL;

FILE* Console_Allocate()
{
	//Request a new console. Returns NULL if it wasn't successful.
	if (!AllocConsole()) {
		return NULL;
	}

	//Open the filestream and write to the console. If unsuccessful, free the console
	if (freopen_s(&ConsoleStream, "CONOUT$", "w", stdout)) {
		FreeConsole();
		ConsoleStream = NULL;
	}
	return ConsoleStream;
}

void Console_Free()
{
	//fclose will error if ConsoleStream is null
	if (!ConsoleStream) return;
	fclose(ConsoleStream);
	FreeConsole();
	ConsoleStream = NULL;
}


