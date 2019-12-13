# Description
Enable a block logic by calling a dynamic library.

# Build Project In Unbunt16
## Install Required Package
```bash
sudo apt-get install lsb-core
sudo apt-get install doxygen
sudo apt-get install graphviz
sudo apt-get install libgoogle-glog-dev
sudo apt-get install cmake
sudo apt-get install valgrind
```
## How To Run Demo
```bash
cd demo
mkdir build
cd build
cmake ..
make -j4
./demo
```
If your want to detect code memory leaks, please run follows bash shell code.
```bash
valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./demo
```
## How To Only Create lib
In the project top-level directory
```
mkdir build
cmake ..
make -j4
```
## How To Use Doxygen
In the doxygen file path: `doxygen doxyfile`, then you can open file`(docs/doxygen/html/index.html)` with browser.
