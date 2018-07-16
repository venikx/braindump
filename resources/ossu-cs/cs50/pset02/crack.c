#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#define SIZE 5

// BRUTE FORCE ATTACK
int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./crack hash/n");
        return 1;
    }
    string hash = argv[1];
    char salt[3] = {hash[0], hash[1], '\0'};
    string letters = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm";
    int lettersLength = strlen(letters);
    for (int a = 0; a < SIZE; a++)
    {
        char password[a + 2];
        password[a + 1] = '\0';
        for (int b = 0; b < lettersLength && a >= 0; b++)
        {
            password[0] = letters[b];
            if (strcmp(crypt(password, salt), hash) == 0)
            {
                printf("%s\n", password);
                return 0;
            }
            for (int c = 0; c < lettersLength && a >= 1; c++)
            {
                password[1] = letters[c];
                if (strcmp(crypt(password, salt), hash) == 0)
                {
                    printf("%s\n", password);
                    return 0;
                }
                for (int d = 0; d < lettersLength && a >= 2; d++)
                {
                    password[2] = letters[d];
                    if (strcmp(crypt(password, salt), hash) == 0)
                    {
                        printf("%s\n", password);
                        return 0;
                    }
                    for (int e = 0; e < lettersLength && a >= 3; e++)
                    {
                        password[3] = letters[e];
                        if (strcmp(crypt(password, salt), hash) == 0)
                        {
                            printf("%s\n", password);
                            return 0;
                        }
                        for (int f = 0; f < lettersLength && a >= 4; f++)
                        {
                            password[4] = letters[f];
                            if (strcmp(crypt(password, salt), hash) == 0)
                            {
                                printf("%s\n", password);
                                return 0;
                            }
                        }
                    }
                }
            }
        }
        printf("No matching words with %d character(s).\n", a+1);
    }
    return 1;
}
