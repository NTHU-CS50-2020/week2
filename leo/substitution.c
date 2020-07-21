#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc ,string argv[])
{
    int num_argv = strlen(argv[1]);
    if(argc == 2)
    {
        if(num_argv ==26)
        {
            printf("success\n");
        }
        else
        {
            printf("key must contain 26 charrcters.\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string s = get_string("plaintext:  ");
    int num_plaintext = strlen(s);
    
    printf("cuphertext: ");
    
    int number;
    for(int i = 0; i < num_plaintext; i++)
    {
        if('A' <= s[i] && s[i] <= 'Z')
        {
            number = (int)s[i] - 65;
            printf("%c", argv[1][number]);
        }
        else if('a' <= s[i] && s[i] <= 'z')
        {
            number = (int)s[i] - 97;
            printf("%c", argv[1][number] + 32);
        }
        else
        {
            printf("%c", s[i]);
        }

    }
    
    printf("\n");
    
}