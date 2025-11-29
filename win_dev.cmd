@echo off
call zig.cmd
set "dest=%APPDATA%\Godot\app_userdata\Tower Networking Inc\mods"
if not exist "%dest%" mkdir "%dest%"
move ".zig\luajit\luajit.elf" "%dest%\luajit.elf"