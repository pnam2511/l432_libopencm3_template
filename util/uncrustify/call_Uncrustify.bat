@echo off

IF (%1)==() GOTO error
dir /b /ad %1 >nul 2>nul && GOTO indentDir
IF NOT EXIST %1 GOTO error
goto indentFile

:indentDir
set searchdir=%1

IF (%2)==() GOTO assignDefaultSuffix
set filesuffix=%2
set filesuffix2=%3

GOTO run

:assignDefaultSuffix
::echo !!!!DEFAULT SUFFIX .c, .h!!!
set filesuffix=c
set filesuffix2=h

:run
FOR /F "tokens=*" %%G IN ('DIR /B /S %searchdir%\*.%filesuffix%') DO (
echo Indenting file "%%G"
"./bin/uncrustify.exe" -f "%%G" -c "./call_Uncrustify.cfg" -o indentoutput.tmp
move /Y indentoutput.tmp "%%G"
)

IF (filesuffix2)==() GOTO ende
FOR /F "tokens=*" %%G IN ('DIR /B /S %searchdir%\*.%filesuffix2%') DO (
echo Indenting file "%%G"
"./bin/uncrustify.exe" -f "%%G" -c "./call_Uncrustify.cfg" -o indentoutput.tmp
move /Y indentoutput.tmp "%%G"

)
GOTO ende

:indentFile
echo Indenting one file %1
"./bin/uncrustify.exe" -f "%1" -c "./call_Uncrustify.cfg" -o indentoutput.tmp
move /Y indentoutput.tmp "%1"


GOTO ende

:error
echo .
echo ERROR: As parameter given directory or file does not exist!
echo Syntax is: call_Uncrustify.bat dirname filesuffix
echo Syntax is: call_Uncrustify.bat filename
echo Example: call_Uncrustify.bat temp cpp
echo .

:ende
