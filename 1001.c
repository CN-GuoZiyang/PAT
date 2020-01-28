/**
 * 1001 A+B Format
 * 
 * Calculate a+b and output the sum in standard format 
 * -- that is, the digits must be separated into groups of three by commas 
 * (unless there are less than four digits).
 * 
 * Input Specification:
 * Each input file contains one test case. 
 * Each case contains a pair of integers a and b where −10^​6​≤a,b≤10^6.
 * The numbers are separated by a space.
 * 
 * Output Specification:
 * For each test case, you should output the sum of a and b in one line. 
 * The sum must be written in the standard format.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a, b, res;
    char resStr[32];
    if(scanf("%d%d", &a, &b) <= 0)
    {
        printf("error!");
        return 1;
    }
    res = a + b;
    if(res < 0) 
    {
        printf("-");
        res = -res;
    }
    sprintf(resStr, "%d", res);
    int n = strlen(resStr);
    int m = n % 3;
    int i = 0;
    for(i = 0; i < m; i ++) {
        printf("%c", resStr[i]);
    }
    for(; i < n; i += 3)
    {
        if(i != 0)
        {
            printf(",");
        }
        printf("%c%c%c", resStr[i], resStr[i+1], resStr[i+2]);
    }
    printf("\n");
    return 0;
}