#include <stdio.h>
#include <cs50.h> //CS50 library to assist beginners for programming in C

int main(void){
    int min;
    
    do {                        
        printf("Minutes: ");    //trappings and constraints/sanitation 
        min = get_int();
    }while (min < 0);
    
    // 1 minute in shower = 12 bottles
    printf("Bottles: %i\n", min * 12);
}