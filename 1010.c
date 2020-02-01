/**
 * 1010 Radix
 * 
 * Given a pair of positive integers, for example, 6 and 110, can this equation 6 = 110 be true? 
 * The answer is yes, if 6 is a decimal number and 110 is a binary number.
 * Now for any pair of positive integers N1 and N2, 
 * your task is to find the radix of one number while that of the other is given.
 * 
 * Input Specification:
 * Each input file contains one test case. Each case occupies a line which contains 4 positive integers:
 * N1 N2 tag radix
 * Here N1 and N2 each has no more than 10 digits. 
 * A digit is less than its radix and is chosen from the set { 0-9, a-z } where 0-9 represent the decimal numbers 0-9, 
 * and a-z represent the decimal numbers 10-35. The last number radix is the radix of N1 if tag is 1, 
 * or of N2 if tag is 2.
 * 
 * Output Specification:
 * For each test case, prlong long in one line the radix of the other number so that the equation N1 = N2 is true. 
 * If the equation is impossible, prlong long Impossible. If the solution is not unique, output the smallest possible radix.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>

long long compute(char *chars, long long radix)
{
    long long len = strlen(chars);
    long long i;
    long long res = 0;
    long long quan = 0;
    for(i = len - 1; i >= 0; i --)
    {
        long long tmp;
        if('0' <= chars[i] && chars[i] <= '9')
        {
            tmp = (long long)chars[i] - '0';
        } else {
            tmp = (long long)chars[i] - 'a' + 10;
        }
        res += (long long)pow(radix, quan) * tmp;
        if(res < 0)
        {
            return INT_MAX;
        }
        quan ++;
    }
    return res;
}

int main()
{
    char N1char[11];
    char N2char[11];
    long long N1 = 0;
    long long tag;
    long long N1Radix;
    scanf("%s %s %lld %lld", N1char, N2char, &tag, &N1Radix);
    if(strcmp(N1char, "0") == 0 && strcmp(N2char, "0") == 0)
    {
        printf("1\n");
        return 0;
    }
    if(tag == 2)
    {
        char tmp[11];
        strcpy(tmp, N1char);
        strcpy(N1char, N2char);
        strcpy(N2char, tmp);
    }
    N1 = compute(N1char, N1Radix);
    long long i, left = 0;
    long long N2len = strlen(N2char);
    long long right = 0;
    for(i = 0; i < N2len; i ++)
    {
        long long tmp;
        if('0' <= N2char[i] && N2char[i] <= '9')
        {
            tmp = N2char[i] - '0';
        } else {
            tmp = N2char[i] - 'a' + 10;
        }
        if(tmp > right)
        {
            left = tmp;
        }
    }
    if(N1 < left)
    {
        printf("Impossible\n");
        return 0;
    }
    left ++;
    if(N1 > left)
    {
        right = N1 + 1;
    } else {
        right = left;
    }
    long long mid;
    long long tmp;
    while(left <= right)
    {
        mid = (left + right) / 2;
        tmp = compute(N2char, mid);
        if(tmp > N1)
        {
            right = mid - 1;
        } else if(tmp < N1)
        {
            left = mid + 1;
        } else if(tmp == N1)
        {
            printf("%lld\n", mid);
            return 0;
        }
    }
    printf("Impossible\n");
    return 0;
}