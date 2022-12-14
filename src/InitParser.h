#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ErrorChoco.h"
#define MAX_LENGTH_TOKS 1000
#define TAPE_SIZE 255

#define _MAX_INT32_ (2147483647L)
#define _MAX_INT32_SIGNED_ (-2147483647L)

#define _MAX_INT64_ (9223372036854775807LL)
#define _MAX_INT64_SIGNED_ (-9223372036854775807LL)

#define _MAX_INT16_ (32767)
#define _MAX_INT16_SIGNED_ (-32767)

enum TokenType
{
    KEYWORD = 1,
    IDENTIFIER = 2,
    DATATYPE = 3,
    INDEX = 4,

    STRING = 5,
    INTEGER = 6,
    FLOAT = 7,
    CHAR = 8,
    OPENING_CHAR = 9,
    OPENING_STRING = 10,
    DOUBLE = 11,
    POINTER = 12,

    LOGICAL = 13,

    EMPTY_END = 99,
    NOTHING = 999
};

enum TokenType toktype = EMPTY_END;
enum TokenType in = EMPTY_END;

struct Values
{
    char stringValue[MAX_LENGTH_TOKS];
    char charValue;

    int i;
    int pointer;
    int pointerProgress;
    char iChr[MAX_LENGTH_TOKS];
    char datatype[MAX_LENGTH_TOKS];
    int backslash;
    int sign;
    int point;
};

struct Booleans
{
    char operand_dt[2][MAX_LENGTH_TOKS];
    int operand_i[2];

    int first;
    int second;

    int equalTo[TAPE_SIZE];
    int greaterThan[TAPE_SIZE];
    int lessThan[TAPE_SIZE];
    
    int arg;
    int i;
};

struct Booleans bools;

struct Values val;

struct Tape
{
    char stringArr[TAPE_SIZE][MAX_LENGTH_TOKS];
    char charArr[TAPE_SIZE];
    short int16Arr[TAPE_SIZE];
    long int int32Arr[TAPE_SIZE];
    long long int int64Arr[TAPE_SIZE];
    float floatArr[TAPE_SIZE];
    double doubleArr[TAPE_SIZE];
};

struct Tape tape;