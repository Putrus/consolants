@echo off

set CMAKE_EXECUTABLE=cmak2e.exe

where %CMAKE_EXECUTABLE% >nul 2>nul


if %errorlevel% neq 0 (
   set GTEST_OUTPUT=xml:%CD%\build\unittests\Testing\report\Logic.xml
   echo Logic module unit tests
   call build\unittests\consolants\logic\consolants_logic_ut.exe --output-on-failure

   echo.
   set GTEST_OUTPUT=xml:%CD%\build\unittests\Testing\report\Main.xml
   echo Main module unit tests
   call build\unittests\consolants\main\consolants_main_ut.exe --output-on-failure

   echo.
   set GTEST_OUTPUT=xml:%CD%\build\unittests\Testing\report\Math.xml
   echo Math module unit tests
   call build\unittests\consolants\math\consolants_math_ut.exe --output-on-failure

   echo.
   set GTEST_OUTPUT=xml:%CD%\build\unittests\Testing\report\View.xml
   echo View module unit tests
   call build\unittests\consolants\view\consolants_view_ut.exe --output-on-failure
) else (
   call ctest -T test --test-dir build\unittests --output-on-failure -j 12
)

pause