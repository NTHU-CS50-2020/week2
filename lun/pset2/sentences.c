#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>//round - round to nearest integer, away from zero

float s(string t)
 {
    float o=0;
    for (int i = 0; i<=strlen(t)-1 ; i++)
    {
        if(t[i]>=33&&t[i]<=47) ;
        else if(t[i]>=58&&t[i]<=64) ;
        else if(t[i]!=' ') o++;
    }
    
    float s=0;
    for (int i = 0; i<strlen(t) ; i++)
    {
        if(t[i]=='.'||t[i]=='!'||t[i]=='?') s++;
    };
    return s;//,o,s/(o/s)*100;
    //with a . or a ! or a ? to be a sentence 
    //S is the average number of sentences per 100 words in the text
}

int main(void)
{
    string t = "Congratulations! Today is your day. You're off to Great Places! You're off and away!";//%c
    
    float o=0;
    for (int i = 0; i<=strlen(t) ; i++)
    {
        if(t[i]==' '||t[i]=='\0') o++;
    }
    
    printf("%.2f\n",o);
    
    float s=0;
    for (int i = 0; i<strlen(t) ; i++)
    {
        if(t[i]=='.'||t[i]=='!'||t[i]=='?') s++;
    };
    printf("%.2f\n",s);//,o,s/(o/s)*100;
    printf("%.2f\n",s/o*100);
    //with a . or a ! or a ? to be a sentence 
    //S is the average number of sentences per 100 words in the text
    

}
/*int s(string t)
 {
    int s=0;
    for (int i = 0; i<strlen(t) ; i++)//t[i]!='\0'  呈現
    {//ends with a . or a ! or a ? to be a sentence
        if(t[i]=='.') s++;
        if(t[i]=='!') s++;
        if(t[i]=='?') s++;
    };
    return round(s/strlen(t)*100);
}*/