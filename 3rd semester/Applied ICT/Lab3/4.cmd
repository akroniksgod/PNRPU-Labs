@echo off
	for /L %%i in (0, 1, 9) do (
		dir C:\Users\ALEX\Desktop\K\*%%i.*;
	)
	pause > nul;
echo on