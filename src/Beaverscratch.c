#include <stdio.h>
#include <stdlib.h>

#include "Utils/debug.h"
#include "Utils/string.h"
#include "ClassesAndInit/console.h"

void main()
{
    //Random Seed...
    srand(GetTickCount64());
    STRING cCmdLine = GETCOMMANDLINE();

    CHAR_T current;

    //The windows terminal will always tell the program the filepath it's being executed from
    //We don't want this, so ignore everything until we find the last quotation
    if (*cCmdLine == TEXT('"')) {
        do {
            cCmdLine = &cCmdLine[1];
            current = *cCmdLine;
        } while (current && current != TEXT('"'));

        //Going further by two characters to ignore the last quotation and the leading space
        if (!current) return;
        cCmdLine = &cCmdLine[1];    //quotation
        if (!*cCmdLine) return;
        cCmdLine = &cCmdLine[1];    //space
    }

    //Print out the contents to show the user what's actually being printed.
    //This is in case the above step was unintentional, but it's also just here so the result's prettier
    PUTS(cCmdLine);

    //this is bs (beaverscratch)
    //We're going through each character from the arguments and relying on the console to become the buffer of our output
    //This code is safe as-is, but if your goal instead is to write to a different buffer, make sure you're allocating memory correctly
    current = *cCmdLine;
    while (current) {
        if (!ISALPHA(current)) goto CONTINUE;

        //This conversion is here just so we don't have to make really specific comparisons for the character
        BOOL was_upper = ISUPPER(current);
        current = TOLOWER(current);

        //I wonder if this is safe for special unicode characters (umlauts)
        if (rand() % 2) current--;
        else current++;

        //shrimply making them loop. I know could mess with bitfields but i'm not sure if that would fuck up specific unicode stuff
        if (current < TEXT('a')) current = TEXT('z');
        else if (current > TEXT('z')) current = TEXT('a');

        if (was_upper) current = TOUPPER(current);

    CONTINUE:
        //Printing the character, then resumes to the next one
        FPUTC(current, stdout);
        cCmdLine = &cCmdLine[1];
        current = *cCmdLine;
    }
    FPUTC(TEXT('\n'), stdout);
}
