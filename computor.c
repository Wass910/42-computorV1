#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1000

void    exit_function(char *message)
{
    printf("%s\n", message);
    exit(1);
}

void    analyze_polynomial_form(char *expression)
{
    int i = 0;

    while (expression[i] != '\0'){
        if (expression[i] != ' ' && expression[i] != 'X' && expression[i] != '^' && expression[i] != '+' && expression[i] != '-' && expression[i] != '=' && (expression[i] < '0' || expression[i] > '9')){
            exit_function("Error: invalid polynomial form");
        }
        if (expression[i] == 'X'){
            if (expression[i + 1] == '^'){
            }
            else
                exit_function("Error: invalid polynomial form");
        }
        i++;
    }
    return ;
}

int     main(int argc, char **argv)
{
    if (argc != 2){
        printf("Bad number of arguments\n");
        return 1;
    }
    analyze_polynomial_form(argv[1]);
    return 0;
}