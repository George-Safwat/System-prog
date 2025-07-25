# Unix Utilities in C

This repository contains simple reimplementations of Unix utilities written in C:

- `pwd`: Print working directory
- `echo`: Print text to stdout
- `cp`: Copy file from source to destination
- `mv`: Move (rename) file

## Compilation

Each file can be compiled using `gcc` as shown below:

```bash
gcc -o pwd_exec pwd.c
gcc -o echo_exec echo.c
gcc -o cp_exec cp.c
gcc -o mv_exec mv.c
