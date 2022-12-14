#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Parser.h"
#define MAX_LENGTH 255
#define CUP_LANG 202207L

char keywordBuffer[MAX_LENGTH];

/*******************************
 * 
 * Interpreter Function
 * 
 * return 0 = clearChar
 * return 1 = keepChar
 * return -1 = error
 * 
*******************************/

void clearTape()
{
    memset(tape.charArr, 0, TAPE_SIZE);
    memset(tape.int16Arr, 0, TAPE_SIZE);
    memset(tape.int32Arr, 0, TAPE_SIZE);
    memset(tape.int64Arr, 0, TAPE_SIZE);
    memset(tape.stringArr, 0, TAPE_SIZE);
    memset(tape.stringArr, 0, TAPE_SIZE);
    val.backslash = 0;
    val.charValue = '\0';
    strcpy(val.datatype, "");
    val.i = 0;
    strcpy(val.iChr, "");
    val.sign = 0;
    strcpy(val.stringValue, "");
    bools.arg = 0;
    bools.first = 0;
    memset(bools.operand_dt, 0, 2);
    memset(bools.operand_i, 0, 2);
    bools.second = 0;
}

int interpreter(char* textBuffer)
{
    if(toktype == EMPTY_END || toktype == NOTHING)
    {
        if(strncmp(textBuffer, "echo", 4) == 0 || 
        strncmp(textBuffer, "NEW", 3) == 0 || 
        strncmp(textBuffer, "ADD", 3) == 0 || 
        strncmp(textBuffer, "SUB", 3) == 0 || 
        strncmp(textBuffer, "MUL", 3) == 0 || 
        strncmp(textBuffer, "DIV", 3) == 0 || 
        strncmp(textBuffer, "arr_dump", 8) == 0 || 
        strncmp(textBuffer, "arr_get", 7) == 0)
        {
            toktype = KEYWORD;
            in = KEYWORD;
            strcpy(keywordBuffer, textBuffer);
            return 0;
        }
        else if(strncmp(textBuffer, "EQ", 2) == 0 || 
        strncmp(textBuffer, "GT", 2) == 0 || 
        strncmp(textBuffer, "LT", 2) == 0)
        {
            toktype = LOGICAL;
            in = LOGICAL;
            strcpy(keywordBuffer, textBuffer);
            return 0;
        }
        else if(strncmp(textBuffer, "\n", 1) == 0 || strncmp(textBuffer, " ", 1) == 0)
        {
            return 0;
        }
        else
        {
            toktype = NOTHING;
            return 1;
        }
    }
    else if(toktype == KEYWORD || in == KEYWORD)
    {
        return keywordParse(textBuffer, keywordBuffer);
    }
    else if(toktype == LOGICAL || in == LOGICAL)
    {
        return logicalParse(textBuffer, keywordBuffer);
    }

    toktype = EMPTY_END;
    strcpy(keywordBuffer, "");
    return 1;
}