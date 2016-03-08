#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printm(int* m, int mode) {
    int i;
    int j = 0;
    switch (mode) {
        case 0:
            while (j < 100) {
                for (i = 0; i < 10; i++) {
                    printf("%3d", m[i + j]);
                }   
                j += 10;
                printf("\n");
            }
         case 1:
            while (j < 90) {
                for (i = 0; i < 10; i++) {
                    printf("%3d", m[i + j]);
                }   
                j += 10;
                printf("\n");
            }
        case 2:
            while (j < 90) {
                for (i = 0; i < 9; i++) {
                    printf("%3d", m[i + j]);
                }   
                j += 9;
                printf("\n");
            }
    }
    printf("\n");
} // end printm

int main() {
    int i;
    int o = 0;
    int r = 1;
    int c = 2;
    int a[10][10];
    int *orig = &a[0][0];
    int b[10][10];
    int *chng = &b[0][0];

    for (i = 0; i < 100; i++) {
        orig[i] = i;
        chng[i] = i;
    }

    printf("The current matrix is:\n");
    printm(orig, o);
    char res[7];
    
    printf("Enter a command based on the following:\n");
    printf("\tFirst letter is \"d\" for delete or \"i\" for interchange.\n");
    printf("\tSecond letter is \"r\" for row or \"c\" for column.\n");
    printf("\tThen enter numbers seperated by spaces.\n");
    printf("For example, entering \"ir 2 3\" would interchange rows 2 and 3.\n");
    fgets(res, sizeof(res), stdin);

    if (res[0] == 'd' || res[0] == 'D') {
        if (res[1] == 'r' || res[1] == 'R') {
            char* n = &res[3];
            int num = atoi(n);
            int formula = ((num - 1) * 10);
            for (i = formula; i < 100; i++) {
                chng[i] = i + 10;
            }
            printf("The original matrix was:\n");
            printm(orig, o);
            printf("The new matrix is:\n");
            printm(chng, r);
        } else if (res[1] == 'c' || res[1] == 'C') {
            char* n = &res[3];
            int num = atoi(n) - 1;
            int j = 0;
            for (i = 0; i < 100; i++) {
                if (i != num) {
                    chng[i] = j;
                    j++;
                } else {
                    j++;
                    chng[i] = j;
                    num = num + 9;
                    j++;
                }
            }
            printf("The original matrix was:\n");
            printm(orig, o);
            printf("The new matrix is:\n");
            printm(chng, c);
        } else {
            // other letters
        }

    } else if (res[0] == 'i' || res[0] == 'I') {
        if (res[1] == 'r' || res[1] == 'R') {
            char* n1 = &res[3];
            char* n2 = &res[5];
            int num1 = atoi(n1) - 1;
            int num2 = atoi(n2) - 1;
            int max = (num1 > num2) ? num1 : num2;
            int min = (num1 != max) ? num1 : num2;
            int distance = (max - min) * 10;
            int j = 0;
            int k;
            for (i = 0; i < 100; i++) {
                if ((i != num1) && (i != num2)) {
                    chng[i] = j;
                    j++;
                } else if (i == min) {
                    for (k = 0; k < distance; k++) {
                        j++;
                    }
                    chng[i] = j;
                    for (k = 0; k < distance; k++) {
                        j--;
                    }
                    j++;
                    min += 1;
                } else if (i == max) {
                    for (k = 0; k < distance; k++) {
                        j--;
                    }
                    chng[i] = j;
                    for (k = 0; k < distance; k++) {
                        j++;
                    }   
                    j++;
                    max += 1;
                }
            }
            printf("The original matrix was:\n");
            printm(orig, o);
            printf("The new matrix is:\n");
            printm(chng, o);
        } else if (res[1] == 'c' || res[1] == 'C') {
            char* n1 = &res[3];
            char* n2 = &res[5];
            int num1 = atoi(n1) - 1;
            int num2 = atoi(n2) - 1;
            int max = (num1 > num2) ? num1 : num2;
            int min = (num1 != max) ? num1 : num2;
            int distance = max - min;
            int j = 0;
            int k;
            for (i = 0; i < 100; i++) {
                if ((i != num1) && (i != num2)) {
                    chng[i] = j;
                    j++;
                } else if (i == min) {
                    for (k = 0; k < distance; k++) {
                        j++;
                    }
                    chng[i] = j;
                    for (k = 0; k < distance; k++) {
                        j--;
                    }
                    j++;
                    min += 10;
                } else if (i == max) {
                    for (k = 0; k < distance; k++) {
                        j--;
                    }
                    chng[i] = j;
                    for (k = 0; k < distance; k++) {
                        j++;
                    }   
                    j++;
                    max += 10;
                }
            }
            printf("The original matrix was:\n");
            printm(orig, o);
            printf("The new matrix is:\n");
            printm(chng, o);
        }

    } else {
        // other letters
    } // end if/else if/else for delete or interchange
} // end main
