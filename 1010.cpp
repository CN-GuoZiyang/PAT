#include <string>
#include <iostream>
#include <cmath>

using namespace std;

long long convert2Decimal(string num, int radix)
{
    int power = 0;
    long long res = 0;
    int len = num.length();
    for(int i = len-1; i >= 0; i --, power ++)
    {
        int tmp;
        if('0' <= num[i] && num[i] <= '9')
        {
            tmp = num[i] - '0';
        } else {
            tmp = num[i] - 'a' + 10;
        }
        res += (pow(radix, power) * tmp);
    }
    return res;
}

int judgeEqual(long long s, string t)
{
    long long min = -1;
    int len = t.length();
    for(int i = 0; i < len; i ++)
    {
        char tmp = t[i];
        if(tmp > min) min = tmp;
    }
    if('0' <= min && min <= '9') min -= '0';
    else min = min - 'a' + 10;
    min ++;
    long long max = s < min ? min : s;
    while(min <= max)
    {
        long long mid = (min + max) / 2;
        long long tmp = convert2Decimal(t, mid);
        if(tmp < 0 || tmp > s) max = mid - 1;
        else if(tmp == s) return mid;
        else min = mid + 1;
    }
    return -1;
}

int main()
{
    int tag, radix;
    string n1, n2;
    cin >> n1 >> n2 >> tag >> radix;
    long long res = -1;
    if(tag == 1)
    {
        long long tmp = convert2Decimal(n1, radix);
        res = judgeEqual(tmp, n2);
    } else {
        long long tmp = convert2Decimal(n2, radix);
        res = judgeEqual(tmp, n1);
    }
    if(res == -1) cout << "Impossible";
    else cout << res;
    return 0;
}