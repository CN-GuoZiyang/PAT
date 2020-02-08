#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct node
{
    int arrive;
    int process;
};

int N, K;

int START_SERVICE = 28800;
int END_SERVICE = 61201;

bool cmp(node a, node b)
{
    return a.arrive < b.arrive;
}

int main()
{
    scanf("%d %d", &N, &K);
    vector<node> custom;
    int hh, mm, ss, p;
    for(int i = 0; i < N; i ++)
    {
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &p);
        int cometime = hh * 60 * 60 + mm * 60 + ss;
        if(cometime >= END_SERVICE)
        {
            continue;
        }
        node tmp = {cometime, p * 60};
        custom.push_back(tmp);
    }
    sort(custom.begin(), custom.end(), cmp);
    vector<int> window(K, START_SERVICE);
    double res;
    for(int index = 0; index < custom.size(); index ++)
    {
        int minWindow = 0;
        int minTime = window[0];
        for(int i = 1; i < K; i ++)
        {
            if(window[i] < minTime)
            {
                minWindow = i;
                minTime = window[i];
            }
        }
        if(window[minWindow] <= custom[index].arrive)
        {
            window[minWindow] = custom[index].arrive + custom[index].process;
        } else {
            res += window[minWindow] - custom[index].arrive;
            window[minWindow] += custom[index].process;
        }
    }
    if(custom.size() == 0)
    {
        printf("0.0");
    } else {
        printf("%.1f", res / 60.0 / custom.size());
    }
    return 0;
}