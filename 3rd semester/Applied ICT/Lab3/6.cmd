@echo off
	for /L %%i in (0, 1, 9) do (		
		if exist C:\Users\ALEX\Desktop\K\b0%%i.* (
			rename C:\Users\ALEX\Desktop\K\b0%%i.* Inf_b0%%i.*;
		)		
	)
echo on