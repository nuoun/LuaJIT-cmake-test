# luajitlib

## To build
git clone https://github.com/nuoun/luajitlib.git
cd luajitlib
git submodule update --init --recursive
cmake -Bbuild
cmake --build build

## Test
./build/luajitlib-test
