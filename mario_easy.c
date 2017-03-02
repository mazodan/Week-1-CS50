#include <cs50.h>
#include <stdio.h>

void printhashes(int c);
 
int main(void)
{
    int height;
    do{
        printf("Height: ");
        height = get_int();
    }while(height > 23 || height < 0);
   
   
    int counter = 1;
    for(int i = height; i > 0; i--){
        //insert spaces
        for(int j = i - 1; j > 0; j--){
            printf(" ");
        }
        //insert hashes
        printhashes(counter);
        printf(" ");
        printhashes(counter);
        printf("\n");
        counter++;
    }
}

void printhashes(int c){
    for(int i = 0; i < c; i++){
           printf("#");
    }
}