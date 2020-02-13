#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    char tmp;
    int sum = 0;
    while(scanf("%c", &tmp) != EOF)
    {
        if('0' <= tmp && tmp <= '9') sum += (tmp - '0');
    }
    string sumStr = to_string(sum);
    int len = sumStr.length();
    string numStr[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    cout << numStr[sumStr[0] - '0'];
    for(int i = 1; i < len; i ++)
    {
        cout << " " << numStr[sumStr[i] - '0'];
    }
    return 0;
}