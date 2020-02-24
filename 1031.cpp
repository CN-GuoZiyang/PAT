#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int N = str.length();
    int n2 = (N+2)/3+(N+2)%3;
    int n1 = (N+2)/3;
    int spnum = n2-2;
    for(int i = 0; i < n1-1; i ++)
    {
        printf("%c", str[i]);
        for(int j = 0; j < spnum; j ++)
        {
            printf(" ");
        }
        printf("%c\n", str[N-i-1]);
    }
    for(int i = 0; i < n2; i ++)
    {
        printf("%c", str[n1-1+i]);
    }
    printf("\n");
    return 0;
}