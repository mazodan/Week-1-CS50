#include <stdio.h>
#include <cs50.h>   //cs50 libraries for easy coding
#include <math.h>   //for rounding off floats

int incrementCounter(int c, int unit);

int main(void){
    //print introductory text
    printf("O hai! How much change is owed?\n");
    int cents = (int) round(GetFloat() * 100);
    
    //trappings
    while (cents < 0){
        printf("How much change is owed?\n");
        cents = (int) round(GetFloat() * 100);
    }
    
    
    int counter = 0;
    if (cents >= 25){
        counter += incrementCounter(cents, 25);
        cents %= 25;
    }
    
    if (cents >= 10){
        counter += incrementCounter(cents, 10);
        cents %= 10;
    }
    
    if (cents >= 5){
        counter += incrementCounter(cents, 5);
        cents %= 5;
    }
    
    if (cents >= 1){
        counter += incrementCounter(cents, 1);
    }
    
    printf("%i\n", counter);
}

//divides the unit and the counter, tells how many units are in the change.
int incrementCounter(int c, int unit){
    return c / unit;
}