pushd ..
if not exist "bin" mkdir "bin"
gcc -O2 -I"include" "src\*.c" -o "bin\aether.exe" exit /b 1
popd
exit /b 0