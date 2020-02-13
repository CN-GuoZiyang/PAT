#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    string in;
    int inTime = 23 * 3600 + 59 * 60 + 59 * 59;
    string out;
    int outTime = 0;
    for(int i = 0; i < n; i ++)
    {
        string tmp;
        int signin[3], signout[3];
        cin >> tmp;
        scanf("%d:%d:%d %d:%d:%d", &signin[0], &signin[1], &signin[2], &signout[0], &signout[1], &signout[2]);
        int signinSec = signin[0] * 3600 + signin[1] * 60 + signin[2];
        int signoutSec = signout[0] * 3600 + signout[1] * 60 + signout[2];
        if(signinSec < inTime) 
        {
            in = tmp;
            inTime = signinSec;
        }
        if(signoutSec > outTime)
        {
            out = tmp;
            outTime = signoutSec;
        }
    }
    cout << in << " " << out;
    return 0;
}