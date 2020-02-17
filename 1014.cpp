#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, k, q;
int serviceTime[1001];
int res[1001], START_TIME=8*60, END_TIME=17*60;

struct window
{
    int firstEnd=8*60, lastEnd=8*60;
    queue<int> customs;
};

int main()
{
    scanf("%d %d %d %d", &n, &m, &k, &q);
    for(int i = 1; i <= k; i ++)
    {
        scanf("%d", &serviceTime[i]);
    }
    bool sorry[k+1];
    fill(sorry, sorry+k+1, false);
    int index = 1; // 当前服务到的序号
    vector<window> windows(n);
    for(int i = 0; i < m; i ++)
    {
        for(int j = 0; j < n; j ++) // window号
        {
            if(index <= k)
            {
                windows[j].customs.push(index);
                if(windows[j].lastEnd >= END_TIME) sorry[index] = true;
                windows[j].lastEnd += serviceTime[index];
                res[index] = windows[j].lastEnd;
                if(i == 0) windows[j].firstEnd = windows[j].lastEnd;
                index ++;
            }
        }
    }
    while(index <= k)
    {
        // 寻找结束时间最短的window
        int min = 0, minT = windows[0].firstEnd;
        for(int i = 1; i < n; i ++)
        {
            if(windows[i].firstEnd < minT)
            {
                min = i;
                minT = windows[i].firstEnd;
            }
        }
        windows[min].customs.pop();
        windows[min].firstEnd += (serviceTime[windows[min].customs.front()]);
        windows[min].customs.push(index);
        if(windows[min].lastEnd >= END_TIME) sorry[index] = true;
        windows[min].lastEnd += serviceTime[index];
        res[index] = windows[min].lastEnd;
        index ++;
    }
    for(int i = 0; i < q; i ++)
    {
        int tmp;
        scanf("%d", &tmp);
        if(sorry[tmp] == true) printf("Sorry\n");
        else printf("%02d:%02d\n", res[tmp]/60, res[tmp]%60);
    }
    return 0;
}