del build
mkdir build
cd ./build
conan install .. -b=missing
cmake ..
cd ..
cmake --build ./build