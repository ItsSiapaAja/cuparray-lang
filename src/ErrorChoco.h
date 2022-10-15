#include <stdio.h>
#include <stdlib.h>

char errorMessage[255];

void MissingChar()
{
    strcpy(errorMessage, "Cup_Interpreter : Missing character (between ';' or '\"')");
    printf("%s\n", errorMessage);
}

void UnknownArgument()
{
    strcpy(errorMessage, "Cup_Interpreter : Losing argument");
    printf("%s\n", errorMessage);
}

void UnexpectedIdentifier()
{
    strcpy(errorMessage, "Cup_Interpreter : Unexpected identifier");
    printf("%s\n", errorMessage);
}

void UnexpectedEscapeChar()
{
    strcpy(errorMessage, "Cup_Interpreter : Unexpected escape char in string");
    printf("%s\n", errorMessage);
}

void UnexpectedKeyword()
{
    strcpy(errorMessage, "Cup_Interpreter : Unexpected keyword");
    printf("%s\n", errorMessage);
}

void UnexpectedDatatype()
{
    strcpy(errorMessage, "Cup_Interpreter : Unexpected datatype");
    printf("%s\n", errorMessage);
}

void NotMatchValue()
{
    strcpy(errorMessage, "Cup_Interpreter : Not matching value with datatype");
    printf("%s\n", errorMessage);
}

void OutOfRange()
{
    strcpy(errorMessage, "Cup_Interpreter : Out of range index");
    printf("%s\n", errorMessage);
}

void OutOfSize()
{
    strcpy(errorMessage, "Cup_Interpreter : Out of size array element");
    printf("%s\n", errorMessage);
}

void WrongInput()
{
    strcpy(errorMessage, "Cup_Interpreter : Wrong input");
    printf("%s\n", errorMessage);
}

void NotMatchingOperand()
{
    strcpy(errorMessage, "Cup_Interpreter : Not matching operands");
    printf("%s\n", errorMessage);
}