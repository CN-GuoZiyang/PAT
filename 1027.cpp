#include <cstdio>
#include <algorithm>

using namespace std;

char shisan[13]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};

void convert(int a)
{
    char tmp[2] = {'0', '0'};
    int i = 1;
    while(a != 0)
    {
        tmp[i] = shisan[a % 13];
        a /= 13;
        i --;
    }
    for(i = 0; i < 2; i ++)
    {
        printf("%c", tmp[i]);
    }
}

int main()
{
    int dr, dg, db;
    scanf("%d %d %d", &dr, &dg, &db);
    printf("#");
    convert(dr);
    convert(dg);
    convert(db);
    return 0;
}