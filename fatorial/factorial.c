#include<stdio.h>
#include<stdlib.h>

/**
 * i know is pretty overkill, i just wanted to look for C limit.
 * Factorial function to calculate the factorial of natural numbers (positive integers).
 * To factorial of real numbers (extend natural to negative and with decimal places) is needed to look for the Gamma Function.
 */
unsigned long long int factorial(unsigned long long int number)
{
    unsigned long long int index = number;
    unsigned long long int fat = 1;

    if (number > 1)
    {
        while(index > 0)
        {
            fat *= index;
            index -= 1;
        }
    }

    return fat;
}

int main(int argc, char **argv)
{
    if (argc < 2) printf("%s.\n", "Please insert a number to calculate the factorial!");

    unsigned long long int number = atoi(argv[1]);

    printf("The factorial of %llu is %llu.\n", number, factorial(number));

    return 0;
}