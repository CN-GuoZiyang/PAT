#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int n, k, p;
int rel[2000][2000];
map<string, int> ids;
map<int, string> names;
vector<vector<int> > gangs;
vector<int> tmpgangs;
int tmpw = 0;
bool visit[2000];

int cindex = -1;

int getIds(string name)
{
    if(ids.find(name) == ids.end())
    {
        cindex ++;
        ids[name] = cindex;
        names[cindex] = name;
        return cindex;
    }
    return ids[name];
}

void dfs(int start, int last)
{
    visit[start] = true;
    // cout << "add " << names[start] << " w is " << tmpw << endl;
    tmpgangs.push_back(start);
    for(int i = 0; i < p; i ++)
    {
        if(rel[start][i] != 0 && visit[i] == false)
        {
            tmpw += rel[start][i];
            dfs(i, start);
        } else if(rel[start][i] != 0 && i != last)
        {
            tmpw += rel[start][i];
        }
    }
}

int getW(int a)
{
    int total = 0;
    for(int i = 0; i < p; i ++)
    {
        if(rel[a][i] != 0 && i != a)
        {
            total += rel[a][i];
        }
    }
    return total;
}

int cmp(pair<string, int> a, pair<string, int> b)
{
    return a.first < b.first;
}

int main()
{
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i ++)
    {
        string as, bs;
        int w;
        cin >> as >> bs >> w;
        int a = getIds(as);
        int b = getIds(bs);
        rel[a][b] += w;
        rel[b][a] += w;
    }
    p = ids.size();
    for(int i = 0; i < p; i ++)
    {
        if(visit[i] == false)
        {
            tmpgangs.clear();
            tmpw = 0;
            dfs(i, -1);
            if(tmpw > k && tmpgangs.size() > 2)
            {
                vector<int> tmp;
                tmp.assign(tmpgangs.begin(), tmpgangs.end());
                gangs.push_back(tmp);
            }
        }
    }
    printf("%lu\n", gangs.size());
    map<string, int> res;
    for(int i = 0; i < gangs.size(); i ++)
    {
        int maxI = -1, max = -1;
        vector<int> tmp = gangs[i];
        for(int j = 0; j < tmp.size(); j ++)
        {
            int tmpm = getW(tmp[j]);
            if(tmpm > max)
            {
                max = tmpm;
                maxI = j;
            }
        }
        res[names[tmp[maxI]]] = tmp.size();
    }
    vector<pair<string, int> > ress(res.begin(), res.end());
    sort(ress.begin(), ress.end(), cmp);
    for(int i = 0; i < ress.size(); i ++)
    {
        cout << ress[i].first << " " << ress[i].second << endl;
    }
    return 0;
}