#include <stdio.h>
#include <cs50.h>
#include <string.h>

int power(int a, int b);

int main(int argc ,string argv[])
{
    int n = strlen(argv[1]);
    int move_number;
    int move_number_total = 0;
    //printf("%i\n", n);
    if(argc == 2)
    {
        for(int i = 0; i < n; i++)
        {
            //printf("success\n %i\n", (int)argv[1][i] - 48);
            if ('1' <= argv[1][i] && argv[1][i] <= '9')
            {
                move_number = ((int)argv[1][i] - 48)*power(10, n - i - 1);
                move_number_total = move_number_total + move_number;
            }
            else
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        //printf("%i\n", move_number_total);
    }
    else
    {
        printf("Usage: ./caesar key\n");
    }
    
    int move = move_number_total%26;
    //printf("%i\n", move);
    
    string s = get_string("plaintext:  ");
    int m = strlen(s);
    
    printf("ciphertext: ");
    
    int after_move;
    
    for(int i = 0; i < m; i++)
    {
        if(65 <= s[i] && s[i] <= 90)
        {
            after_move = (int)s[i] + move; 
            if(after_move > 90)
            {
                after_move = after_move - 26;
                printf("%c", after_move);
            }
            else
            {
                printf("%c", after_move);
            }
        }
        else if(97 <= s[i] && s[i] <= 122)
        {
            after_move = (int)s[i] + move; 
            if(after_move > 122)
            {
                int after_move_1 = after_move -26;
                printf("%c", after_move_1);
            }
            else
            {
                printf("%c", after_move);
            }
        }
        else
        {
            printf("%c", s[i]);
        }

    }
    printf("\n");
}




int power(int a, int b)
{
    int solution = 1;
    for(int i = 0; i < b; i++)
    {
        solution = solution*a;
    }
    return solution;
}
