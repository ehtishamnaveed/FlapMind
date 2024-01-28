@echo off
:menu
echo.
echo Select an option:
echo 1. Build
echo 2. Run
echo 3. Clean
echo Press 'Esc' to exit

choice /c 123q /n /m "Enter your choice: "

if errorlevel 4 goto :exit
if errorlevel 3 call :clean_project
if errorlevel 2 call :run_project
if errorlevel 1 call :build_project

goto :menu

:build_project
    make
    goto :eof

:run_project
    make run
    goto :eof

:clean_project
    make clean
    goto :eof

:exit
echo Exiting.
