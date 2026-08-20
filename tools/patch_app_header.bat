@echo off
REM Post-build: patch Appl_BootHeader length/crc32 into last364.hex
setlocal
set "HEX=%~1"
if "%HEX%"=="" set "HEX=%CD%\last364.hex"
set "SCRIPT=%~dp0patch_app_header.py"

where python >nul 2>&1
if errorlevel 1 (
  echo [patch_app_header] python not found in PATH
  exit /b 1
)

if not exist "%HEX%" (
  echo [patch_app_header] HEX not found: %HEX%
  exit /b 1
)

python "%SCRIPT%" "%HEX%"
exit /b %ERRORLEVEL%
