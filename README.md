# Beaverscratch Generator
 A tool that traslates user input into a cypher called Beaverscratch.
 
 Beaverscratch is a cypher code from a PC game called Shipwrecked 64, where letters are simply shifted to the ascending or descending letter in the alphabet. This program was made to have fun with the process, but otherwise has no other uses.
 
# Compiling
 This was compiled with Microsoft Visual Studio 2022. You should be able to open the project file and run it without issues.
 
 For other users, however, here is the compiler arguments:
 `/permissive- /ifcOutput "Beaverscratch\Release\" /GS /TC /analyze- /W3 /Gy /Zc:wchar_t /Gm- /O2 /Ob1 /sdl- /Fd"Beaverscratch\Release\vc143.pdb" /Zc:inline /fp:precise /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /Gd /Oy /Oi /MD /FC /Fa"Beaverscratch\Release\" /EHsc /nologo /Fo"Beaverscratch\Release\" /Ot /Fp"Beaverscratch\Release\bscratch.pch" /diagnostics:column`
 
 Here are the linker arguments:
 `/OUT:"<out>" /MANIFEST /NXCOMPAT /DYNAMICBASE "kernel32.lib" "user32.lib" "gdi32.lib" "winspool.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "odbc32.lib" "odbccp32.lib" /MACHINE:X86 /OPT:REF /SAFESEH /SUBSYSTEM:CONSOLE /MANIFESTUAC:"level='asInvoker' uiAccess='false'" /ManifestFile:"Beaverscratch\Release\bscratch.exe.intermediate.manifest" /OPT:ICF /ERRORREPORT:PROMPT /ILK:"Beaverscratch\Release\bscratch.ilk" /NOLOGO /TLBID:1`
 
# Execution
 Quick Execution: `.\bscratch.exe "<contents here>"`

 Open bscratch.exe through your terminal (or program of choice) and specify any arguments thereafter. These arguments are then passed to the program, where it will shift the letters randomly, and then output the result to a console.

 If using the windows terminal, you will get consistent results if you surround the text with double-quotes, but they are not required to let the program run properly.

# FAQ
### The program says I'm missing a DLL
- You can download the C++ distributables, they're the main reason people are missing something. You can download them here: https://learn.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist?view=msvc-170#latest-microsoft-visual-c-redistributable-version

### I entered some text, but the program didn't output anything
- Try inserting two double-quotes ("") at the start of the commandline arguments. The program is structured to always ignore text until it finds the second quotation, since the Windows terminal will always provide the working directory in its arguments.
