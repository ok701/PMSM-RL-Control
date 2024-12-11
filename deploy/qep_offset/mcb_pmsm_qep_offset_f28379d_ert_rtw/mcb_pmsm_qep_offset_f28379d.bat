
cd .

if "%1"=="" ("C:\PROGRA~1\MATLAB\R2024b\bin\win64\gmake"  DEPRULES=1 -j17  -f mcb_pmsm_qep_offset_f28379d.mk all) else ("C:\PROGRA~1\MATLAB\R2024b\bin\win64\gmake"  DEPRULES=1 -j17  -f mcb_pmsm_qep_offset_f28379d.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1