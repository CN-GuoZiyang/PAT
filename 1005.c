/**
 * 1005 Spell It Right
 * 
 * Given a non-negative integer N, 
 * your task is to compute the sum of all the digits of N, 
 * and output every digit of the sum in English.
 * 
 * Input Specification:
 * Each input file contains one test case. Each case occupies one line which contains an N (≤10​^100).
 * 
 * Output Specification:
 * For each test case, output in one line the digits of the sum in English words. 
 * There must be one space between two consecutive words, but no extra space at the end of a line.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    char N[101];
    scanf("%s", N);
    int sum = 0;
    int i;
    for(i = 0;;i++)
    {
        if(N[i] == '\0') break;
        sum += N[i] - '0';
    }
    char res[101];
    sprintf(res, "%d", sum);
    int start = 1;
    for(i = 0;;i++)
    {
        if(res[i] == '\0') break;
        if(start == 1)
        {
            switch(res[i])
            {
                case '0':
                printf("zero");
                break;
                case '1':
                printf("one");
                break;
                case '2':
                printf("two");
                break;
                case '3':
                printf("three");
                break;
                case '4':
                printf("four");
                break;
                case '5':
                printf("five");
                break;
                case '6':
                printf("six");
                break;
                case '7':
                printf("seven");
                break;
                case '8':
                printf("eight");
                break;
                case '9':
                printf("nine");
                break;
            }
            start = 0;
        } else
        {
            switch(res[i])
            {
                case '0':
                printf(" zero");
                break;
                case '1':
                printf(" one");
                break;
                case '2':
                printf(" two");
                break;
                case '3':
                printf(" three");
                break;
                case '4':
                printf(" four");
                break;
                case '5':
                printf(" five");
                break;
                case '6':
                printf(" six");
                break;
                case '7':
                printf(" seven");
                break;
                case '8':
                printf(" eight");
                break;
                case '9':
                printf(" nine");
                break;
            }
        }
    }
    printf("\n");
    return 0;
}