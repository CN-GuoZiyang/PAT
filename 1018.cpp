#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> croad;
vector<int> rroad;
int csend = 0;
int rsend = INT_MAX;
int clength = 0;
int rlength = INT_MAX;
int rback=INT_MAX, cback = 0;
bool visit[501];
int road[501][501];
int cstatus[501];
int best, n;

void dfs(int start, int end)
{
    visit[start] = true;
    int lback = cback;
    int lsend = csend;
    cback += (cstatus[start] - best);
    if(cback < 0)
    {
        csend += (-cback);
        cback = 0;
    }
    if(start == end)
    {
        if(clength < rlength)
        {
            rlength = clength;
            rsend = csend;
            rback = cback;
            rroad.clear();
            rroad.assign(croad.begin(), croad.end());
        } else if(clength == rlength && csend < rsend)
        {
            rsend = csend;
            rback = cback;
            rroad.clear();
            rroad.assign(croad.begin(), croad.end());
        } else if(clength == rlength && csend == rsend && cback < rback)
        {
            rback = cback;
            rroad.clear();
            rroad.assign(croad.begin(), croad.end());
        }
        csend = lsend;
        cback = lback;
        visit[start] = false;
        return;
    }
    for(int i = 1; i <= n; i ++)
    {
        if(road[i][start] != 0 && visit[i] == false)
        {
            clength += road[i][start];
            if(clength > rlength)
            {
                clength -= road[i][start];
                continue;
            }
            croad.push_back(i);
            dfs(i, end);
            croad.pop_back();
            clength -= road[i][start];
        }
    }
    csend = lsend;
    cback = lback;
    visit[start] = false;
    return;
}

int main()
{
    int cm, sp, m;
    scanf("%d %d %d %d", &cm, &n, &sp, &m);
    best = cm / 2;
    cstatus[0] = best;
    for(int i = 1; i <= n; i ++)
    {
        int tmp;
        scanf("%d", &tmp);
        cstatus[i] = tmp;
    }
    for(int i = 0; i < m; i ++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        road[a][b] = c;
        road[b][a] = c;
    }
    dfs(0, sp);
    printf("%d 0", rsend);
    for(int i = 0; i < rroad.size(); i ++)
    {
        printf("->%d", rroad[i]);
    }
    printf(" %d", rback);
    return 0;
}