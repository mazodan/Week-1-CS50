#include <cs50.h>
#include <stdio.h>
#include <math.h>
 
//HACKER CHALLENGE, IF MY IMPLEMENTATION IS BAD, PLEASE HELP ME OPTIMIZE IT, FEEDBACK AND CRITICISMS ARE WELCOME.
 
void luhnChecksum(long long cNumber);
int * convertNumberIntoArray(unsigned long long number);
void identifyVendor(int digit);

int main(void)
{
    //Input, must be positive
    printf("Number: ");
    unsigned long long cardNumber = get_long_long();
    luhnChecksum(cardNumber);
}
 
//FUNCTION CALCULATES THE CHECKSUM 
void luhnChecksum(long long cNumber){
    int *cArray;
    unsigned int length = (int)(log10((float)cNumber)) + 1;
   
    cArray = convertNumberIntoArray(cNumber);
    
    int uncheckedSum = 0;
    int checkSum = 0;
    
    for(int i = 0; i < length; i++){
        //378282246310005 - AMEX
        
        //if number is even
        if(i % 2 == 0){            
            uncheckedSum += cArray[i];            
        }else{
            //checked digit is multiplied by 2
            cArray[i] *= 2;
            //add 2 digits in advance
            if (cArray[i] > 9){
            	cArray[i] = (int)(cArray[i] / 10) + (cArray[i] % 10);
        	}
            checkSum += cArray[i];
            
        }
    }
    
    
    int *nArray;
    nArray = convertNumberIntoArray(cNumber);
    if ((uncheckedSum + checkSum) % 10 == 0){
        identifyVendor((nArray[length - 1] * 10) + nArray[length - 2]);
    }else{
        printf("INVALID\n");
    }
    
}
 
//CONVERT A LONG LONG TO AN ARRAY OF INTs, from stackexchange
int * convertNumberIntoArray(unsigned long long number) {
    unsigned int length = (int)(log10((float)number)) + 1;
    int * arr = (int *) malloc(length * sizeof(int)), * curr = arr;
    do {
        *curr++ = number % 10;
        number /= 10;
    } while (number != 0);
    return arr;
}

void identifyVendor(int digit){
    if (digit / 10 == 4){
        printf("VISA\n");
    }else{
        switch(digit){
            case 35:
                printf("JCB\n" );
            	break;
            case 34:
            case 37:
            	printf("AMEX\n" );
            	break;
            case 51:
            case 52:
            case 53:
            case 54:
            case 55:
                printf("MASTERCARD\n" );
            	break;
            case 56:
                printf("Bankcard\n" );
            	break;
            case 30:
            case 38:
                printf("Diners Club\n" );
            	break;
            case 60:
                printf("Discover\n" );
            	break;
            default:    
            	printf("VENDOR NOT FOUND, INVALID\n" );
        }
    }
    
}

