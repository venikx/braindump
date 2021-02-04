#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Check if the credit card is valid: ");
    long long creditCard = get_long_long();
    int length = 0;
    int result = 0;
    int creditCardPrefix = 0;
    
    while (creditCard != 0){
        length++;
        
        if(length % 2 == 0)
        {
            int tmp = (creditCard % 10) * 2;
            result = result + tmp % 10 + tmp / 10;
        } else {
             result = result + creditCard % 10;
        }
            
        if(creditCard / 10 != 0) 
        {
            creditCardPrefix = creditCard % 100;
        }
        creditCard /= 10;
    }
    
    if(result % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if(creditCardPrefix == 34 || creditCardPrefix == 37)
    {
        printf("AMEX\n");
    } else if(creditCardPrefix >= 51 && creditCardPrefix <= 55)
    {
        printf("MASTERCARD\n");
    } else if(creditCardPrefix / 10 == 4)
    {
        printf("VISA\n");
    } else {
        printf("INVALID\n");
    }
    
    return 0;
}