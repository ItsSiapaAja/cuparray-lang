#include "DataType.h"

/*******************************
 * 
 * Parse Function
 * 
 * return 0 = clearChar
 * return 1 = keepChar
 * return -1 = error
 * 
*******************************/

// Echo command
int echoExec(char* text)
{
    if(toktype == STRING)
    {
        return stringParse(text);
    }

    if(strncmp(text, "\"", 1) == 0)
    {
        toktype = STRING;
        return 0;
    }
    else if(strncmp(text, " ", 1) == 0)
    {
        return 0;
    }
    else if(strncmp(text, ";", 1) == 0)
    {
        toktype = EMPTY_END;
        in = EMPTY_END;
        strcpy(val.stringValue, escapeChar(val.stringValue));
        printf("%s", val.stringValue);
        strcpy(val.stringValue, "");
        return 0;
    }
    else
    {
        return -1;
    }
}

// Executing a mnemonic keyword
int mnemonicExec(char* text, char mode)
{
    int lengthInput = strlen(text) - 1;
    switch (toktype)
    {
    case DATATYPE:
        if(text[lengthInput] == ':' || text[lengthInput] == ' ')
        {
            text[lengthInput] = '\0';
            return checkDatatype(text, 1);
        }
        else
        {
            return 1;
        }

        break;
    case INTEGER:
        return integerParse(text, lengthInput);
    case OPENING_CHAR:
        return charParse(text);
    case CHAR:
        return charParse(text);
    case OPENING_STRING:
        if(text[lengthInput] == '\"')
        {
            toktype = STRING;
            return 0;
        }
        else
        {
            return -1;
        }
    case STRING:
        return stringParse(text);
    case FLOAT:
        return floatParse(text, lengthInput);
    case INDEX:
        return indexMnemonic(text, lengthInput, mode);
    case POINTER:
        return indexMnemonic(text, lengthInput, mode);
    case KEYWORD:
        if(strncmp(text, " ", 1) == 0 && 
        (strcmp(val.stringValue, "") == 0 || val.charValue == '\0'))
        {
            toktype = DATATYPE;
            return 0;
        }
        else if(strncmp(text, ":", 1) == 0 && 
        (strcmp(val.stringValue, "") != 0 || val.charValue != '\0'))
        {
            toktype = INDEX;
            return 0;
        }
        else
        {
            return -1;
        }

        break;
    }
}

// arr_dump for outputting an array value
int arrDumpExec(char* text)
{
    int lengthInput = strlen(text) - 1;
    switch (toktype)
    {
    case DATATYPE:
        if(text[lengthInput] == ' ')
        {
            text[lengthInput] = '\0';
            return checkDatatype(text, 0);
        }
        else
        {
            return 1;
        }
        break;
    case INDEX:
        return indexDump(text, lengthInput, 1);
    case KEYWORD:
        if(strncmp(text, " ", 1) == 0)
        {
            toktype = DATATYPE;
            return 0;
        }
        break;
    }
}

// arr_get for getting user input
int arrGetExec(char* text)
{
    int lengthInput = strlen(text) - 1;
    switch (toktype)
    {
    case DATATYPE:
        if(text[lengthInput] == ' ')
        {
            text[lengthInput] = '\0';
            return checkDatatype(text, 0);
        }
        else
        {
            return 1;
        }
        break;
    case INDEX:
        return indexDump(text, lengthInput, 0);
    case KEYWORD:
        if(strncmp(text, " ", 1) == 0)
        {
            toktype = DATATYPE;
            return 0;
        }
        break;
    }
}

// Executing two operand
int twoOperandExec(char* text, char mode)
{
    int length = strlen(text) - 1;
    switch (toktype)
    {
    case DATATYPE:
        if(text[length] == ':')
        {
            text[length] = '\0';
            return checkDatatype(text, 0);
        }
        else
        {
            return 1;
        }
    case INDEX:
        return indexTwoLogical(text, length, mode);
    case LOGICAL:
        if(strncmp(text, " ", 1) == 0)
        {
            toktype = DATATYPE;
            return 0;
        }
        break;
    }
}

// Logical operation
int logicalParse(char* textBuffer, char* keyword)
{
    if(strcmp(keyword, "EQ") == 0)
    {
        return twoOperandExec(textBuffer, '=');
    }
    else if(strcmp(keyword, "GT") == 0)
    {
        return twoOperandExec(textBuffer, '>');
    }
    else if(strcmp(keyword, "LT") == 0)
    {
        return twoOperandExec(textBuffer, '<');
    }
}

// Keyword parser
int keywordParse(char* textBuffer, char* keyword)
{
    if(strncmp(keyword, "echo", 4) == 0)
    {
        return echoExec(textBuffer);
    }
    else if(strncmp(keyword, "NEW", 3) == 0)
    {
        return mnemonicExec(textBuffer, '=');
    }
    else if(strncmp(keyword, "ADD", 3) == 0)
    {
        return mnemonicExec(textBuffer, '+');
    }
    else if(strncmp(keyword, "SUB", 3) == 0)
    {
        return mnemonicExec(textBuffer, '-');
    }
    else if(strncmp(keyword, "MUL", 3) == 0)
    {
        return mnemonicExec(textBuffer, '*');
    }
    else if(strncmp(keyword, "DIV", 3) == 0)
    {
        return mnemonicExec(textBuffer, '/');
    }
    else if(strncmp(keyword, "arr_dump", 8) == 0)
    {
        return arrDumpExec(textBuffer);
    }
    else if(strncmp(keyword, "arr_get", 7) == 0)
    {
        return arrGetExec(textBuffer);
    }
}