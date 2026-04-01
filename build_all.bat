@echo off
if not exist Compiled mkdir Compiled

echo Building BasicConcepts...
gcc BasicConcepts/Macros.c -o Compiled/Macros.exe
gcc BasicConcepts/MacrosRefined.c -o Compiled/MacrosRefined.exe
gcc BasicConcepts/MemoryManagement.c -o Compiled/MemoryManagement.exe
gcc BasicConcepts/PointersArrays.c -o Compiled/PointersArrays.exe
gcc BasicConcepts/StructsTypedefs.c -o Compiled/StructsTypedefs.exe

echo Building RaylibHello...
gcc RaylibHelloWorld/RaylibHello.c -o Compiled/RaylibHello.exe -I. -Lraylib/lib -lraylib -lopengl32 -lgdi32 -lwinmm -luser32 -lshell32

echo Build Complete! Outputs are in the Compiled/ folder.
