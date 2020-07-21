#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string s = get_string("Text: ");
    int n = strlen(s);

    int letter = 0;
    int word = 0;
    int sentence = 0;

    for(int i = 0 ; i < n ; i++)
    {
       
        if(('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z'))
        {
            letter = letter + 1;
        }
        else if(s[i] == ' ')
        {
            word = word + 1;
        }
        else if (s[i] == '.' || s[i] == '!')
        {
            sentence = sentence + 1;
        }
    }
    int word_real = word + 1;
    printf(" %i letters\n %i words\n %i sentense\n", letter, word_real, sentence);
    
    float multiple = 100 / (float)word_real;
    float letter_per = letter * multiple;
    //int letter_2f =letter_per * 100;
    //float L = (float)letter_2f / 100;
    float sentence_per = sentence * multiple;
    //int sentence_2f = sentence_per * 100;
    //float S = (float)sentence_2f / 100;
    
    printf("%f letter_per100\n %f sentenct_per100\n", letter_per, sentence_per);
    
    float degree = (0.0588 * letter_per) - (0.296 * sentence_per) - 15.8;
    
    int degree_precise;
    
    if(((int)(degree * 10) % 10) >= 5)
    {
        degree_precise = (int)degree + 1;
    }
    else
    {
        degree_precise = (int)degree;
    }
    printf("degree: %i\n", degree_precise);
}