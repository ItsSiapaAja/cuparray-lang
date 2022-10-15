/***********************************
 * 
 * CUP ARRAY
 * 
 * Created by ItsSiapaAja
 * Version 202206 (CUR-BETA-06)
 * 
 ***********************************/

#include "src\Read.h"

void help()
{
    printf("CUP ARRAY HELP SECTION\n");
    printf("\t[-r][file name] : Running a file\n");
    printf("\t[-v] : The interpreter version\n");
    printf("\t[-h] : Showing help\n");
}

int main(int argc, char** argv)
{
    if(argc == 3 && strncmp(argv[1], "-r", 2) == 0)
    {
        readFile(argv[2]);
    }
    else if(argc == 2 && strncmp(argv[1], "-v", 2) == 0)
    {
        printf("CUP ARRAY Beta Version : %d", CUP_LANG);
    }
    else if(argc == 3 && strncmp(argv[1], "-h", 2) == 0)
    {
        help();
    }
    else
    {
        help();
    }
    return 0;
}