#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool checkTable(string table);

int main(int argc, string argv[]){
    if(argc != 2) return 1;
    if(!checkTable(argv[1])) return 1;

    //make a offset table
    int offset[26];
    for(int i = 0; i < 26; ++i){
        char c = toupper(argv[1][i]);
        offset[i] = (c - 'A') - i;
    }

    //input
    string text = get_string("plaintext:  ");

    for(int i = 0; text[i] != '\0'; ++i){
        if(text[i] >= 'A' && text[i] <= 'Z')
            text[i] += offset[text[i]-'A'];
        else if(text[i] >= 'a' && text[i] <= 'z')
            text[i] += offset[text[i]-'a'];
    }

    //output
    printf("ciphertext: %s\n", text);

    return 0;
}

bool checkTable(string table){
    if(strlen(table) != 26) return false;
    bool used[26] = {0};
    for(int i = 0; i < 26; ++i){
        char c = toupper(table[i]);
        if(used[c - 'A'] == true) return false;
        if(c < 'A' || c > 'Z') return false;
        used[c - 'A'] = true;
    }
    return true;
}