#! /bin/bash
rm -rf bin/
mkdir bin
cd bin/
cmake ..
make
./app
cd ..
