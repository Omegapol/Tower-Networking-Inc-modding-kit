@echo off
set HERE=%cd%
if not exist .zig mkdir .zig
pushd .zig
cmake .. -G Ninja -DCMAKE_BUILD_TYPE=Release -DSTRIPPED=ON -DCMAKE_TOOLCHAIN_FILE=%HERE%\cmake\zig-toolchain.cmake
cmake --build .
popd
