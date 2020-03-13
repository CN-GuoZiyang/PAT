#include <algorithm>
#include <map>
#include <cstdio>

using namespace std;

int main() {
    int max=0, maxnum=-1, m, n;
    map<int, int> res;
    scanf("%d %d", &m, &n);
    for(int i = 0; i < m; i ++) {
        for(int j = 0; j < n; j ++) {
            int tmp;
            scanf("%d", &tmp);
            if(res.find(tmp) == res.end()) {
                res[tmp] = 1;
            } else {
                res[tmp] ++;
            }
            if(res[tmp] > maxnum) {
                maxnum = res[tmp];
                max = tmp;
            }
        }
    }
    printf("%d", max);
    return 0;
}