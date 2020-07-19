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

int main(void)
{
    string t = "Congratulations! Today is your day. You're off to Great Places! You're off and away!";//%c
    printf("%.2f\n",l(t));
    string g = "Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year. For another, he really wanted to do his homework, but was forced to do it in secret, in the dead of the night. And he also happened to be a wizard.";
    printf("%.2f\n",l(g));
}

/*int l(string t)
{
    int o=0;
    for (int i = 0; i<t[i]!='\0' ; i++)
    {
        o=i;
    }
    return round(o/strlen(t)*100);
}*/