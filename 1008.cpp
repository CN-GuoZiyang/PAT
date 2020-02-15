#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int c = 0;
    int res = 0;
    for(int i = 0; i < n; i ++)
    {
        int tmp;
        scanf("%d", &tmp);
        if(tmp == c) res += 5;
        else if(tmp > c)
        {
            res += ((tmp - c) * 6 + 5);
            c = tmp;
        } else
        {
            res += ((c - tmp) * 4 + 5);
            c = tmp;
        }
    }
    printf("%d", res);
    return 0;
}