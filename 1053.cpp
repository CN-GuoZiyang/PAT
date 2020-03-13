#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, s;

struct node {
    int weight;
    vector<int> children;
};

node nodes[101];
bool visit[101];

vector<int> croad;
int cw = 0;
vector<vector<int> > res;

void dfs(int start) {
    croad.push_back(start);
    visit[start] = true;
    cw += nodes[start].weight;
    if(cw == s) {
        if(nodes[start].children.empty()) {
            vector<int> tmp;
            tmp.assign(croad.begin(), croad.end());
            res.push_back(tmp);
        }
        croad.pop_back();
        cw -= nodes[start].weight;
        return;
    }
    if(cw > s) {
        croad.pop_back();
        cw -= nodes[start].weight;
        return;
    }
    int len = nodes[start].children.size();
    for(int i = 0; i < len; i ++) {
        dfs(nodes[start].children[i]);
    }
    croad.pop_back();
    cw -= nodes[start].weight;
    return;
}

int main() {
    scanf("%d %d %d", &n, &m, &s);
    for(int i = 0; i < n; i ++) {
        scanf("%d", &nodes[i].weight);
    }
    for(int i = 0; i < m; i ++) {
        int id, num;
        scanf("%d %d ", &id, &num);
        for(int j = 0; j < num; j ++) {
            int tmp;
            scanf("%d", &tmp);
            nodes[id].children.push_back(tmp);
        }
    }
    dfs(0);
    vector<vector<int> > ress;
    for(int i = 0; i < res.size(); i ++) {
        vector<int> t;
        vector<int> r = res[i];
        for(int j = 0; j < r.size(); j ++) {
            t.push_back(nodes[r[j]].weight);
        }
        ress.push_back(t);
    }
    sort(ress.begin(), ress.end());
    for(int i = ress.size()-1; i >= 0; i --) {
        vector<int> r = ress[i];
        printf("%d", r[0]);
        for(int j = 1; j < r.size(); j ++) {
            printf(" %d", r[j]);
        }
        printf("\n");
    }
    return 0;
}