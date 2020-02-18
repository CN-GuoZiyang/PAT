#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

struct record
{
    string name;
    int time;   // minute
    int status; // 0-on, 1-off
};

int costs[25];
int month;

float getm(int a)
{
    float t = 0;
    t += (costs[24] * (a / (24*60)));
    int h = (a / 60) % 24;
    for(int i = 0; i < h; i ++)
    {
        t += (60 * costs[i]);
    }
    t += ((a % 60) * costs[h]);
    return t/100.0;
}

int cmp(record a, record b)
{
    if(a.name != b.name)
    {
        return a.name < b.name;
    } else {
        return a.time < b.time;
    }
}

int main()
{
    for(int i = 0; i < 24; i ++)
    {
        scanf("%d", &costs[i]);
        costs[24] += (costs[i] * 60);
    }
    int n;
    scanf("%d", &n);
    vector<record> recs(n);
    for(int i = 0; i < n; i ++)
    {
        cin >> recs[i].name;
        int mo, dd, hh, mm;
        scanf("%d:%d:%d:%d", &mo, &dd, &hh, &mm);
        month = mo;
        recs[i].time = dd * 60 * 24 + hh * 60 + mm;
        string status;
        cin >> status;
        if(status == "on-line") recs[i].status = 0;
        else recs[i].status = 1;
    }
    sort(recs.begin(), recs.end(), cmp);
    map<string, vector<record> > ress;
    for(int i = 0; i < recs.size()-1; i ++)
    {
        if(recs[i].name == recs[i+1].name && recs[i].status == 0 && recs[i+1].status == 1)
        {
            ress[recs[i].name].push_back(recs[i]);
            ress[recs[i].name].push_back(recs[i+1]);
        }
    }
    for(auto it : ress)
    {
        cout << it.first;
        printf(" %02d\n", month);
        vector<record> tmpv = it.second;
        float total = 0;
        for(int i = 0; i < tmpv.size(); i += 2)
        {
            int dda, hha, mma, ddb, hhb, mmb;
            dda = tmpv[i].time / (60 * 24);
            hha = (tmpv[i].time / 60) % 24;
            mma = tmpv[i].time % 60;
            ddb = tmpv[i+1].time / (60 * 24);
            hhb = (tmpv[i+1].time / 60) % 24;
            mmb = tmpv[i+1].time % 60;
            int time = tmpv[i+1].time-tmpv[i].time;
            float money = getm(tmpv[i+1].time) - getm(tmpv[i].time);
            total += money;
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", dda, hha, mma, ddb, hhb, mmb, time, money);
        }
        printf("Total amount: $%.2f\n", total);
    }
    return 0;
}