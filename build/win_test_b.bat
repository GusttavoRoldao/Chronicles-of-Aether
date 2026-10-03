@echo off
pushd "%~dp0.."
if not exist "bin" mkdir "bin"
gcc -Wall -Wextra -I"include" "build\testeB.c" "build\stubs.c" "src\enemy.c" "src\chest.c" "src\battle.c" -o "bin\testeB.exe"
if exist "bin\testeB.exe" "bin\testeB.exe"
popd
