#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <cs50.h>

int key = 0;

bool checkArg(int argc, char*argv[]){
    //print the args
    for(int i = 0; i<argc; i++){
        printf("arg %d : %s\n", i, *(i+argv));
    }

    //check the arg
    if(argc == 2){// ./caeser key
        for(int i = 0; i<strlen(*(1+argv)); i++){
            if(!isdigit((*(1+argv))[i])){//key is not a int
                printf("Usage: ./caesar key\n");
                return false;
            }
            key = key * 10 + ((*(1+argv))[i] - '0');
        }
        printf("Success\n%d\n", key);
    }else{
        printf("Usage: ./caesar key\n");
        return false;
    }
    return true;
}

char *cipherText(char *plainText){
    //ci = (pi + k) % 26
    char *cipherText =  malloc(sizeof(char) * (strlen(plainText)));
    for(int i = 0; i<strlen(plainText); i++){
        if(islower(plainText[i])){
            int pi = plainText[i] - 'a';
            int ci = (pi + key) % 26;
            cipherText[i] = ci + 'a';
        }else if(isupper(plainText[i])){
            int pi = plainText[i] - 'A';
            int ci = (pi + key) % 26;
            cipherText[i] = ci + 'A';
        }else{
            cipherText[i] = plainText[i];
        }
    }
    return cipherText;
}

int main(int argc, char*argv[]){
    if(checkArg(argc, argv)){
        char *plainText = get_string("plaintext:  ");
        printf("ciphertext: %s\n", cipherText(plainText));
        return 0;
    };
    return 1;
}