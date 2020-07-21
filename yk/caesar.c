#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

bool checkKey(string key);

int main(int argc, string argv[]){
    //handle key
    if(argc != 2) return 1;
    if(!checkKey(argv[1])) return 1;
    int key = atoi(argv[1]) % 26;

    //input
    string text = get_string("plaintext:  ");

    for(int i = 0; text[i] != '\0'; ++i){
        int tmp = text[i];
        if(text[i] >= 'A' && text[i] <= 'Z'){
            tmp += key;
            if(tmp > 'Z') tmp -= 26;
        }else if(text[i] >= 'a' && text[i] <= 'z'){
            tmp += key;
            if(tmp > 'z') tmp -= 26;
        }
        text[i] = tmp;
    }

    //output
    printf("ciphertext: %s\n", text);

    return 0;
}

bool checkKey(string key){
    for(int i = 0; key[i] != '\0'; ++i){
        if(!isdigit(key[i])) return false;
    }
    return true;
}