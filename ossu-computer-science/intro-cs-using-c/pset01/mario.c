#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height = 0;
    int minHeight = 1;
    int maxHeight = 23;
    
    while(height < minHeight || height > maxHeight)
    {
        printf("Give the height of the desired pyramid: ");
        height = get_int();
    }
    
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < (height + 1) * 2; j++)
        {
            j < height - i || (j > height && j < height + 2) || j > height + 2 + i
                ? printf(" ")
                : printf("#");
        }
         printf("\n");
    }
}