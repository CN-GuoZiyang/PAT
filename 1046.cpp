#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int dis[n+1];
    int tofirst[n+1];
    dis[0] = 0;
    tofirst[0] = 0;
    for(int i = 1; i <= n; i ++) {
        scanf("%d", &dis[i]);
        dis[0] += dis[i];
        tofirst[i] = tofirst[i-1]+dis[i];
    }
    int m;
    scanf("%d", &m);
    int a, b;
    for(int i = 0; i < m; i ++) {
        scanf("%d %d", &a, &b);
        if(a > b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        int d = tofirst[b-1] - tofirst[a-1];
        d = min(d, dis[0]-d);
        printf("%d\n", d);
    }
    return 0;
}