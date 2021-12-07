@echo off
	for /L %%i in (0, 1, 9) do (
		for /L %%j in (0, 1, 9) do (
			if exist C:\Users\ALEX\Desktop\K\*%%i*%%j*.* (
				dir /b C:\Users\ALEX\Desktop\K\*%%i*%%j*.* >> C:\Users\ALEX\Desktop\K\F.txt;
				echo "ALL RIGHT";
			) else (
				echo %%i%%j;
			)
		)
	)
echo on