@echo off
cls

REM folder containing the exe
REM leave the double \\ at the end of folder paths!!!!
set FFBIN=C:\Users\danielebosetti.hp\Desktop\CO_FormFinding2\trunk\to_package\package_dir\bin\\
REM folder containing the data (input and output)
set FFDATA=C:\Users\danielebosetti.hp\Desktop\CO_FormFinding2\trunk\to_package\package_dir\IO_txt\\
REM the folder containing the setting files
set FFSETTINGS=C:\Users\danielebosetti.hp\Desktop\CO_FormFinding2\trunk\to_package\package_dir\settings\\

REM the input file name
set FILE_INPUT=sampleSIX-003-FM102-F_00.txt


REM don t change below!
set FFEXE=FF-cmd.exe
set FFPARAMS=
set FFPARAMS=%FFPARAMS% APPLICATION_DIR "%FFBIN%"
set FFPARAMS=%FFPARAMS% DATA_DIR "%FFDATA%"
set FFPARAMS=%FFPARAMS% SETTINGS_DIR "%FFSETTINGS%"
set FFPARAMS=%FFPARAMS% FILE_INPUT "%FILE_INPUT%"
set FFPARAMS=%FFPARAMS% FILE_OUTPUT output1.txt
set FFPARAMS=%FFPARAMS% N_ITERATIONS 100
set FFPARAMS=%FFPARAMS% METHOD DR

set RUN_CMD="%FFBIN%%FFEXE%" %FFPARAMS%
echo on
%RUN_CMD%
PAUSE