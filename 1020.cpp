#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct node
{
    int left, right;
};

int n, post[31], in[31];
vector<node> tree(31);

int build(vector<int> posto, vector<int> ino)
{
    if(posto.size() == 1) return posto[0];
    else if(posto.size() == 0) return -1;
    int root = posto[posto.size() - 1];
    int rootIndex = 0;
    for(rootIndex = 0; rootIndex < ino.size(); rootIndex ++)
    {
        if(ino[rootIndex] == root) break;
    }
    vector<int> leftin, rightin, leftpo, rightpo;
    leftin.assign(ino.begin(), ino.begin()+rootIndex);
    rightin.assign(ino.begin()+rootIndex+1, ino.end());
    for(int i = 0; i < posto.size(); i ++)
    {
        int tmp = posto[i];
        if(find(leftin.begin(), leftin.end(), tmp) != leftin.end()) leftpo.push_back(tmp);
        else if(find(rightin.begin(), rightin.end(), tmp) != rightin.end()) rightpo.push_back(tmp);
    }
    int left = build(leftpo, leftin);
    int right = build(rightpo, rightin);
    tree[root].left = left;
    tree[root].right = right;
    return root;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)
    {
        scanf("%d", &post[i]);
    }
    for(int i = 0; i < n; i ++)
    {
        scanf("%d", &in[i]);
    }
    vector<int> posto(post, post+n);
    vector<int> ino(in, in+n);
    int root = build(posto, ino);
    queue<int> cu;
    cu.push(root);
    printf("%d", root);
    while(cu.empty() == false)
    {
        int tmp = cu.front();
        cu.pop();
        if(tmp != root) printf(" %d", tmp);
        if(tree[tmp].left != -1 && tree[tmp].left != 0) cu.push(tree[tmp].left);
        if(tree[tmp].right != -1 && tree[tmp].right != 0) cu.push(tree[tmp].right);
    }
}