@echo off
echo Compiling College Exam Timetable Generation project...
"C:\msys64\ucrt64\bin\gcc.exe" -Wall -Wextra main.c input.c conflict.c greedy.c backtracking.c display.c -o timetable.exe
if %ERRORLEVEL% EQU 0 (
    echo.
    echo =======================================
    echo   Compilation Successful! (timetable.exe)
    echo =======================================
) else (
    echo.
    echo =======================================
    echo   Compilation Failed!
    echo =======================================
)
