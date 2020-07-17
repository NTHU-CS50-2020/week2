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
        int duplicate[26];
        int key[26];
        if (strlen(argv[1]) < 26) 
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        for (int i = 0; i < 26; i++) 
        {
            if (!(isalpha(argv[1][i])))
            {
                printf("Key must contain 26 characters.\n");
                return 1;
            }
            for (int j = 0; j < i; j++) {
                if (argv[1][i] == duplicate[j]) 
				{
                    printf("Can't repeat\n");
                    return 1;
                }
            }
            duplicate[i] = argv[1][i];
            if (isupper(argv[1][i])) key[i] = argv[1][i] - 65 - i;
            else if (islower(argv[1][i])) key[i] = argv[1][i] - 97 - i;
        }

        string ptext = get_string("plaintext: ");
        printf("ciphertext: ");
        for (int i = 0, n = strlen(ptext); i < n; i++) 
        {
            int alpha = (int)toupper(ptext[i]) - 65;
            if (isupper(ptext[i])) printf("%c", (ptext[i] + key[alpha]));
            else if (islower(ptext[i])) printf("%c", (ptext[i] + key[alpha]));
            else printf("%c", ptext[i]);
        }
        printf("\n");
        return 0;
    }
}