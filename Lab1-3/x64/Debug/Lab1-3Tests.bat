Lab1-3.exe
IF NOT ERRORLEVEL 1 GOTO err

Lab1-3.exe m.txt
IF NOT ERRORLEVEL 1 GOTO err

Lab1-3.exe vc output.txt ma MAMA
IF NOT ERRORLEVEL 1 GOTO err

Lab1-3.exe matrix.txt
IF ERRORLEVEL 1 GOTO err
FC /b output1.txt CheckData/right1.txt
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-) 
PAUSE
EXIT
  
:err
ECHO Program testing failed :-( 
PAUSE
EXIT