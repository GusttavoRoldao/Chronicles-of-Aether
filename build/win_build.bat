pushd ..
if not exist "bin" mkdir "bin"
gcc -I"include" "src\*.c" -o "bin\aether.exe"
popd