pushd ..
if not exist "bin" mkdir "bin"
gcc -g -O0 -I"include" "src\*.c" -o "bin\aetherDEBUG.exe"
popd