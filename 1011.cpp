#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    double res[3];
    int wtl[3];
    char duiying[] = {'W', 'T', 'L'};
    for(int i = 0; i < 3; i ++)
    {
        double a[3];
        for(int j = 0; j < 3; j ++) scanf("%lf", &a[j]);
        res[i] = *max_element(a, a+3);
        if(res[i] == a[0]) wtl[i] = 0;
        else if(res[i] == a[1]) wtl[i] = 1;
        else wtl[i] = 2;
    }
    for(int i = 0; i < 3; i ++)
    {
        printf("%c ", duiying[wtl[i]]);
    }
    printf("%.2f", (res[0] * res[1] * res[2] * 0.65 - 1) * 2);
    return 0;
}