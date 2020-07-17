#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int main(void)
{
    string t = get_string("Text: ");
    int l_count, w_count, s_count;
    l_count = w_count = s_count = 0;
    int flag = 1;
    int n = strlen(t);
    for (int i = 0; i < n; i++)
    {
        if (isalpha(t[i])) l_count += 1;
        if (t[i] == '.' || t[i] == '!' || t[i] == '?') s_count += 1;
        if(flag && !(isspace(t[i])))
        {
            w_count += 1;
            flag = 0;
        }
        else if(isspace(t[i])) flag=1;
    }
    float L = (float)l_count / w_count * 100;
    float S = (float)s_count / w_count * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int g = round(index);
    if (g > 16) printf("Grade 16+\n");
    else if (g < 1) printf("Before Grade 1\n");
    else printf("Grade %d\n", g);
    
    return 0;
}