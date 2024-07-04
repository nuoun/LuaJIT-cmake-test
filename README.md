# LuaJIT-cmake-test

## To build
git clone https://github.com/nuoun/LuaJIT-cmake-test.git  
cd LuaJIT-cmake-test  
git submodule update --init --recursive  
cmake -Bbuild  
cmake --build build

## Test
./build/luajit-test
