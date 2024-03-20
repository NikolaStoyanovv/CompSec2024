#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXN 1024

char* vigenere_decrypt(char* cipher, char* key)
{
    int length = strlen(cipher);
    int key_length = strlen(key);
    char* plaintext = (char*) malloc(sizeof(char) * (length + 1));
    int index = 0;
    while(cipher[index] != '\0')
    {
        int shift = tolower(key[index % key_length]) - 'a';
        
        if(islower(cipher[index]))
        {
            plaintext[index] = 'a' + (cipher[index] - 'a' - shift + 26) % 26;
        }
        else if(isupper(cipher[index]))
        {
            plaintext[index] = 'A' + (cipher[index] - 'A' - shift + 26) % 26;
        }
        else
        {
            plaintext[index] = cipher[index];    
        }
        index++;
    }
    plaintext[index] = '\0';
    return plaintext;
}


char* read_decypher(char* filename)
{
    FILE* file;
    file = fopen(filename, "r");
    
    if(file == NULL)
    {
        printf("Error reading from file.");
        return NULL;
    }
    
    char* decipher = (char*) malloc(MAXN * sizeof(char));
    if(fgets(decipher, MAXN, file) == NULL)
    {
        printf("Error reading from file.");
        
        return NULL;
    }
    
    
    fclose(file);
    return decipher;
}

char* read_key(char* filename)
{
    FILE* file;
    file = fopen(filename, "r");
    
    if(file == NULL)
    {
        printf("Error reading from file.");
        return NULL;
    }
    
    char* key = (char*) malloc(MAXN * sizeof(char));
    if(fgets(key, MAXN, file) == NULL)
    {
        printf("Error reading from file.");
        
        return NULL;
    }
    
    
    fclose(file);
    return key;
}

int main()
{
    
    
    char* result = vigenere_decrypt(read_decypher("ciper.txt"), read_key("key.txt"));

    printf("Result: %s", result);
    return EXIT_SUCCESS;
}
