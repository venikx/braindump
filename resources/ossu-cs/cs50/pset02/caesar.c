#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
  if (argc >= 2)
    {
      int code = atoi(argv[1]);
      string text = get_string("plaintext: ");
      for (int i = 0, n = strlen(text); i < n; i++)
        {
          char c = text[i];
          if (isupper(c))
            {
              text[i] = ((text[i] - 65 + code) % 26) + 65;
            }
          else if (islower(c))
            {
              text[i] = ((text[i] - 97 + code) % 26) + 97;
            }
        }
      printf("ciphertext: %s\n", text);
      return 0;
    }
  else
    {
      printf("Not enough arguments");
      return 1;
    }
}
