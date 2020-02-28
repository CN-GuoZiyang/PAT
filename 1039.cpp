#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

map<int, vector<int> > cs;

int getid(char *name)
{
    int res=0;
    for(int i = 0; i < 3; i ++)
    {
        res = 26*res + (name[i]-'A');
    }
    res = res * 10 + name[3]-'0';
    return res;
}

void put(int name, int c)
{
    if(cs.find(name) == cs.end())
    {
        vector<int> tmp;
        tmp.push_back(c);
        cs[name] = tmp;
    }
    else
    {
        cs[name].push_back(c);
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < k; i ++)
    {
        int number, ps;
        scanf("%d %d", &number, &ps);
        for(int j = 0; j < ps; j ++)
        {
            char name[5];
            scanf("%s", name);
            int id = getid(name);
            put(id, number);
        }
    }
    for(int i = 0; i < n; i ++)
    {
        char name[5];
        scanf("%s", name);
        printf("%s ", name);
        int id = getid(name);
        auto it = cs.find(id);
        if(it == cs.end())
        {
            printf("0\n");
            continue;
        }
        else
        {
            vector<int> tmp = (*it).second;
            sort(tmp.begin(), tmp.end());
            printf("%d", tmp.size());
            for(int j = 0; j < tmp.size(); j ++)
            {
                printf(" %d", tmp[j]);
            }
            printf("\n");
        }
    }
    return 0;
}