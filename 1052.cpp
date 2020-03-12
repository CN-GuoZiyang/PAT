#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int addr;
    int key;
    int next;
    bool flag;
};

int n, head;

bool cmp(node a, node b) {
    return !a.flag || !b.flag ? a.flag > b.flag : a.key < b.key;
}

int main() {
    scanf("%d %d", &n, &head);
    vector<node> nodes(n);
    int m[100001];
    for(int i = 0; i < n; i ++) {
        scanf("%d %d %d", &nodes[i].addr, &nodes[i].key, &nodes[i].next);
        nodes[i].flag = false;
        m[nodes[i].addr] = i;
    }
    int count = 0;
    while(head != -1) {
        nodes[m[head]].flag = true;
        head = nodes[m[head]].next;
        count ++;
    }
    if(count == 0) {
        printf("0 -1");
        return 0;
    }
    sort(nodes.begin(), nodes.end(), cmp);
    printf("%d %05d\n", count, nodes[0].addr);
    for(int i = 0; i < count; i ++) {
        printf("%05d %d ", nodes[i].addr, nodes[i].key);
        if(i == count-1) {
            printf("-1\n");
        } else {
            printf("%05d\n", nodes[i+1].addr);
        }
    }
    return 0;
}