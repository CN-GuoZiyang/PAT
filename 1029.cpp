#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int an, bn;
    scanf("%d", &an);
    vector<long> a(an);
    for(int i = 0; i < an; i ++)
    {
        scanf("%ld", &a[i]);
    }
    scanf("%d", &bn);
    int midIndex = (an+bn+1)/2;
    int ai = 0;
    int ci = 0;
    for(int i = 0; i < bn; i ++)
    {
        long tmpd;
        scanf("%ld", &tmpd);
        if(ai < an && a[ai] < tmpd)
        {
            while(a[ai] < tmpd)
            {
                ci ++;
                if(ci == midIndex)
                {  
                    printf("%ld", a[ai]);
                    return 0;
                }
                ai ++;
            }
        }
        ci ++;
        if(ci == midIndex)
        {
            printf("%ld", tmpd);
            return 0;
        }
    }
    for(;ai < an; ai ++)
    {
        ci++;
        if(ci == midIndex)
        {
            printf("%ld", a[ai]);
            return 0;
        }
    }
}