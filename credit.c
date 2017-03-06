#include <cs50.h>
#include <stdio.h>
#include <math.h>
 
//HACKER CHALLENGE, IF MY IMPLEMENTATION IS BAD, PLEASE HELP ME OPTIMIZE IT, FEEDBACK AND CRITICISMS ARE WELCOME.
 
void luhnChecksum(long long cNumber);
int * convertNumberIntoArray(unsigned long long number);
 
int main(int argc, string argv[])
{
    //Input, must be positive
    printf("Number: ");
    unsigned long long cardNumber = get_long_long();
    luhnChecksum(cardNumber);
    //Format
    //printf("%llu\n",cardNumber);
}
 
//FUNCTION CALCULATES THE CHECKSUM 
void luhnChecksum(long long cNumber){
    int *cArray;
    unsigned int length = (int)(log10((float)cNumber)) + 1;
   
    cArray = convertNumberIntoArray(cNumber);
    
    int uncheckedSum = 0;
    int checkSum = 0;
    
    for(int i = 0; i < length; i++){
        //TODO - ADD 2 DIGITS
        //FUCK YOU LUHN!!!!
        //378282246310005 - AMEX
        
        
        
        //if number is even
        if(i % 2 == 0){            
            uncheckedSum += cArray[i];            
        }else{
            //checked digit is multiplied by 2
            cArray[i] *= 2;
            if (cArray[i] > 9){
            	cArray[i] = (int)(cArray[i] / 10) + (cArray[i] % 10);
        	}
            checkSum += cArray[i];
            
        }
    }
    
    printf("%i\t%i\n", uncheckedSum, checkSum);
    
    if ((uncheckedSum + checkSum) % 10 == 0){
        printf("VALID!!!");
    }else{
        printf("%i\n", (uncheckedSum + checkSum));
        printf("INVALID!!!\n");
    }
    
}
 
//CONVERT A LONG LONG TO AN ARRAY OF INTs
int * convertNumberIntoArray(unsigned long long number) {
    unsigned int length = (int)(log10((float)number)) + 1;
    int * arr = (int *) malloc(length * sizeof(int)), * curr = arr;
    do {
        *curr++ = number % 10;
        number /= 10;
    } while (number != 0);
    return arr;
}




