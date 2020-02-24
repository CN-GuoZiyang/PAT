#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int dis[500][500], cost[500][500], n, m, s, d;
bool visit[500];

vector<int> froad;
vector<int> troad;

int fdis=INT_MAX, tdis=0, fcost=INT_MAX, tcost=0;

void dfs(int start)
{
    visit[start] = true;
    // printf("visit %d\n", start);
    troad.push_back(start);
    if(start == d)
    {
        if(tdis < fdis)
        {
            fdis = tdis;
            fcost = tcost;
            froad.clear();
            froad.assign(troad.begin(), troad.end());
        } else if(tdis == fdis && tcost < fcost)
        {
            fcost = tcost;
            froad.clear();
            froad.assign(troad.begin(), troad.end());
        }
        visit[start] = false;
        troad.pop_back();
        return;
    }
    for(int i = 0; i < n; i ++)
    {
        if(dis[start][i] != 0 && visit[i] == false)
        {
            tdis += dis[start][i];
            if(tdis > fdis)
            {
                tdis -= dis[start][i];
                continue;
            }
            tcost += cost[start][i];
            dfs(i);
            tcost -= cost[start][i];
            tdis -= dis[start][i];
        }
    }
    visit[start] = false;
    troad.pop_back();
    return;
}

int main()
{
    scanf("%d %d %d %d", &n, &m, &s, &d);
    for(int i = 0; i < m; i ++)
    {
        int a, b, t, c;
        scanf("%d %d %d %d", &a, &b, &t, &c);
        dis[a][b] = t;
        dis[b][a] = t;
        cost[a][b] = c;
        cost[b][a] = c;
    }
    dfs(s);
    for(int i = 0; i < froad.size(); i ++)
    {
        printf("%d ", froad[i]);
    }
    printf("%d %d", fdis, fcost);
    return 0;
}