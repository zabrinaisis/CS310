#include <stdio.h>

int main() {
    int i;
    int temp[10][10];
    int *orig = &temp[0][0];
    int *chng = &temp[0][0];
    for (i = 0; i < 100; i++) {
        orig[i] = i + 1;
        printf("%d ", orig[i]);
    }
    printf("\n");
    for (i = 0; i < 100; i++) {
        chng[i] = i + 1;
        printf("%d ", chng[i]);
    }

    char res;
    printf("Testing: ");
    scanf("%c", &res);
    printf("%c\n", res);
    
    
    
    
    
    
    
    
    
    
    
    

}

