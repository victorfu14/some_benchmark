// C program to illustrate
// command line arguments
#include <stdio.h>
#include <stdlib.h>

float tofloat(char digit[]) {

    float result = 0;

    int offset = 0;
    int positive = 1;
    if (digit[0] == '-')
    {
        positive = 0;
        offset = 1;
    } else if (digit[0] == '+') offset = 1;

    int isDecimal = 0;
    float dec_mul = 0.1;

    for (int i=offset; digit[i] != '\0'; i++) 
    {
        if (digit[i] == '.') 
        {
            isDecimal = 1;
            continue;
        }
        if (isDecimal == 0)
        {
            result = result * 10 + digit[i] - '0';
        } else
        {
            result += dec_mul * (digit[i] - '0');
            dec_mul *= 0.1;
        } 
    }
    if (positive == 0) result = -result;
    return result;
}

int main(int argc,char* argv[])
{
    int i;
    float value;
    FILE *fptr;
    fptr = fopen("float_conversion_output.txt", "w");
    if(argc != 2) 
    {
        printf("\nWrong number of command line arguments");
        exit(0);
    }
    fprintf(stdout, "Program Name Is: %s\n", argv[0]);
    fprintf(fptr, "Program Name Is: %s\n", argv[0]);
    i = 0;
    while (argv[1][i] != '\0') 
    {
        fprintf(stdout, "%c\n", argv[1][i]);
        fprintf(fptr, "%c\n", argv[1][i]);
        i++;
    }
    value = tofloat(argv[1]);
    float value_alt = atof(argv[1]);
    fprintf(stdout, "Self implemented conversion: %f\n", value);
    fprintf(fptr, "Self implemented conversion: %f\n", value);
    fprintf(stdout, "C conversion: %f\n", value_alt);
    fprintf(fptr, "C conversion: %f\n", value_alt);
    exit(0);
}