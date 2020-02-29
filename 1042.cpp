#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct card
{
    int type;   //0:spade,1:heart,2:club,3:diamond,4:joker
    int num;
};

void printC(card c)
{
    switch(c.type)
    {
        case 0:
            printf("S");
            break;
        case 1:
            printf("H");
            break;
        case 2:
            printf("C");
            break;
        case 3:
            printf("D");
            break;
        case 4:
            printf("J");
            break;
    }
    printf("%d", c.num);
}

int main()
{
    vector<card> pos[55];
    int n;
    scanf("%d", &n);
    int newp[55];
    for(int i = 1; i <= 54; i ++)
    {
        scanf("%d", &newp[i]);
    }
    int index = 1;
    for(int i = 0; i < 4; i ++)
    {
        for(int j = 1; j <= 13; j ++)
        {
            card c;
            c.type = i;
            c.num = j;
            pos[index].push_back(c);
            index ++;
        }
    }
    card c; c.type=4;c.num=1;
    pos[index].push_back(c);
    card c1; c1.type=4;c1.num=2;
    pos[index+1].push_back(c1);
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= 54; j ++)
        {
            pos[newp[j]].push_back(pos[j][i-1]);
        }
    }
    printC(pos[1][n]);
    for(int i = 2; i <= 54; i ++)
    {
        printf(" ");
        printC(pos[i][n]);
    }
    return 0;
}