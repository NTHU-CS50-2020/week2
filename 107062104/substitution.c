#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <cs50.h>

int key[26] = {0};
bool vis[26] = {false};

bool checkArg(int argc, char*argv[]){
    //print the args
    for(int i = 0; i<argc; i++){
        printf("arg %d : %s\n", i, *(i+argv));
    }

    //check the arg
    if(argc == 2){// ./substitution key
        if(strlen(*(1+argv)) == 26){
            for(int i = 0; i<26; i++){
                if(!isalpha((*(1+argv))[i])){//key is not an alpha
                    printf("Key must contain 26 characters\n");
                    return false;
                }else{
                    if(islower((*(1+argv))[i])){
                        key[i] = (*(1+argv))[i] - 'a';
                        if(vis[key[i]]){
                            printf("Duplicate chars\n");
                            return false;
                        }
                        vis[key[i]] = true;
                    }else{
                        key[i] = (*(1+argv))[i] - 'A';
                        if(vis[key[i]]){
                            printf("Duplicate chars\n");
                            return false;
                        }
                        vis[key[i]] = true;
                    }
                }
            }
            printf("Success\n");
        }else{//other than 26 chars
            printf("Key must contain 26 characters\n");
            return false;
        }
    }else{
        printf("Usage: ./substitution key\n");
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
            int ci = key[pi];
            cipherText[i] = ci + 'a';
        }else if(isupper(plainText[i])){
            int pi = plainText[i] - 'A';
            int ci = key[pi];
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