#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

void T(string h)
{
    string t = get_string("plaintext: ");//%c
    string y= t;        
    printf("ciphertext:");
    
    for (int i = 0; i<=strlen(t) ; i++)
    {
        if(t[i]>'A'&&t[i]<'Z')
        {
            for (int n = 0; n<=25 ; n++)
            {
                if(t[i]==65+n)    y[i]=toupper(h[n]); 
            }
        }
        else if(t[i]>'a'&&t[i]<'z') 
        {
            for (int n = 0; n<=25 ; n++)
            {
                if(t[i]=='a'+n)    y[i]=tolower(h[n]); 
            }
        }
    }
    printf("%s\n",y);
}

int main(int c,string v[])//為甚麼需要int n(是段落嗎?)，然後再用[]
{

    v[1]="JTREKYAVOGDXPSNCUIZLFBMWHQ";
    printf("%s\n",v[1]);
    T(v[1]);
}