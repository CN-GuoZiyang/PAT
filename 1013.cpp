#include <cstdio>
#include <algorithm>
using namespace std;

int juzhen[1001][1001];
bool visit[1001];

int n, m, k;

void dfs(int node);

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < m; i ++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        juzhen[a][b] = 1;
        juzhen[b][a] = 1;
    }
    for(int i = 0; i < k; i ++)
    {
        int a;
        fill(visit, visit + 1001, false);
        scanf("%d", &a);
        visit[a] = true;
        int time = 0;
        for(int j = 1; j <= n; j ++)
        {
            if(visit[j] == false)
            {
                dfs(j);
                time ++;
            }
        }
        printf("%d\n", time - 1);
    }
    return 0;
}

void dfs(int node)
{
    visit[node] = true;
    for(int i = 1; i <= n; i ++)
    {
        if(visit[i] == false && juzhen[node][i] == 1)
        {
            dfs(i);
        }
    }
}