#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>//round - round to nearest integer, away from zero

int l(string t)
{
/*    int o=0;
    for (int i = 0; i<t[i]!='\0' ; i++)
    {
        o=i;
    }
    return round(o/strlen(t)*100);
*/
}
int s(string t)
 {
/*
    int s=0;
    for (int i = 0; i<strlen(t) ; i++)//t[i]!='\0'  呈現
    {//ends with a . or a ! or a ? to be a sentence
        if(t[i]=='.') s++;
        if(t[i]=='!') s++;
        if(t[i]=='?') s++;
    };
    return round(s/strlen(t)*100);
*/
}
int index(int l,int s)
{
    return round(0.0588 *l- 0.296 *s- 15.8);
    /*L is the average number of letters per 100 words in the text,
    and S is the average number of sentences per 100 words in the text*/
}
void grade(int l,int s)
{
    int g=index(l,s);
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

