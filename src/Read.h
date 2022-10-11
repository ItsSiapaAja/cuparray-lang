#include "Interpreter.h"

int searchExt(char* fileName)
{
    char* ext = strrchr(fileName, '.');
    if(!ext)
    {
        return -1;
    }

    if(strncmp(ext + 1, "crr", 3) == 0)
    {
        return 0;
    }

    return -1;
}

int readFile(char* fileName)
{
    if(searchExt(fileName) < 0)
    {
        printf("Cup : Wrong file extention\n");
        return -1;
    }

    FILE *file;
    file = fopen(fileName, "r");

    if(!file)
    {
        printf("Cup : Failed to open the file\n");
        return -1;
    }

    char c;
    char* text = (char*) malloc(sizeof(char) * MAX_LENGTH);

    int i = 0;
    while ((c = fgetc(file)) != EOF)
    {
        text[i] = c;
        text[i + 1] = '\0';
        int progress = interpreter(text);

        if(progress == 0)
        {
            memset(text, 0, sizeof(text));
            i = 0;
        }
        else if(progress < 0)
        {
            break;
        }
        else
        {
            i++;
        }
    }

    text[i] = '\0';

    if(toktype == STRING)
    {
        printf("\t");
        MissingChar();
    }
    else if(toktype == KEYWORD || in == KEYWORD)
    {
        printf("\t");
        UnknownArgument();
    }
    else if(toktype == NOTHING)
    {
        printf("\t");
        UnexpectedIdentifier();
        printf("\t");
        UnexpectedIdentifier();
    }

    // printf("<TOKEN-TYPE : %d>\n", toktype);
    
    clearTape();
    fclose(file);
    free(text);
    return 0;
}