#include <stdio.h>

void main(){
    char ch;
    printf("Enther any Character: \n");
    scanf("%c",&ch);

    switch (ch){
    case 'a': case 'A':
    case 'e': case 'E':
    case 'i': case 'I':
    case 'o': case 'O':
    case 'u': case 'U':

        printf("You Have Enter Vowel\n");
        break;
    default:
        printf("You have Enter Consonant\n");
    }
    getchar();
}