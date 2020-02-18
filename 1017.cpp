#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct window
{
    int endTime = 8 * 60 * 60;
};

struct cu
{
    int aTime;
    int pTime;
};

bool cmp(cu a, cu b)
{
    return a.aTime < b.aTime;
};

int main()
{
    int n, k, res=0;
    scanf("%d %d", &n, &k);
    vector<window> windows(k);
    vector<cu> cus(n);
    for(int i = 0; i < n; i ++)
    {
        int hh, mm, ss, p;
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &p);
        p *= 60;
        cus[i].aTime = hh * 3600 + mm * 60 + ss;
        cus[i].pTime = p;
    }
    sort(cus.begin(), cus.end(), cmp);
    int count = 0;
    for(int i = 0; i < n; i ++)
    {
        cu tmp = cus[i];
        if(tmp.aTime >= 17*3600 + 1) break;
        int minT = windows[0].endTime, min=0;
        for(int j = 1; j < k; j ++)
        {
            if(windows[j].endTime < minT)
            {
                min = j;
                minT = windows[j].endTime;
            }
        }
        if(tmp.aTime < minT)
        {
            res += (minT - tmp.aTime);
            windows[min].endTime += tmp.pTime;
        } else if(tmp.aTime == minT) {
            windows[min].endTime += tmp.pTime;
        } else {
            windows[min].endTime = tmp.aTime + tmp.pTime;
        }
        count ++;
    }
    float avg = res / 60.0 / count;
    printf("%.1f", avg);
    return 0;
}