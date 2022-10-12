#include "InitParser.h"

char* escapeChar(char* text);

int newMnemonic()
{
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
    else if(strcmp(val.datatype, "float") == 0)
    {
        float temp = atof(val.stringValue);
        tape.floatArr[val.i] = temp;
    }
}

int addMnemonic()
{
    if(strcmp(val.datatype, "int32") == 0)
    {
        long int temp = atoi(val.stringValue);

        if(temp >= _MAX_INT32_ || temp <= _MAX_INT32_SIGNED_)
        {
            OutOfSize();
            return -1;
        }

        tape.int32Arr[val.i] += temp;

        if(tape.int32Arr[val.i] >= _MAX_INT32_ || tape.int32Arr[val.i] <= _MAX_INT32_SIGNED_)
        {
            OutOfSize();
            return -1;
        }
    }
    else if(strcmp(val.datatype, "int64") == 0)
    {
        long long int temp = atoi(val.stringValue);

        if(temp >= _MAX_INT64_ || temp <= _MAX_INT64_SIGNED_)
        {
            OutOfSize();
            return -1;
        }

        tape.int64Arr[val.i] += temp;

        if(tape.int64Arr[val.i] >= _MAX_INT64_ || tape.int64Arr[val.i] <= _MAX_INT64_SIGNED_)
        {
            OutOfSize();
            return -1;
        }
    }
    else if(strcmp(val.datatype, "int16") == 0)
    {
        short temp = atoi(val.stringValue);

        if(temp >= _MAX_INT16_ || temp <= _MAX_INT16_SIGNED_)
        {
            OutOfSize();
            return -1;
        }

        tape.int16Arr[val.i] += temp;

        if(tape.int16Arr[val.i] >= _MAX_INT16_ || tape.int16Arr[val.i] <= _MAX_INT16_SIGNED_)
        {
            OutOfSize();
            return -1;
        }
    }
    else if(strcmp(val.datatype, "char") == 0)
    {
        NotMatchValue();
        return -1;
    }
    else if(strcmp(val.datatype, "string") == 0)
    {
        strcpy(val.stringValue, escapeChar(val.stringValue));
        strcat(tape.stringArr[val.i], val.stringValue);
    }
    else if(strcmp(val.datatype, "float") == 0)
    {
        float temp = atof(val.stringValue);
        tape.floatArr[val.i] += temp;
    }
}

int subMnemonic()
{
    if(strcmp(val.datatype, "int32") == 0)
    {
        long int temp = atoi(val.stringValue);

        if(temp >= _MAX_INT32_ || temp <= _MAX_INT32_SIGNED_)
        {
            OutOfSize();
            return -1;
        }

        tape.int32Arr[val.i] -= temp;

        if(tape.int32Arr[val.i] >= _MAX_INT32_ || tape.int32Arr[val.i] <= _MAX_INT32_SIGNED_)
        {
            OutOfSize();
            return -1;
        }
    }
    else if(strcmp(val.datatype, "int64") == 0)
    {
        long long int temp = atoi(val.stringValue);

        if(temp >= _MAX_INT64_ || temp <= _MAX_INT64_SIGNED_)
        {
            OutOfSize();
            return -1;
        }

        tape.int64Arr[val.i] -= temp;

        if(tape.int64Arr[val.i] >= _MAX_INT64_ || tape.int64Arr[val.i] <= _MAX_INT64_SIGNED_)
        {
            OutOfSize();
            return -1;
        }
    }
    else if(strcmp(val.datatype, "int16") == 0)
    {
        short temp = atoi(val.stringValue);

        if(temp >= _MAX_INT16_ || temp <= _MAX_INT16_SIGNED_)
        {
            OutOfSize();
            return -1;
        }

        tape.int16Arr[val.i] -= temp;

        if(tape.int16Arr[val.i] >= _MAX_INT16_ || tape.int16Arr[val.i] <= _MAX_INT16_SIGNED_)
        {
            OutOfSize();
            return -1;
        }
    }
    else if(strcmp(val.datatype, "char") == 0)
    {
        NotMatchValue();
        return -1;
    }
    else if(strcmp(val.datatype, "string") == 0)
    {
        NotMatchValue();
        return -1;
    }
    else if(strcmp(val.datatype, "float") == 0)
    {
        float temp = atof(val.stringValue);
        tape.floatArr[val.i] -= temp;
    }
}