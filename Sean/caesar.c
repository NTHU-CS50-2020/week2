#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++) 
        {
            if (!(isdigit(argv[1][i]))) 
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        string ptext = get_string("plaintext: ");
        int key = atoi(argv[1])%26;
        printf("ciphertext: ");
        for (int i = 0, n = strlen(ptext); i < n; i++) 
        {
            if (isupper(ptext[i])) printf("%c", (ptext[i] - 64 + key) % 26 + 64);
            else if (islower(ptext[i])) printf("%c", (ptext[i] - 96 + key) % 26 + 96);
            else printf("%c", ptext[i]);
        }
        printf("\n");
        return 0;
    }
}