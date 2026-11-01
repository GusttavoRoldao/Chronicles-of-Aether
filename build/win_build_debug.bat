pushd ..
if not exist "bin" mkdir "bin"
gcc -g -O0 -I"include" "src\*.c" -o "bin\aetherDEBUG.exe" || exit /b 1
popd
exit /b 0