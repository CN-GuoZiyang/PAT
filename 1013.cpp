#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, k, c;
int roads[1001][1001];

bool visited[1001];

void dfs(int start)
{
    visited[start] = true;
    for(int i = 1; i <= n; i ++)
    {
        if(visited[i] == false && roads[start][i] == 1 && i != c) dfs(i);
    }
    return;
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < m; i ++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        roads[a][b] = 1;
        roads[b][a] = 1;
    }
    int checked[k];
    for(int i = 0; i < k; i ++)
    {
        scanf("%d", &checked[i]);
    }
    for(int i = 0; i < k; i ++)
    {
        c = checked[i];
        fill(visited, visited+1001, false);
        int part = 0;
        for(int j = 1; j <= n; j ++)
        {
            if(visited[j] != true && j != c)
            {
                part ++;
                dfs(j);
            }
        }
        printf("%d\n", part - 1);
    }
}