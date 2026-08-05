@echo off
rem Switch all DaVinci docs to local image mode.
cd /d "%~dp0"
powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0toggle_image_source.ps1" -Mode local
pause
