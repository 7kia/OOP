Lab1-1.exe
IF NOT ERRORLEVEL 1 GOTO err

Lab1-1.exe vc output.txt ma MAMA
IF NOT ERRORLEVEL 1 GOTO err

Lab1-1.exe input1.txt output1.txt ma FIX
IF ERRORLEVEL 1 GOTO err
FC /b output1.txt CheckData/right1.txt
IF ERRORLEVEL 1 GOTO err

Lab1-1.exe input2.txt output2.txt char FIXCHAR
IF ERRORLEVEL 1 GOTO err
FC /b output2.txt CheckData/right2.txt
IF ERRORLEVEL 1 GOTO err

Lab1-1.exe input3.txt output3.txt 1231234 FIX
IF ERRORLEVEL 1 GOTO err
FC /b output3.txt CheckData/right3.txt
IF ERRORLEVEL 1 GOTO err

Lab1-1.exe input4.txt output4.txt char FIXCHAR
IF ERRORLEVEL 1 GOTO err
FC /b output4.txt CheckData/right4.txt
IF ERRORLEVEL 1 GOTO err

Lab1-1.exe input5.txt output5.txt ma Ma
IF ERRORLEVEL 1 GOTO err
FC /b output5.txt CheckData/right5.txt
IF ERRORLEVEL 1 GOTO err

Lab1-1.exe input6.txt output6.txt ma Ma
IF ERRORLEVEL 1 GOTO err
FC /b output6.txt CheckData/right6.txt
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-) 
PAUSE
EXIT
  
:err
ECHO Program testing failed :-( 
PAUSE
EXIT