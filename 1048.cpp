#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

int times[1001];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i ++) {
        int tmp;
        scanf("%d", &tmp);
        times[tmp] ++;
    }
    for(int i = 0; i < 1001; i ++) {
        if(times[i] > 0) {
            times[i]--;
            if(m>i && times[m-i] > 0) {
                printf("%d %d", i, m-i);
                return 0;
            }
            times[i]++;
        }
    }
    printf("No Solution");
    return 0;
}