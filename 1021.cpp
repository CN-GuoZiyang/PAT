#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool road[10001][10001];
bool visit[10001];

int n;
int height = 0;
int hh = -1;
vector<int> hnode;
bool first = true;

void dfs(int start)
{
    height ++;
    visit[start] = true;
    if(height > hh)
    {
        hh = height;
        hnode.clear();
        hnode.push_back(start);
    } else if(height == hh)
    {
        hnode.push_back(start);
    }
    for(int i = 1; i <= n; i ++)
    {
        if(road[start][i] == true && visit[i] == false)
        {
            dfs(i);
        }
    }
    height --;
    if(first == false) visit[start] = false;
    return;
}

bool cmp(int a, int b)
{
    return a < b;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n-1; i ++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        road[a][b] = true;
        road[b][a] = true;
    }
    int con = 0;
    for(int i = 1; i <= n; i ++)
    {
        if(visit[i] == false)
        {
            dfs(i);
            con ++;
        }
    }
    if(con > 1)
    {
        printf("Error: %d components", con);
        return 0;
    }
    first = false;
    hh = -1;
    fill(visit, visit+10001, false);
    vector<int> tmp(hnode);
    dfs(hnode[0]);
    for(int i = 0; i < tmp.size(); i ++) hnode.push_back(tmp[i]);
    sort(hnode.begin(), hnode.end(), cmp);
    printf("%d\n", hnode[0]);
    for(int i = 1; i < hnode.size(); i ++)
    {
        if(hnode[i] == hnode[i-1]) continue;
        printf("%d\n", hnode[i]);
    }
    return 0;
}