
Lab1-2.exe >> test1.txt
IF NOT ERRORLEVEL 1 GOTO err
FC /b test1.txt CheckData/test1.txt
IF ERRORLEVEL 1 GOTO err

Lab1-2.exe 16 >> test2.txt
IF NOT ERRORLEVEL 1 GOTO err
FC /b test2.txt CheckData/test2.txt
IF ERRORLEVEL 1 GOTO err

Lab1-2.exe 16 10>> test3.txt
IF NOT ERRORLEVEL 1 GOTO err
FC /b test3.txt CheckData/test3.txt
IF ERRORLEVEL 1 GOTO err

Lab1-2.exe 16 10 - >> test4.txt
IF NOT ERRORLEVEL 1 GOTO err
FC /b test4.txt CheckData/test4.txt
IF ERRORLEVEL 1 GOTO err

Lab1-2.exe 16 -10 0 >> test5.txt
IF NOT ERRORLEVEL 1 GOTO err
FC /b test5.txt CheckData/test5.txt
IF ERRORLEVEL 1 GOTO err

Lab1-2.exe -16 10 0 >> test6.txt
IF NOT ERRORLEVEL 1 GOTO err
FC /b test6.txt CheckData/test6.txt
IF ERRORLEVEL 1 GOTO err

Lab1-2.exe 1c6 4 2 >> test7.txt
IF NOT ERRORLEVEL 1 GOTO err
FC /b test7.txt CheckData/test7.txt
IF ERRORLEVEL 1 GOTO err

Lab1-2.exe 16 10 FFFFFFFF >> test8.txt
IF NOT ERRORLEVEL 1 GOTO err
FC /b test8.txt CheckData/test8.txt
IF ERRORLEVEL 1 GOTO err

Lab1-2.exe 16 10 -FFFFFFFF >> test9.txt
IF NOT ERRORLEVEL 1 GOTO err
FC /b test9.txt CheckData/test9.txt
IF ERRORLEVEL 1 GOTO err

Lab1-2.exe 16 10 -FFFFFF >> test10.txt
IF ERRORLEVEL 1 GOTO err
FC /b test10.txt CheckData/test10.txt
IF ERRORLEVEL 1 GOTO err

Lab1-2.exe 16 10 -FF >> test11.txt
IF ERRORLEVEL 1 GOTO err
FC /b test11.txt CheckData/test11.txt
IF ERRORLEVEL 1 GOTO err

Lab1-2.exe 10 16 -2147483648 >> test12.txt
IF NOT ERRORLEVEL 1 GOTO err
FC /b test12.txt CheckData/test12.txt
IF ERRORLEVEL 1 GOTO err

Lab1-2.exe 16 10 -F >> test13.txt
IF ERRORLEVEL 1 GOTO err
FC /b test13.txt CheckData/test13.txt
IF ERRORLEVEL 1 GOTO err

Lab1-2.exe 10 16 -K >> test14.txt
IF NOT ERRORLEVEL 1 GOTO err
FC /b test14.txt CheckData/test14.txt
IF ERRORLEVEL 1 GOTO err

Lab1-2.exe 0 10 2 >> test15.txt
IF NOT ERRORLEVEL 1 GOTO err
FC /b test15.txt CheckData/test15.txt
IF ERRORLEVEL 1 GOTO err

Lab1-2.exe 16 40 -F >> test16.txt
IF NOT ERRORLEVEL 1 GOTO err
FC /b test16.txt CheckData/test16.txt
IF ERRORLEVEL 1 GOTO err

Lab1-2.exe 16 35 -A >> test17.txt
IF ERRORLEVEL 1 GOTO err
FC /b test17.txt CheckData/test17.txt
IF ERRORLEVEL 1 GOTO err

Lab1-2.exe 16 34 -A >> test18.txt
IF ERRORLEVEL 1 GOTO err
FC /b test18.txt CheckData/test18.txt
IF ERRORLEVEL 1 GOTO err

Lab1-2.exe 16000000000 34 -A >> test19.txt
IF NOT ERRORLEVEL 1 GOTO err
FC /b test19.txt CheckData/test19.txt
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-) 
PAUSE
EXIT
  
:err
ECHO Program testing failed :-( 
PAUSE
EXIT