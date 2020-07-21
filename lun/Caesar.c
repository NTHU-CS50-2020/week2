#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


void T(string p)
{
    int k=atoi(p);
    //int atoi(const char *str) 轉換為字符串參數str為整數（int型）
    string t = get_string("plaintext: ");//%
    printf("ciphertext:");
    for (int i = 0; i<=strlen(t) ; i++)
    {
        if(t[i]>'A'&&t[i]<'Z')
        {
            printf("%c",toupper((t[i]+ k-64) % 26)+64);
        }
        else if(t[i]>'a'&&t[i]<'z')
        {
            printf("%c",tolower((t[i] + k-96) % 26)+96);
        }
        else printf("%c", t[i]);
    };
    printf("\n");
}

int main(int c,string a[])
{
    if(c==2)
    {
            for (int i = 0; i<=strlen(a[1]) ; i++)
        {
           if(a[1][i]>='0'&&a[1][i]<='9')T(a[1]);else return 1; 
        }
    }
    else  
    {
        printf("Usage: ./caesar key\n");
        return 1;
        
    }
}