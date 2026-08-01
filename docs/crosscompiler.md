# How to get a cross-compiler that works with rsd

## Requirements
0. A POSIX-compliant dev enviroment (On Linux, macOS and *BSD you already have it, on Windows you either need [MSYS2](https://www.msys2.org/), [Cygwin](https://cygwin.com/) or [WSL](https://wsl.dev/))
1. An existing gcc compiler for your computers architecture
2. GNU Make (in theory BSD Make should work too but I haven't tested it yet)
3. [Bison](https://www.gnu.org/software/bison/)
4. [Flex](https://github.com/westes/flex)
5. [GMP](https://gmplib.org/)
6. [MPC](https://ftp.gnu.org/gnu/mpc/)
7. [MPFR](https://www.mpfr.org/)
8. [Texinfo](https://www.gnu.org/software/texinfo/)
9. [ISL](http://isl.gforge.inria.fr/)

## The process
Making a cross-compiler should be as easy as running the ```build-crosscompiler``` script in the ```scripts``` directory. Please note that by default it creates the ```opt``` and ```src``` directories in your ```$HOME```, so please change the corresponding values in the script according to your preferences (just please don't commit those). By default it builds gcc with support for Ada, C and sysroot enviroments
