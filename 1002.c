/**
 * 1002 A+B for Polynomials
 * 
 * This time, you are supposed to find A+B where A and B are two polynomials.
 * 
 * Input Specification:
 * Each input file contains one test case. 
 * Each case occupies 2 lines, and each line contains the information of a polynomial:
 * K N_​1aN​1 N_​2a​N2 ... N_KaNK
 * where K is the number of nonzero terms in the polynomial, 
 * Ni and a​N​i (i=1,2,⋯,K) are the exponents and coefficients, respectively. 
 * It is given that 1≤K≤10，0≤NK<⋯<N2<N1≤1000. 
 * 
 * Output Specification:
 * For each test case you should output the sum of A and B in one line, with the same format as the input. 
 * Notice that there must be NO extra space at the end of each line. 
 * Please be accurate to 1 decimal place.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int xiangmushu = 0;
    float canshu[1001] = {0.0};
    float jishu;
    int zhishu;
    int i, k;
    int N;
    for(i = 0; i < 2; i ++)
    {
        scanf("%d", &N);
        for(k = 0; k < N; k ++)
        {
            scanf(" %d", &zhishu);
            scanf(" %f", &jishu);
            canshu[zhishu] += jishu;
        }
    }
    for(i = 0; i <= 1000; i ++)
    {
        if(fabs(canshu[i]) >= 0.05)
        {
            xiangmushu ++;
        }
    }
    printf("%d", xiangmushu);
    for(i = 1000; i >= 0; i --)
    {
        if(fabs(canshu[i]) >= 0.05)
        {
            printf(" %d %.1f", i, canshu[i]);
        }
    }
    printf("\n");
    return 0;
}