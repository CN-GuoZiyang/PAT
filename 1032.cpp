#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct node
{
    char data;
    int next;
};

node nodes[100000];

int main()
{
    int abegin, bbegin, n;
    scanf("%d %d %d", &abegin, &bbegin, &n);
    for(int i = 0; i < n; i ++)
    {
        int ad, next;
        char data;
        scanf("%d %c %d", &ad, &data, &next);
        nodes[ad].data = data;
        nodes[ad].next = next;
    }
    vector<int> a, b;
    int ad = abegin;
    while(ad != -1)
    {
        a.push_back(ad);
        ad = nodes[ad].next;
    }
    int bd = bbegin;
    while(bd != -1)
    {
        b.push_back(bd);
        bd = nodes[bd].next;
    }
    if(a.size() == 0 || b.size() == 0 || a[a.size()-1] != b[b.size()-1])
    {
        printf("-1");
        return 0;
    }
    int res = a[a.size()-1], aindex=a.size()-2, bindex=b.size()-2;
    if(aindex == -1 || bindex == -1)
    {
        printf("%05d", res);
        return 0;
    }
    while(a[aindex] == b[bindex])
    {
        res = a[aindex];
        aindex --;
        bindex --;
        if(aindex == -1) break;
        if(bindex == -1) break;
    }
    printf("%05d", res);
    return 0;
}