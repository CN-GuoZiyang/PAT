#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool cmp(string a, string b)
{
    return a+b < b+a;
}

int main()
{
    int n;
    cin >> n;
    vector<string> ss(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ss[i];
    }
    sort(ss.begin(), ss.end(), cmp);
    string s="";
    for(int i = 0; i < n; i ++)
    {
        s += ss[i];
    }
    while(s.length() != 0 && s[0] == '0')
    {
        s.erase(s.begin());
    }
    if(s.length() == 0) cout << 0;
    else cout << s;
    return 0;
}