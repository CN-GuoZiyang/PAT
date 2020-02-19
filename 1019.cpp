#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> res;

int main()
{
    int d, b;
    scanf("%d %d", &d, &b);
    if(d == 0)
    {
        printf("Yes\n0");
        return 0;
    }
    while(d != 0)
    {
        res.push_back(d%b);
        d /= b;
    }
    reverse(res.begin(), res.end());
    bool is = true;
    for(int i = 0, j = res.size()-1; i < j; i ++, j --)
    {
        if(res[i] != res[j])
        {
            is = false;
            break;
        }
    }
    if(is == true) printf("Yes\n");
    else printf("No\n");
    printf("%d", res[0]);
    for(int i = 1; i < res.size(); i ++)
    {
        printf(" %d", res[i]);
    }
    return 0;
}