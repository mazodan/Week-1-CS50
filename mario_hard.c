#include <stdio.h>
#include <cs50.h> //CS50 library to assist beginners for programming in C

int main(void){
    int height;
    
    do{
        printf("Height: ");
        height = get_int();
    }while (height < 0 || height > 23);
    
    
    int st = 2; //min stair limit
    for(int i = height; i > 0; i--){
        //for the spaces
        for(int sp = 0; sp < i - 1; sp++){
            printf(" ");
        }
        //for the hashes or stairs as you want to call it
        /*
            what this does is initialize st as h, then taking it down to Zero
            for some reason. initializing it 
        
        */
        
        for(int h = st; h > 0; h--){
            printf("#");    //this is the stairs
        }
        
        //increasing stair limit
        st++;
        //adding new line, C does not have an endl syntax
        printf("\n");
    }
    
    //This algorithm may not be optimized but this would do, still a beginner though
}
