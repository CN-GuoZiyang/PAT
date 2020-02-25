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
    int cIndex = 0;
    double cPrice = stations[0].price;
    double totalPrice = 0.0;
    double cc = 0.0;
    


    printf("%.2lf", totalPrice);
    return 0;
}