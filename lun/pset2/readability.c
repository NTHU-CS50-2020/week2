#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>//round - round to nearest integer, away from zero

float l(string t)
{
    float o=0;
    for (int i = 0; i<=strlen(t)-1 ; i++)
    {
        if(t[i]>=33&&t[i]<=47) ;
        else if(t[i]>=58&&t[i]<=64) ;
        else if(t[i]!=' ') o++;
    }

    float u=0;
    for (int i = 0; i<=strlen(t) ; i++)
    {
        if(t[i]==' '||t[i]=='\0') u++;
    }
    return o/u*100;
    //L is the average number of letters per 100 words in the text
}

float s(string t)
 {
    float o=0;
    for (int i = 0; i<=strlen(t) ; i++)
    {
        if(t[i]==' '||t[i]=='\0') o++;
    }
    
    float s=0;
    for (int i = 0; i<strlen(t) ; i++)
    {
        if(t[i]=='.'||t[i]=='!'||t[i]=='?') s++;
    };
    return s/o*100;
    //with a . or a ! or a ? to be a sentence 
    //S is the average number of sentences per 100 words in the text
}

void grade(float l,float s)
{
    int g=round(0.0588 *l- 0.296 *s- 15.8);
    if(g<1)
    {
    printf("Before Grade 1");
    }else if(g>=16)
    {
        printf("Grade 16+");
    }else printf("Grade %i",g);
    //If the resulting index number is 16 or higher
    //(equivalent to or greater than a senior undergraduate reading level),
    //your program should output "Grade 16+"
    //If the index number is less than 1,
    //your program should output "Before Grade 1".
    printf("\n");
}
int main(void)
{
    string t = get_string("Text:");//%c
    grade(l(t),s(t));
}

