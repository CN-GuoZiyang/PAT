#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct node
{
    long long int id;
    int score, frank, lnum, lrank;
};

vector<node> final;

bool cmp1(node a, node b)
{
    if(a.score != b.score) return a.score > b.score;
    else return a.id < b.id;
}

int main()
{
    int n, k;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
    {
        scanf("%d", &k);
        vector<node> tmp(k);
        for(int j = 0; j < k; j ++)
        {
            scanf("%lld %d", &tmp[j].id, &tmp[j].score);
            tmp[j].lnum = i;
        }
        sort(tmp.begin(), tmp.end(), cmp1);
        tmp[0].lrank = 1;
        for(int j = 1; j < k; j ++)
        {
            if(tmp[j].score == tmp[j-1].score) tmp[j].lrank = tmp[j-1].lrank;
            else tmp[j].lrank = j+1;
        }
        final.insert(final.end(), tmp.begin(), tmp.end());
    }
    sort(final.begin(), final.end(), cmp1);
    final[0].frank = 1;
    for(int i = 1; i < final.size(); i ++)
    {
        if(final[i].score == final[i-1].score) final[i].frank = final[i-1].frank;
        else final[i].frank = i+1;
    }
    printf("%lu\n", final.size());
    for(int i = 0; i < final.size(); i ++)
    {
        printf("%013lld %d %d %d\n", final[i].id, final[i].frank, final[i].lnum, final[i].lrank);
    }
    return 0;
}