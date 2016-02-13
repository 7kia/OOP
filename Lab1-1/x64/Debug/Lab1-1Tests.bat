REM Проверка на маленьком файле
Lab1-1.exe input1.txt output1.txt ma FIX
IF ERRORLEVEL 1 GOTO err

REM Проверка файле побольше
Lab1-1.exe input2.txt output2.txt char FIXCHAR
IF ERRORLEVEL 1 GOTO err

REM Проверка случая описанного в условии задачи(который был выделен красным цветом)
Lab1-1.exe input3.txt output3.txt 1231234 FIX
IF ERRORLEVEL 1 GOTO err

REM Проверка на большом файле
Lab1-1.exe input4.txt output4.txt char FIXCHAR
IF ERRORLEVEL 1 GOTO err

Lab1-1.exe input5.txt output5.txt ma Ma
IF ERRORLEVEL 1 GOTO err

Lab1-1.exe input6.txt output6.txt ma MA
IF ERRORLEVEL 1 GOTO err

REM Запуск с неправильными данными
Lab1-1.exe input1.txt output1.txt FIX
IF ERRORLEVEL 1 GOTO err

Lab1-1.exe input2.txt output2.txt
IF ERRORLEVEL 1 GOTO err

Lab1-1.exe input3.txt
IF ERRORLEVEL 1 GOTO err

Lab1-1.exe inp#ut1.txt output1.txt ma FIX
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)
PAUSE
EXIT

:err
ECHO Programtestingfailed :-(
PAUSE