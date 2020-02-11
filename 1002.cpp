#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int cmp(pair<int, double> &a, pair<int, double> &b)
{
    return a.first > b.first;
}

int main()
{
    map<int, double> exps;
    for(int i = 0; i < 2; i ++)
    {
        int n;
        scanf("%d", &n);
        for(int j = 0; j < n; j ++)
        {
            int exp; double co;
            scanf("%d %lf", &exp, &co);
            if(exps.find(exp) != exps.end()) {
                exps[exp] += co;
            } else {
                exps[exp] = co;
            }
        }
    }
    vector<pair<int, double> > vecs(exps.begin(), exps.end());
    sort(vecs.begin(), vecs.end(), cmp);
    int len = 0;
    for(int i = 0; i < vecs.size(); i ++)
    {
        if(abs(vecs[i].second) > 0.01) len ++;
    }
    printf("%d", len);
    for(int i = 0; i < vecs.size(); i ++)
    {
        if(abs(vecs[i].second) > 0.01) printf(" %d %.1f", vecs[i].first, vecs[i].second);
    }
    return 0;
}