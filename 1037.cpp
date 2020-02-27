#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int na, nb;
    scanf("%d", &na);
    vector<int> a(na);
    for(int i = 0; i < na; i ++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &nb);
    vector<int> b(nb);
    for(int i = 0; i < nb; i ++)
    {
        scanf("%d", &b[i]);
    }
    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end(), cmp);
    int ai, bi;
    int total=0;
    for(ai=0,bi=0; ai<na,bi<nb; ai++,bi++)
    {
        if(a[ai] > 0 && b[bi] > 0)
        {
            total += a[ai]*b[bi];
        } else {
            break;
        }
    }
    for(ai=na-1,bi=nb-1; ai>-1,bi>-1; ai--,bi--)
    {
        if(a[ai] < 0 && b[bi] < 0)
        {
            total += a[ai]*b[bi];
        } else {
            break;
        }
    }
    printf("%d", total);
    return 0;
}