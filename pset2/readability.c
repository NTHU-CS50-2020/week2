#include <stdio.h>
#include <cs50.h>
int index(int L,int S)
 {
    int index=0;
    index = 0.0588 * L - 0.296 * S - 15.8;
    return index;
    /*L is the average number of letters per 100 words in the text, 
    and S is the average number of sentences per 100 words in the text*/
 }   
int main(void)
{
    string t = get_string("Text");
    //%c
    
    for (int i = 0; i <= 10; i++)
    {
        t[i]="";
        //get_string;
    }
    
    int l=0;int s=0;
    printf("Grade %i\n",index(l,s));
}

 