#include <cs50.h>
#include <stdio.h>

int main(){
    //input
    string text = get_string("Text: ");

    //number of letters/words/sentences
    float count_l = 0, count_w = 0, count_s = 0;
    for(int i = 0; text[i] != '\0'; ++i){
        if(text[i] == '.' || text[i] == '?' || text[i] == '!')
            count_s++;
        else if(text[i] >= 'A' && text[i] <= 'Z')
            count_l++;
        else if(text[i] >= 'a' && text[i] <= 'z')
            count_l++;
        else if(text[i] == ' ')
            count_w++;
    }
    if(count_w != 0) count_w++; //last word

    count_l *= (100 / count_w);
    count_s *= (100 / count_w);
    int index = 0.0588 * count_l - 0.296 * count_s - 15.8 + 0.5; //+0.5 for round

    //output
    if(index < 1)
        printf("Before Grade 1\n");
    else if(index >= 16)
        printf("Grade 16+\n");
    else
        printf("Grade %d\n", index);

    return 0;
}