#include <stdio.h>
#include <cs50.h>
#include <string.h>
bool key(string t)
{
    int o=0;
    for (int i = 0; i<=strlen(t) ; i++)
    {
        if((!(t[i]==' '||t[i]=='\0'))&&((t[i]>='a'&&t[i]<='z')||(t[i]>='A'&&t[i]<='Z'))) o++;
    }
    return ( o == 26) ? true : false;
}
void T(string n)
{
    printf("T");
}

int main(int c,string v[])//為甚麼需要int n(是段落嗎?)，然後再用[]
{

    bool k=key(v[1]);
    printf("%i\n",c);
    printf("%lu",strlen(v[1]));
    if(k)   printf("T");
    printf("\n");
}