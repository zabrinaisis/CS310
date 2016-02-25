#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("%s\n", argv[0]);
}

// & in "&n" gives the memory address of n.
// & in "x & y" is a bitwise AND table.
// * in "int *x" makes *x pointer, an integer pointer.
// * in "*x" locates the address and returns the value.
//  (value of operator)
// Arrays and pointers are similar:
//  Both are really memory addresses.
//  A pointer is an array.
// Arrays and pointers are different:
//  Pointers can be changed and manipulated.
