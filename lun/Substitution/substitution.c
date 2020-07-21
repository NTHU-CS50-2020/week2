#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool key(string t)
{
    int o=0;
    for (int i = 0; i<=strlen(t) ; i++)
    {
        if((!(t[i]==' '||t[i]=='\0'))&&((t[i]>='a'&&t[i]<='z')||(t[i]>='A'&&t[i]<='Z'))) o++;
    }
    return ( o == 26) ? true : false;
}
void T(string h)
{
    string t = get_string("plaintext: ");//%c
    string y= NULL;
    printf("ciphertext:");

    for (int i = 0; i<=strlen(t) ; i++)
    {
        if(t[i]>'A'&&t[i]<'Z')
        {
            for (int n = 0; n<=25 ; n++)
            {
                if(t[i]==65+n)    printf("%c",toupper(h[n]));
            }
        }
        else if(t[i]>'a'&&t[i]<'z')
        {
            for (int n = 0; n<=25 ; n++)
            {
                if(t[i]==97+n)    printf("%c", tolower(h[n]));
            }
        }else printf("%c", t[i]);
    }
    printf("\n");
}

int main(int c,string v[])//為甚麼需要int n(是段落嗎?)，然後再用[]
{
    if(c==2)
    {
        bool k=key(v[1]);

        if(k)  T(v[1]);
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    else  printf("Usage: ./substitution key\n");
}
