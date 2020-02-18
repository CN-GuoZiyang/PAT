#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int reverseWithR(int s, int r)
{
    int res = 0, arr[100];
    int i = 0;
    while(s != 0)
    {
        arr[i] = s % r;
        s /= r;
        i ++;
    }
    for(int j = 0; j < i; j ++)
    {
        res = res * r + arr[j];
    }
    return res;
}

bool isPrime(int a)
{
    if(a < 2) return false;
    int mid = int(sqrt(a*1.0));
    for(int i = 2; i <= mid; i ++)
    {
        if(a % i == 0) return false;
    }
    return true;
}

int main()
{
    while(true)
    {
        int b, radix;
        scanf("%d", &b);
        if(b < 0) break;
        scanf("%d", &radix);
        if(isPrime(b) == false)
        {
            printf("No\n");
            continue;
        }
        int c = reverseWithR(b, radix);
        if(isPrime(c) == false)
        {
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    }
    return 0;
}