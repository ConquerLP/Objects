del *.o
del main.exe
set "home=%CD%"

cd source\base\misc 
gcc -std=c11 -c *.c
move *.o "%home%"

cd "%home%"
cd source\base\wrapper
gcc -std=c11 -c *.c
move *.o "%home%"

cd "%home%"
cd source\base
gcc -std=c11 -c *.c
move *.o "%home%"

cd "%home%"
cd source\util\collection
gcc -std=c11 -c *.c
move *.o "%home%"

cd "%home%"
cd source
gcc -std=c11 -c *.c
move *.o "%home%"

cd "%home%"
gcc -std=c11 *.o -o main.exe
del *.o
pause
cls
@echo "Compilation of project is finished."
pause
cls

cd %home%
cd test\test_api
gcc -std=c11 -c *.c
move *.o "%home%"

cd %home%
cd test\test_classes
gcc -std=c11 -c *.c
move *.o "%home%"

cd %home%
cd test
gcc -std=c11 -c *.c
move *.o "%home%"

cd %home%
gcc -std=c11 *.o -o test.exe
pause
del *.o
cls
@echo "Compilation of tests is finished."
pause
"test.exe"
pause
cls

"main.exe"
pause
del *.exe