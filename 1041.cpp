#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int a[10001];
    fill(a, a+10001, -1);
    vector<int> b;
    for(int i = 0; i < n; i ++)
    {
        int tmp;
        scanf("%d", &tmp);
        if(a[tmp] == -1)
        {
            b.push_back(tmp);
            a[tmp] = 0;
        }
        a[tmp] ++;
    }
    for(int i = 0; i < n; i ++)
    {
        if(a[b[i]] == 1)
        {
            printf("%d", b[i]);
            return 0;
        }
    }
    printf("None");
    return 0;
}