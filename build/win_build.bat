pushd ..
if not exist "bin" mkdir "bin"
gcc -O2 -I"include" "src\*.c" -o "bin\aether.exe"
popd