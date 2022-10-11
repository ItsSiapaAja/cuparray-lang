#include "InitParser.h"

char* escapeChar(char* text);

int checkDatatype(char* text, int gotoType)
{
    switch (gotoType)
    {
    case 1:
        if(strncmp(text, "int32", 5) == 0 || 
        strncmp(text, "int64", 5) == 0 || 
        strncmp(text, "int16", 5) == 0)
        {
            toktype = INTEGER;
            strcpy(val.datatype, text);
            return 0;
        }
        else if(strncmp(text, "char", 4) == 0)
        {
            toktype = OPENING_CHAR;
            strcpy(val.datatype, text);
            return 0;
        }
        else if(strncmp(text, "string", 6) == 0)
        {
            toktype = OPENING_STRING;
            strcpy(val.datatype, text);
            return 0;
        }
        else
        {
            UnexpectedDatatype();
            return -1;
        }
        break;
    case 0:
        if(strncmp(text, "int32", 5) == 0 || 
        strncmp(text, "int64", 5) == 0 || 
        strncmp(text, "int16", 5) == 0 || 
        strncmp(text, "char", 5) == 0 || 
        strncmp(text, "string", 6) == 0)
        {
            toktype = INDEX;
            strcpy(val.datatype, text);
            return 0;
        }
        else
        {
            UnexpectedDatatype();
            return -1;
        }
        break;
    }
}

int indexNew(char* text, int length)
{
    if(isdigit(text[length]))
    {
        strcpy(val.iChr, text);
        return 1;
    }
    else if(strrchr(text, ';'))
    {
        toktype = EMPTY_END;
        in = EMPTY_END;
        val.i = atoi(val.iChr);

        if(val.i >= TAPE_SIZE)
        {
            OutOfRange();
            return -1;
        }

        if(strcmp(val.datatype, "int32") == 0)
        {
            long int temp = atoi(val.stringValue);

            if(temp >= _MAX_INT32_ || temp <= _MAX_INT32_SIGNED_)
            {
                OutOfSize();
                return -1;
            }

            tape.int32Arr[val.i] = temp;
        }
        else if(strcmp(val.datatype, "int64") == 0)
        {
            long long int temp = atoi(val.stringValue);

            if(temp >= _MAX_INT64_ || temp <= _MAX_INT64_SIGNED_)
            {
                OutOfSize();
                return -1;
            }

            tape.int64Arr[val.i] = temp;
        }
        else if(strcmp(val.datatype, "int16") == 0)
        {
            short temp = atoi(val.stringValue);

            if(temp >= _MAX_INT16_ || temp <= _MAX_INT16_SIGNED_)
            {
                OutOfSize();
                return -1;
            }

            tape.int16Arr[val.i] = temp;
        }
        else if(strcmp(val.datatype, "char") == 0)
        {
            char temp = val.charValue;
            tape.charArr[val.i] = temp;
        }
        else if(strcmp(val.datatype, "string") == 0)
        {
            strcpy(val.stringValue, escapeChar(val.stringValue));
            strcpy(tape.stringArr[val.i], val.stringValue);
        }
        
        strcpy(val.stringValue, "");
        strcpy(val.datatype, "");
        val.i = 0;
        val.sign = 0;
        val.charValue = '\0';
        return 0;
    }
    else
    {
        OutOfRange();
        return -1;
    }
}

void outDump()
{
    if(strcmp(val.datatype, "int64") == 0)
    {
        printf("%d", tape.int64Arr[val.i]);
    }
    else if(strcmp(val.datatype, "int32") == 0)
    {
        printf("%d", tape.int32Arr[val.i]);
    }
    else if(strcmp(val.datatype, "int16") == 0)
    {
        printf("%d", tape.int16Arr[val.i]);
    }
    else if(strcmp(val.datatype, "char") == 0)
    {
        printf("%c", tape.charArr[val.i]);
    }
    else if(strcmp(val.datatype, "string") == 0)
    {
        printf("%s", tape.stringArr[val.i]);
    }
}

void getArr()
{
    if(strcmp(val.datatype, "int64") == 0)
    {
        scanf("%d", &tape.int64Arr[val.i]);
    }
    else if(strcmp(val.datatype, "int32") == 0)
    {
        scanf("%d", &tape.int32Arr[val.i]);
    }
    else if(strcmp(val.datatype, "int16") == 0)
    {
        scanf("%d", &tape.int16Arr[val.i]);
    }
    else if(strcmp(val.datatype, "char") == 0)
    {
        val.charValue = fgetc(stdin);
        tape.charArr[val.i] = val.charValue;
    }
    else if(strcmp(val.datatype, "string") == 0)
    {
        scanf("%1000[^\n]", val.stringValue);
        strcpy(tape.stringArr[val.i], val.stringValue);
    }
}

int indexDump(char* text, int length, int mode)
{
    if(isdigit(text[length]))
    {
        strcpy(val.iChr, text);
        return 1;
    }
    else if(strrchr(text, ';'))
    {
        toktype = EMPTY_END;
        in = EMPTY_END;
        val.i = atoi(val.iChr);

        if(val.i >= TAPE_SIZE)
        {
            OutOfRange();
            return -1;
        }

        switch (mode)
        {
        case 1:
            outDump();
            break;
        case 0:
            getArr();
            break;
        }

        val.i = 0;
        strcpy(val.iChr, "");
        strcpy(val.datatype, "");
        return 0;
    }
    else
    {
        OutOfRange();
        return -1;
    }
}

int integerParse(char* text, int length)
{
    if(text[length - length] == '-' && val.sign == 0)
    {
        val.sign = 1;
        strcpy(val.stringValue, text);
        return 1;
    }

    if(isdigit(text[length]))
    {
        strcpy(val.stringValue, text);
        return 1;
    }
    else if(strrchr(text, ':'))
    {
        toktype = INDEX;
        return 0;
    }
    else
    {
        NotMatchValue();
        return -1;
    }
}

int charParse(char* text)
{
    int len = strlen(text) - 1;
    switch (toktype)
    {
    case OPENING_CHAR:
        if(text[len] == '\'')
        {
            toktype = CHAR;
            return 0;
        }

        NotMatchValue();
        return -1;
    case CHAR:
        if(text[len] == '\'')
        {
            toktype = KEYWORD;
            return 0;
        }
        
        val.charValue = text[len];
        return 1;
    }
}

int stringParse(char* text)
{
    int len = strlen(text) - 1;

    if(val.backslash == 1)
    {
        if(strrchr(text, '\"'))
        {
            val.backslash = 0;
            strcpy(val.stringValue, text);
        }
        else if(strrchr(text, '\''))
        {
            val.backslash = 0;
            strcpy(val.stringValue, text);
        }
        else if(strrchr(text, '\\'))
        {
            val.backslash = 0;
            strcpy(val.stringValue, text);
        }
        else if(strrchr(text, 'n'))
        {
            val.backslash = 0;
            strcpy(val.stringValue, text);
        }
        else if(strrchr(text, 't'))
        {
            val.backslash = 0;
            strcpy(val.stringValue, text);
        }
        else if(strrchr(text, 'r'))
        {
            val.backslash = 0;
            strcpy(val.stringValue, text);
        }
        else
        {
            val.backslash = 0;
            UnexpectedEscapeChar();
            return -1;
        }

        return 1;
    }

    if(text[len] == '\"' && val.backslash == 0)
    {
        toktype = KEYWORD;
        return 0;
    }
    else if(text[len] == '\\')
    {
        val.backslash = 1;
        strcpy(val.stringValue, text);
        return 1;
    }
    else if(strrchr(text, '\n'))
    {
        MissingChar();
        return -1;
    }

    strcpy(val.stringValue, text);
    return 1;
}

char* escapeChar(char* text)
{
    int count = 0;
    int i = 0;

    char* result = (char*)malloc(MAX_LENGTH_TOKS);

    while (*text) {
        if (strstr(text, "\\\"") == text) {
            strcpy(&result[i], "\"");
            i += 1;
            text += 2;
        }
        else if (strstr(text, "\\\'") == text) {
            strcpy(&result[i], "\'");
            i += 1;
            text += 2;
        }
        else if (strstr(text, "\\\\") == text) {
            strcpy(&result[i], "\\");
            i += 1;
            text += 2;
        }
        else if (strstr(text, "\\n") == text) {
            strcpy(&result[i], "\n");
            i += 1;
            text += 2;
        }
        else if (strstr(text, "\\t") == text) {
            strcpy(&result[i], "\t");
            i += 1;
            text += 2;
        }
        else if (strstr(text, "\\r") == text) {
            strcpy(&result[i], "\r");
            i += 1;
            text += 2;
        }
        else
        {
            result[i++] = *text++;
        }
    }

    result[i] = '\0';
    return result;
}