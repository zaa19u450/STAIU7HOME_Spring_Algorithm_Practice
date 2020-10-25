@echo off
cls
(cd ..)


echo POSITIVES

echo pos_01_test
app.exe func_tests\\pos_01_in.txt year > func_tests\out.txt
if errorlevel == 0 (fc func_tests\out.txt func_tests\pos_01_out.txt) else ( echo Failed!)
pause

echo pos_02_test
app.exe func_tests\\pos_02_in.txt title > func_tests\out.txt
if errorlevel == 0 (fc func_tests\out.txt func_tests\pos_02_out.txt) else ( echo Failed!)
pause

echo pos_03_test
app.exe func_tests\\pos_03_in.txt name > func_tests\out.txt
if errorlevel == 0 (fc func_tests\out.txt func_tests\pos_03_out.txt) else ( echo Failed!)
pause

echo pos_04_test
app.exe func_tests\\pos_04_in.txt year > func_tests\out.txt
if errorlevel == 0 (fc func_tests\out.txt func_tests\pos_04_out.txt) else ( echo Failed!)
pause

echo pos_05_test
app.exe func_tests\\pos_05_in.txt year > func_tests\out.txt
if errorlevel == 0 (fc func_tests\out.txt func_tests\pos_05_out.txt) else ( echo Failed!)
pause

echo pos_06_test
app.exe func_tests\\pos_06_in.txt year > func_tests\out.txt
if errorlevel == 0 (fc func_tests\out.txt func_tests\pos_06_out.txt) else ( echo Failed!)
pause


echo pos_07_test
app.exe func_tests\\pos_07_in.txt title Nobody > func_tests\out.txt
if errorlevel == 0 (fc func_tests\out.txt func_tests\pos_07_out.txt) else ( echo Failed!)
pause

echo pos_08_test
app.exe func_tests\\pos_08_in.txt name Nobody > func_tests\out.txt
if errorlevel == 0 (fc func_tests\out.txt func_tests\pos_08_out.txt) else ( echo Failed!)
pause

echo pos_09_test
app.exe func_tests\\pos_09_in.txt year 2000 > func_tests\out.txt
if errorlevel == 0 (fc func_tests\out.txt func_tests\pos_09_out.txt) else ( echo Failed!)
pause

echo pos_10_test
app.exe func_tests\\pos_10_in.txt year 2019 > func_tests\out.txt
if errorlevel == 0 (fc func_tests\out.txt func_tests\pos_10_out.txt) else ( echo Failed!)
pause

echo pos_11_test
app.exe func_tests\\pos_11_in.txt name Darabont > func_tests\out.txt
if errorlevel == 0 (fc func_tests\out.txt func_tests\pos_11_out.txt) else ( echo Failed!)
pause

echo pos_12_test
app.exe func_tests\\pos_12_in.txt title Avatar > func_tests\out.txt
if errorlevel == 0 (fc func_tests\out.txt func_tests\pos_12_out.txt) else ( echo Failed!)
pause

echo pos_13_test
app.exe func_tests\\pos_13_in.txt title "Shawshank Redemption" > func_tests\out.txt
if errorlevel == 0 (fc func_tests\out.txt func_tests\pos_13_out.txt) else ( echo Failed!)
pause

echo pos_14_test
app.exe func_tests\\pos_14_in.txt name hahn > func_tests\out.txt
if errorlevel == 0 (fc func_tests\out.txt func_tests\pos_14_out.txt) else ( echo Failed!)
pause


echo NEGATIVES

echo neg_01_test
app.exe func_tests\\films.txt > func_tests\out.txt
if errorlevel == -1 ( echo PASSED!) else ( echo Failed!)
fc func_tests\out.txt func_tests\neg_01_out.txt
pause

echo neg_02_test
app.exe func_tests\\films.txt year CasinoRoyale toomany > func_tests\out.txt
if errorlevel == -1 ( echo PASSED!) else ( echo Failed!)
fc func_tests\out.txt func_tests\neg_02_out.txt
pause

echo neg_03_test
app.exe func_tests\\films.txt whatever > func_tests\out.txt
if errorlevel == -1 ( echo PASSED!) else ( echo Failed!)
fc func_tests\out.txt func_tests\neg_03_out.txt
pause

echo neg_06_test
app.exe func_tests\\films.txt year two > func_tests\out.txt
if errorlevel == -1 ( echo PASSED!) else ( echo Failed!)
fc func_tests\out.txt func_tests\neg_06_out.txt
pause

echo neg_07_test
app.exe func_tests\\films.txt year -2020 > func_tests\out.txt
if errorlevel == -1 ( echo PASSED!) else ( echo Failed!)
fc func_tests\out.txt func_tests\neg_07_out.txt
pause

echo neg_08_test
app.exe func_tests\\films.txt year 100000 > func_tests\out.txt
if errorlevel == -1 ( echo PASSED!) else ( echo Failed!)
fc func_tests\out.txt func_tests\neg_08_out.txt
pause


echo neg_09_test
app.exe func_tests\\no.txt year > func_tests\out.txt
if errorlevel == -2 ( echo PASSED!) else ( echo Failed!)
fc func_tests\out.txt func_tests\neg_09_out.txt
pause

echo neg_10_test
app.exe func_tests\\neg_10_in.txt year > func_tests\out.txt
if errorlevel == -3 ( echo PASSED!) else ( echo Failed!)
fc func_tests\out.txt func_tests\neg_10_out.txt
pause

echo neg_13_test
app.exe func_tests\\neg_13_in.txt year > func_tests\out.txt
if errorlevel == -4 ( echo PASSED!) else ( echo Failed!)
fc func_tests\out.txt func_tests\neg_13_out.txt
pause

echo neg_14_test
app.exe func_tests\\neg_14_in.txt year > func_tests\out.txt
if errorlevel == -4 ( echo PASSED!) else ( echo Failed!)
fc func_tests\out.txt func_tests\neg_14_out.txt
pause

echo neg_15_test
app.exe func_tests\\neg_15_in.txt year > func_tests\out.txt
if errorlevel == -4 ( echo PASSED!) else ( echo Failed!)
fc func_tests\out.txt func_tests\neg_15_out.txt
pause

echo neg_16_test
app.exe func_tests\\neg_16_in.txt year > func_tests\out.txt
if errorlevel == -4 ( echo PASSED!) else ( echo Failed!)
fc func_tests\out.txt func_tests\neg_16_out.txt
pause




