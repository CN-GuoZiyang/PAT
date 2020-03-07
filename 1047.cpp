#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

char names[40001][5];

bool cmp(int a, int b) {
    return strcmp(names[a], names[b]) < 0;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    vector<vector<int> > cs(k+1);
    for(int i = 1; i <= n; i ++) {
        int num;
        scanf("%s %d", names[i], &num);
        for(int j = 0; j < num; j ++) {
            int c;
            scanf("%d", &c);
            cs[c].push_back(i);
        }
    }
    for(int i = 1; i <= k; i ++) {
        vector<int> v = cs[i];
        sort(v.begin(), v.end(), cmp);
        int len = v.size();
        printf("%d %d\n", i, len);
        for(int j = 0; j < len; j ++) {
            printf("%s\n", names[v[j]]);
        }
    }
    return 0;
}