#include <stdio.c>

int main() {
    struct car cars[25];
    int i;
    int year = 1991;
    char* make = "Honda";               // did not create for the pointer
    for (i = 0; i < 25; i++) {
        cars[i].make = make;            // will go away with main
        sprintf(cars[i].model, "Civic %d", year);
        year++;
    }
    struct car** rev = malloc(25*sizeof(struct car*));  // needed array
    for (i = 0; i < 25; i++) {
        rev[i] = &cars[24 - i];
    }
}
