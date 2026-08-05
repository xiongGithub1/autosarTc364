@echo off
rem Switch all DaVinci docs to image bed (CDN) mode.
cd /d "%~dp0"
powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0toggle_image_source.ps1" -Mode cdn
pause
