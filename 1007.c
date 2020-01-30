/**
 * 1007 Maximum Subsequence Sum
 * 
 * Given a sequence of K integers {N1, N2, ..., NK}. 
 * A continuous subsequence is defined to be {Ni, Ni+1, ..., Nj} where 1≤i≤j≤K. 
 * The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. 
 * For example, given sequence { -2, 11, -4, 13, -5, -2 }, 
 * its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.
 * 
 * Input Specification:
 * Each input file contains one test case. Each case occupies two lines. 
 * The first line contains a positive integer K (≤10000). The second line contains K numbers, separated by a space.
 * 
 * Output Specification:
 * For each test case, output in one line the largest sum, 
 * together with the first and the last numbers of the maximum subsequence. 
 * The numbers must be separated by one space, but there must be no extra space at the end of a line. 
 * In case that the maximum subsequence is not unique, output the one with the smallest indices i and j 
 * (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, 
 * and you are supposed to output the first and the last numbers of the whole sequence.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, K;
    scanf("%d", &K);
    int num[K];
    int allNotPos = 1;
    int withZero = 0;
    for(i = 0; i < K; i ++)
    {
        scanf("%d", &num[i]);
        if(num[i] > 0) allNotPos = 0;
        if(num[i] == 0) withZero = 1;
    }
    if(allNotPos == 1)
    {
        if(withZero == 0) printf("0 %d %d\n", num[0], num[K-1]);
        else printf("0 0 0\n");
        return 0;
    }
    int currentLeft = 0;
    int currentRight = 0;
    int currentSum = 0;
    int resLeft = 0;
    int resRight = 0;
    int resSum = -1;
    while(1)
    {
        if(currentRight == K) break;
        currentSum += num[currentRight];
        if(currentSum < 0)
        {
            currentSum = 0;
            currentLeft = currentRight + 1;
            if(currentRight == K) break;
        } else if(currentSum > resSum)
        {
            resSum = currentSum;
            resLeft = currentLeft;
            resRight = currentRight;
        }
        currentRight ++;
    }
    printf("%d %d %d\n", resSum, num[resLeft], num[resRight]);
    return 0;
}