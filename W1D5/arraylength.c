#include <stdio.h>
#include <stdlib.h>

void printSizeOf(int intArray[]);
void pringLength(int intArray[]);

int main(int argc, char* argv[]) {
    int array[] = {0, 1, 2, 3, 4, 5, 6};

    printf("Size of array: %d\n", (int)sizeof(array));
    printSizeOf(array);

    printf("Length of array: %d\n", (int)(sizeof(array)/sizeof(array[0]);
    printLengthOf(array);
}

void printSizeOf(int intArray[]) {
    printf("Size of parameter: %d\n", (int)sizeof(intArray));
}

void printLength(int intArray[]) {
    printf("Length of parameter: %d\n", (int)(sizeof(intArray)\sizeof(intArray[0]));
}
