Lab1-3.exe matrix.txt
IF ERRORLEVEL 1 GOTO err

Lab1-3.exe matrix2.txt
IF ERRORLEVEL 1 GOTO err

Lab1-3.exe matrixc.txt
IF ERRORLEVEL 1 GOTO err

Lab1-3.exe 
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)
PAUSE
EXIT

:err
ECHO Programtestingfailed :-(
PAUSE