/**
 * 1009 Product of Polynomials
 * 
 * This time, you are supposed to find A×B where A and B are two polynomials.
 * 
 * Input Specification:
 * Each input file contains one test case. Each case occupies 2 lines, 
 * and each line contains the information of a polynomial:
 * K N1 aN1 N2 aN2 ... Nk aNk
 * where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1,2,⋯,K) are the exponents and coefficients, respectively. 
 * It is given that 1≤K≤10, 0≤NK <⋯< N2 < N1 ≤1000.
 * 
 * Output Specification:
 * For each test case you should output the product of A and B in one line, with the same format as the input. 
 * Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i, j, k, num_a, num_b;
    scanf("%d", &num_a);
    int zhishu_a[num_a];
    double xishu_a[num_a];
    for(i = 0; i < num_a; i ++)
    {
        scanf("%d %lf", &zhishu_a[i], &xishu_a[i]);
    }
    scanf("%d", &num_b);
    int zhishu_b;
    double xishu_b;
    int zhishu_new;
    double xishu_new;
    int zhishu_res[num_a * num_b + 1];
    double xishu_res[num_a * num_b + 1];
    int index_can_use = 0;
    for(i = 0; i < num_b; i ++)
    {
        scanf("%d %lf", &zhishu_b, &xishu_b);
        if(xishu_b == 0) continue;
        for(j = 0; j < num_a; j ++)
        {
            zhishu_new = zhishu_b + zhishu_a[j];
            xishu_new = xishu_b * xishu_a[j];
            int found = 0;
            for(k = 0; k < index_can_use; k ++)
            {
                if(zhishu_res[k] == zhishu_new)
                {
                    xishu_res[k] += xishu_new;
                    found = 1;
                    break;
                } else if(zhishu_res[k] < zhishu_new)
                {
                    break;
                }
            }
            if(found == 0)
            {
                zhishu_res[index_can_use] = zhishu_new;
                xishu_res[index_can_use] = xishu_new;
                index_can_use ++;
            }
        }
    }
    int num_res = 0;
    for(i = 0; i < index_can_use; i ++)
    {
        if(fabs(xishu_res[i]) > 1e-15) num_res ++;
    }
    for(i = 0; i < index_can_use - 1; i ++)
    {
        for(j = 0; j < index_can_use - 1 - i; j ++)
        {
            if(zhishu_res[j] < zhishu_res[j + 1])
            {
                int tmp_int;
                float tmp_float;
                tmp_int = zhishu_res[j];
                zhishu_res[j] = zhishu_res[j + 1];
                zhishu_res[j + 1] = tmp_int;
                tmp_float = xishu_res[j];
                xishu_res[j] = xishu_res[j + 1];
                xishu_res[j + 1] = tmp_float;
            }
        }
    }
    printf("%d", num_res);
    for(i = 0; i < index_can_use; i ++)
    {
        if(fabs(xishu_res[i]) > 1e-15) printf(" %d %.1lf", zhishu_res[i], xishu_res[i]);
    }
    printf("\n");
    return 0;
}