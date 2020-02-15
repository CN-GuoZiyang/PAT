#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

bool cmp(pair<int, double> a, pair<int, double> b)
{
    return a.first > b.first;
}

int main()
{
    map<int, double> pa;
    map<int, double> res;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)
    {
        int exp;
        double co;
        scanf("%d %lf", &exp, &co);
        pa[exp] = co;
    }
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)
    {
        int exp;
        double co;
        scanf("%d %lf", &exp, &co);
        for(auto it = pa.begin(); it != pa.end(); it ++)
        {
            int tmp = exp + it->first;
            auto tmpit = res.find(tmp);
            if(tmpit != res.end())
            {
                res[tmp] = res[tmp] + it->second * co;
            } else {
                res[tmp] = it->second * co;
            }
        }
    }
    vector<pair<int, double> > resv(res.begin(), res.end());
    sort(resv.begin(), resv.end(), cmp);
    int num = 0;
    for(int i = 0; i < resv.size(); i ++)
    {
        if(abs(resv[i].second) > 0.05) num ++;
    }
    printf("%d", num);
    for(int i = 0; i < resv.size(); i ++)
    {
        if(abs(resv[i].second) > 0.05) printf(" %d %.1f", resv[i].first, resv[i].second);
    }
    return 0;
}