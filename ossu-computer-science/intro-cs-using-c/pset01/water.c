#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("How long do you shower (in minutes)? ");
    int minutes = get_int();
    
    printf("%i minutes of showerin, equal %i bottles of 1l\n", minutes, minutes * 3);
}