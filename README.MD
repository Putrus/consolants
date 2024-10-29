# Build

## CMake
Minimum version required is 3.6. 
```
git clone https://github.com/Putrus/consolants
cd consolants
cmake -S . -B build # Default compiler
cmake -G "MinGW Makefiles" -DCMAKE_CXX_COMPILER=g++ -DCMAKE_C_COMPILER=gcc -DCMAKE_BUILD_TYPE=Release -S . -B build # Recommended g++ compiler
cmake --build build
```

# Run
## consolants
The consolants executable (consolants.exe on windows) is located in the build\consolants\main folder

## unit tests
### ctest 
```
ctest --test-dir build/unittests --output-on-failure
```
### executable
The unit tests executables are located in the subdirectories in the build\unittests\consolants folder