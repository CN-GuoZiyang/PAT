#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int tmp[1001][1001];

int main()
{
    string str;
    getline(cin, str, '\n');
    int len = str.size();
    int longest = 1;
    for(int i = 0; i < len; i ++)
    {
        tmp[i][i] = 1;
    }
    for(int i = 0; i < len-1; i ++)
    {
        if(str[i] == str[i+1])
        {
            tmp[i][i+1] = 1;
            longest = 2;
        }
        else
        {
            tmp[i][i+1] = 0;
        }
    }
    for(int i = 3; i <= len; i ++)
    {
        for(int j = 0; j <= len-i; j ++)
        {
            int a = j;
            int b = a+i-1;
            if(tmp[a+1][b-1] == 0) tmp[a][b] = 0;
            else
            {
                if(str[a] == str[b])
                {
                    tmp[a][b] = 1;
                    longest = i;
                } else {
                    tmp[a][b] = 0;
                }
            }
        }
    }
    printf("%d", longest);
    return 0;
}