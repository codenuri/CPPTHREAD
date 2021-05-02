cls

@echo [101mg++ %* -std=c++20 -o gout.exe [0m
@g++ %* -std=c++20 -o gout.exe

@IF %ERRORLEVEL% EQU 0 (
	echo [37;4m[ g++ compiling success !! run gout.exe ][0m
  	gout.exe
) ELSE (
	echo [37;4m[ Error !!, g++ fail to compile. ][0m
)

@echo.

@echo [101mcl %* /std:c++latest /utf-8 /out:vout.exe [0m
@cl  %* /permissive- /std:c++latest /utf-8 /nologo /EHsc /link /out:vout.exe

@IF %ERRORLEVEL%  EQU 0 (
	echo [37;4m[ cl compiling success !! run vout.exe ][0m
	vout.exe
)ELSE (
	echo [37;4m[ Error !!, cl fail to compile. ][0m
)
