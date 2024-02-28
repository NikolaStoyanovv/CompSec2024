#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* caesar_cypher(char* str, int key)
{
    int length = strlen(str);
    char* cypher = (char*) malloc(sizeof(char) * (length + 1));
    
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] >= 97 & str[i] <= 122){
           
            //lowercase
            cypher[i] = ((str[i] - 'a' - key + 26)%26) + 'a';
            i++;
        }
        if(str[i] >= 65 & str[i] <= 90){
            //uppercase
            cypher[i] = ((str[i] - 'A' - key + 26) % 26) + 'A';
            i++;
        }
        if(str[i] >= 48 & str[i] <= 57){
            //digits
            cypher[i] = ((str[i] - '0' - key + 9)% 9) + '0';
            i++;
        }
    }
    cypher[i] = '\0';
    
    return cypher;
}

int main() {
    const int MAXN = 1000;
    char str[MAXN];
    scanf("%s", str);
    
    int key;
    printf("Enter key:");
    scanf("%d", &key);
    
    char* cypher = caesar_cypher(str, key);
    
    printf("%s", cypher);
    
    return EXIT_SUCCESS;
}
