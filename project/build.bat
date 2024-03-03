del *.o
del main.exe
set "home=%CD%"

cd base 
cd misc 
gcc -std=c11 -c *.c
move *.o "%home%"

cd "%home%"
cd base
cd wrapper 
gcc -std=c11 -c *.c
move *.o "%home%"

cd "%home%"
cd base
gcc -std=c11 -c *.c
move *.o "%home%"

cd "%home%"
cd util
cd collection
gcc -std=c11 -c *.c
move *.o "%home%"

cd "%home%"

gcc -std=c11 -c *.c
pause
gcc -std=c11 *.o -o main.exe
del *.o
cls
@echo "Finish compilation."
pause
cls
"main.exe"
@echo "Done."
pause