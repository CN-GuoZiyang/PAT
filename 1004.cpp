#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;

struct node {
    vector<int> children;
};

int main()
{
    scanf("%d %d", &n, &m);
    vector<node> nodes(n+1);
    for(int i = 0; i < m; i ++)
    {
        int id, k;
        scanf("%d %d", &id, &k);
        for(int j = 0; j < k; j ++)
        {
            int tmp;
            scanf("%d", &tmp);
            nodes[id].children.push_back(tmp);
        }
    }
    queue<int> q;
    q.push(1);
    vector<int> reses;
    while(q.empty() == false)
    {
        vector<int> layer;
        while(q.size() != 0)
        {
            layer.push_back(q.front());
            q.pop();
        }
        int res = 0;
        for(int i = 0; i < layer.size(); i ++)
        {
            int index = layer[i];
            if(nodes[index].children.size() == 0)
            {
                res ++;
            } else {
                for(int j = 0; j < nodes[index].children.size(); j ++)
                {
                    q.push(nodes[index].children[j]);
                }
            }
        }
        reses.push_back(res);
    }
    for(int i = 0; i < reses.size(); i ++)
    {
        if(i == reses.size() - 1)
        {
            printf("%d", reses[i]);
        } else {
            printf("%d ", reses[i]);
        }
    }
    return 0;
}