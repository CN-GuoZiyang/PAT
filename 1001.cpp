#include <cstdio>
#include <string>
using namespace std;

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    string sumStr = to_string(a + b);
    int len = sumStr.length();
    for(int i = 0;i < len; i ++)
    {
        printf("%c", sumStr[i]);
        if(sumStr[i] == '-') continue;
        if((len - i)%3 == 1 && i != len - 1) printf(",");
    }
    return 0;
}