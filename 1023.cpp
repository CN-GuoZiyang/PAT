#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
    char tmp;
    map<int, int> countb;
    for(int i = 0; i < 10; i ++)
    {
        countb[i] = 0;
    }
    vector<int> b;
    while(true)
    {
        tmp = getchar();
        if('0' <= tmp && tmp <= '9')
        {
            b.push_back(tmp - '0');
            countb[tmp-'0'] ++;
        } else {
            break;
        }
    }
    int jinwei = 0;
    bool Yes = true;
    for(int i = b.size()-1; i >= 0; i --)
    {
        int tmp = b[i] * 2 + jinwei;
        if(tmp >= 10)
        {
            b[i] = tmp % 10;
            jinwei = 1;
        } else {
            b[i] = tmp;
            jinwei = 0;
        }
        countb[b[i]] --;
        if(countb[b[i]] < 0) Yes = false;
    }
    if(jinwei != 0)
    {
        countb[1] --;
        if(countb[1] < 0) Yes = false;
    }
    for(int i = 0; i < 10; i ++)
    {
        if(countb[i] != 0) Yes = false;
    }
    if(Yes == false) printf("No\n");
    else printf("Yes\n");
    if(jinwei != 0) printf("%d", jinwei);
    for(int i = 0; i < b.size(); i ++)
    {
        printf("%d", b[i]);
    }
    return 0;
}