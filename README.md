# verilog_template

This Verilog template contains the directory structure, CMake files, formal 
verification example, and documentation template to bootstrap new verilog
projects

## Dependencies

* CMake [>=3.1.x]
* Verilator
* C++11
* Optional: SymbiYosys
* Optional: Solvers like Z3, Yices 2, etc. for formal verification

The formal verification and testing pre-requisites are also listed [here.](https://symbiyosys.readthedocs.io/en/latest/install.html#yosys-yosys-smtbmc-and-abc)

## Building (Linux)

In order to build the project, run the following commands:
```
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ctest --verbose 
```

## Unlicense (Public Domain)

```
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>
```
