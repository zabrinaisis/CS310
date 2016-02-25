#include <stdio.h>

int makeit(float money) {
    int count100 = 0;
    int count50 = 0;
    int count20 = 0;
    int count10 = 0;
    int count5 = 0;
    int count1 = 0;
    int countq = 0;
    int countd = 0;
    int countn = 0;
    int countp = 0;

    while (money >= 100.00) {
        count100++;
        money = money - 100.00;
    }
    while (money >= 50.00) {
        count50++;
        money = money - 50.00;
    }
    while (money >= 20.00) {
        count20++;
        money = money - 20.00;
    }
    while (money >= 10.00) {
        count10++;
        money = money - 10.00;
    }
    while (money >= 5.00) {
        count5++;
        money = money - 5.00;
    }
    while (money >= 1.00) {
        count1++;
        money = money - 1.00;
    }
    while (money >= 0.25) {
        countq++;
        money = money - 0.25;
    }
    while (money >= 0.10) {
        countd++;
        money = money - 0.10;
    }
    while (money >= 0.05) {
        countn++;
        money = money - 0.05;
    }
    while (money >= 0.01) {
        countp++;
        money = money - 0.01;
    }

    printf("You should get %d hundred dollar bills.\n", count100);
    printf("You should get %d fifty dollar bills.\n", count50);        
    printf("You should get %d twenty dollar bills.\n", count20);        
    printf("You should get %d ten dollar bills.\n", count10);       
    printf("You should get %d five dollar bills.\n", count5);        
    printf("You should get %d one dollar bills.\n", count1);        
    printf("You should get %d quarters.\n", countq);        
    printf("You should get %d dimes.\n", countd);        
    printf("You should get %d nickles.\n", countn);        
    printf("You should get %d pennies.\n", countp);        
    printf("Enjoy your change!\n");        
}

int main() {
    float cost = 0.00;
    float paid = 0.00;
    float change = 0.00;
    printf("How much did your stuff cost: ");
    scanf("%f", &cost);
    printf("Total money given: ");
    scanf("%f", &paid);
    change = paid - cost;
    printf("Your change should be: %.2f\n", change);
    makeit(change);
}
