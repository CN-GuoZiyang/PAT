#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int n, m, c1, c2;
vector<int> teams;
vector<bool> visited(500, false);
int road[500][500];

int paths = 0;
int length = INT_MAX;
int tmpLength = 0;
int res = -1;
int tmpRes = 0;

void dfs(int start)
{
    tmpRes += teams[start];
    if(start == c2)
    {
        if(tmpLength < length)
        {
            length = tmpLength;
            paths = 1;
            res = tmpRes;
        } else if(tmpLength == length)
        {
            paths ++;
            if(tmpRes > res) res = tmpRes;
        }
        tmpRes -= teams[start];
        return;
    }
    visited[start] = true;
    for(int i = 0; i < n; i ++)
    {
        if(visited[i] == false && road[start][i] != 0)
        {
            tmpLength += road[start][i];
            if(tmpLength > length)
            {
                tmpLength -= road[start][i];
                continue;
            }
            dfs(i);
            tmpLength -= road[start][i];
        }
    }
    visited[start] = false;
    tmpRes -= teams[start];
    return;
}

int main()
{
    scanf("%d %d %d %d", &n, &m, &c1, &c2);
    for(int i = 0; i < n; i ++)
    {
        int tmp;
        scanf("%d", &tmp);
        teams.push_back(tmp);
    }
    for(int i = 0; i < m; i ++)
    {
        int a, b, l;
        scanf("%d %d %d", &a, &b, &l);
        road[a][b] = l;
        road[b][a] = l;
    }
    dfs(c1);
    printf("%d %d", paths, res);
    return 0;
}