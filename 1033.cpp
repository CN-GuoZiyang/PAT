#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
    double dis;
    double price;
};

bool cmp(node a, node b)
{
    return a.dis < b.dis;
}

int main()
{
    double davg, cmax, d;
    int n;
    scanf("%lf %lf %lf %d", &cmax, &d, &davg, &n);
    vector<node> stations(n+1);
    for(int i = 0; i < n; i ++)
    {
        scanf("%lf %lf", &stations[i].price, &stations[i].dis);
    }
    stations[n].dis = d;
    stations[n].price = 0.0;
    sort(stations.begin(), stations.end(), cmp);
    if(stations[0].dis != 0)
    {
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    double cDis = 0.0, maxDis = 0.0, leftDis=0.0;
    double cPrice = stations[0].price;
    double totalPrice = 0.0;
    double cc = 0.0;
    while(cDis < d)
    {
        maxDis = cDis + cmax * davg;
        double minPriceDis = 0.0, minPrice = 999999.9;
        bool flag = false;
        for(int i = 1; i <= n && stations[i].dis <= maxDis; i ++)
        {
            if(stations[i].dis <= cDis) continue;
            if(stations[i].price < cPrice)
            {
                totalPrice += (stations[i].dis - cDis - leftDis) * cPrice / davg;
                leftDis = 0.0;
                cPrice = stations[i].price;
                cDis = stations[i].dis;
                flag = 1;
                break;
            }
            if(stations[i].price < minPrice)
            {
                minPrice = stations[i].price;
                minPriceDis = stations[i].dis;
            }
        }
        if(flag == false && minPrice != 999999.9)
        {
            totalPrice += (cPrice * (cmax - leftDis/davg));
            leftDis = cmax * davg - (minPriceDis - cDis);
            cPrice = minPrice;
            cDis = minPriceDis;
        }
        if(flag == 0 && minPrice == 999999.9)
        {
            cDis += cmax * davg;
            printf("The maximum travel distance = %.2f", cDis);
            return 0;
        }
    }
    printf("%.2lf", totalPrice);
    return 0;
}