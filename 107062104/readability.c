#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <cs50.h>

double letters = 0, words = 0, sentences = 0;

void count(char* text){
    int len = strlen(text);
    for(int i = 0; i<len ;i++){
        if(isalpha(text[i])){
            letters++;
        }else if(isspace(text[i])){//every word has a space after except last one
            words++;
        }else if(text[i] == '.' || text[i] == '!' || text[i] == '?'){//"."=46, "!"=33, "?"=63
            sentences++;
        }
    }
    words++;//for the last word with no space after
    //printf("letters:%f, words:%f, sentences:%f\n", letters, words, sentences);
}

double gradeCal(){
    double index;//index = 0.0588 * L - 0.296 * S - 15.8
    double L, S;//L = # letters per 100 words, S = # words per 100 sentences
    L = letters/words*100;
    S = sentences/words*100;
    //printf("L:%f, S:%f\n", L, S);
    index = round(0.0588 * L - 0.296 * S - 15.8);
    return index;
}

void printGrade(double grade){
    if(grade<1){
        printf("Before Grade 1\n");
    }else if(grade>16){
        printf("Grade 16+\n");
    }else{
        printf("Grade %.0f\n", grade);
    }
}

int main(){
    char *text = get_string("Text: ");
    count(text);
    printGrade(gradeCal());
    return 0;
}