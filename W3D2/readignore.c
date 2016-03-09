#include <stdio.h>

int main() {
    int second, fourth, seventh;
    FILE* stream = fopen("nums.txt", "r");    
    fscanf(stream, "%*d %d %*d %d %*d %*d %d", &second, &fourth, &seventh);
    printf("Second: %d\n", second);    
    printf("Fourth: %d\n", fourth);
    printf("Seventh: %d\n", seventh);

    int l2n2, l2n4, l2n7, l3n2, l3n4, l3n7;
    fscanf(stream, "%*d %d %*d %d %*d %*d %d %*[\n]", &l2n2, &l2n4, &l2n7);
    fscanf(stream, "%*d %d %*d %d %*d %*d %d %*[\n]", &l3n2, &l3n4, &l3n7);
    printf("Second: %d\n", l2n2);    
    printf("Fourth: %d\n", l2n4);
    printf("Seventh: %d\n", l2n7);
    printf("Second: %d\n", l3n2);    
    printf("Fourth: %d\n", l3n4);
    printf("Seventh: %d\n", l3n7);
    fclose(stream);

}
