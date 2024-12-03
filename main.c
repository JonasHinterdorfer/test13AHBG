#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int DoubleString(char* text, char* newText);

void ShuffleString(char* text, char* newText, char c);


int main()
{
    char text[200];
    char c;
    printf("Please enter a string: ");
    scanf("%s", text);
    printf("Please enter a char: ");
    scanf(" %c", &c);
    printf("Eingabe1: %s\n", text);

    char newText[strlen(text) * 2 ];
    int length = DoubleString(text, newText);

    printf("Ausgabe1: %s\n", newText);
    printf("Neue Länge: %d\n", length);

    char shuffledText[strlen(text) +1 ];
    ShuffleString(text, shuffledText, c);
    printf("Ausgabe2: %s\n", shuffledText);


    return 0;
}

int DoubleString(char* text, char* newText)
{
    int length = strlen(text);
    strcpy(newText, text);

    for(int i = 0; i < length; i ++)
    {
        newText[length + i] = text[length - i - 1];
    }
    newText[length*2] = '\0';
    return length *2;
}

void ShuffleString(char* text, char* newText, char c){
    int length = strlen(text);
    strcpy(newText, text);

    for (int i = 0; i < length; ++i) {
        int rand1 = rand() % (length -1);
        int rand2 = rand() % (length -1);

        char tmp = newText[rand1];
        newText[rand1] = newText[rand2];
        newText[rand2] = tmp;
    }
    newText[length] = c;
    newText[length +1] = '\0';
}
