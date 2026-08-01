# rsd
rsd is an attempt at making somewhat secure minimal operating system with its own kernel and non-gnu userland applications.

## Installation
Currently the only way to get an image of the operating system is to compile it yourself
### Required software
 - i686-elf versions of gcc and binutils (see [compile instructions](./docs/crosscompiler.md))
 - bash
 - xorriso
 - gzip
 - curl
 - tar
 - GRUB (Optional)
### Build process
Just run ```make dist``` and it should compile and give you an iso with default configs
