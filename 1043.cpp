#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

bool mirror = false;
int pre[1000];
int n;

vector<int> post;

void getPost(int root, int end)
{
    if (root > end)
        return;
    //分出左子树和右子树，i为右子树开头，j为左子树结尾
    int i = root + 1, j = end;
    if (mirror == false)
    {
        while (i <= end && pre[root] > pre[i])
        {
            i++;
        }
        while (j > root && pre[root] <= pre[j])
        {
            j--;
        }
    }
    else
    {
        while (i <= end && pre[root] <= pre[i])
        {
            i++;
        }
        while (j > root && pre[root] > pre[j])
        {
            j--;
        }
    }
    if (i - j != 1)
        return;
    getPost(root + 1, j);
    getPost(i, end);
    post.push_back(pre[root]);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pre[i]);
    }
    getPost(0, n - 1);
    if (post.size() == n)
    {
        printf("YES\n%d", post[0]);
        for (int i = 1; i < n; i++)
        {
            printf(" %d", post[i]);
        }
    }
    else
    {
        mirror = true;
        post.clear();
        getPost(0, n - 1);
        if (post.size() == n)
        {
            printf("YES\n%d", post[0]);
            for (int i = 1; i < n; i++)
            {
                printf(" %d", post[i]);
            }
        }
        else
        {
            printf("NO");
        }
    }
}