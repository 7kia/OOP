Lab1-3.exe
IF NOT ERRORLEVEL 1 GOTO err

Lab1-3.exe m.txt
IF NOT ERRORLEVEL 1 GOTO err

Lab1-3.exe vc output.txt ma MAMA
IF NOT ERRORLEVEL 1 GOTO err

Lab1-3.exe matrixE.txt
IF NOT ERRORLEVEL 1 GOTO err

Lab1-3.exe matrix.txt >> out.txt
IF ERRORLEVEL 1 GOTO err
FC /b out.txt CheckData/right.txt
IF ERRORLEVEL 1 GOTO err

Lab1-3.exe matrix2.txt >> out2.txt
IF ERRORLEVEL 1 GOTO err
FC /b out2.txt CheckData/right2.txt
IF ERRORLEVEL 1 GOTO err

Lab1-3.exe matrix3.txt >> out3.txt
IF ERRORLEVEL 1 GOTO err
FC /b out3.txt CheckData/right3.txt
IF ERRORLEVEL 1 GOTO err

Lab1-3.exe matrix4.txt >> out4.txt
IF ERRORLEVEL 1 GOTO err
FC /b out4.txt CheckData/right4.txt
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-) 
PAUSE
EXIT
  
:err
ECHO Program testing failed :-( 
PAUSE
EXIT