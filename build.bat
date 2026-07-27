@echo off
echo Building Encoding Converter...
echo.

:: Try cmake first
where cmake >nul 2>&1
if %ERRORLEVEL% EQU 0 (
    echo Using CMake build...
    if not exist build mkdir build
    cd build
    cmake -G "Visual Studio 17 2022" -A x64 ..
    cmake --build . --config Release
    echo.
    echo Build complete: build\Release\EncodingConverter.exe
    goto :end
)

:: Fallback to cl.exe directly
where cl >nul 2>&1
if %ERRORLEVEL% EQU 0 (
    echo Using MSVC cl.exe directly...
    cl /EHsc /W4 /utf-8 /DUNICODE /D_UNICODE /DWINVER=0x0A00 /D_WIN32_WINNT=0x0A00 /DNTDDI_VERSION=0x0A00000A /Fe:EncodingConverter.exe main.cpp /link /SUBSYSTEM:WINDOWS bcrypt.lib ncrypt.lib comdlg32.lib comctl32.lib shell32.lib user32.lib gdi32.lib kernel32.lib
    echo.
    echo Build complete: EncodingConverter.exe
    goto :end
)

echo ERROR: Neither cmake nor cl.exe found.
echo Please install Visual Studio or CMake.
echo.

:end
pause
