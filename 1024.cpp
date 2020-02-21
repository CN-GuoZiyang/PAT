#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool test(string s)
{
    if(s.size() == 1) return true;
    int l=0, r=s.size()-1;
    while(l < r)
    {
        if(s[l] != s[r]) return false;
        l ++;
        r --;
    }
    return true;
}

string add(string a)
{
    string b = a;
    reverse(b.begin(), b.end());
    vector<char> resv;
    int len = a.length();
    int jinwei = 0;
    for(int i = len-1; i >= 0; i --)
    {
        int tmpa = a[i]-'0', tmpb = b[i]-'0';
        int res = tmpa + tmpb + jinwei;
        if(res >= 10)
        {
            res = res % 10;
            jinwei = 1;
        } else {
            jinwei = 0;
        }
        char tmp = res + '0';
        resv.push_back(tmp);
    }
    if(jinwei != 0) resv.push_back('1');
    reverse(resv.begin(), resv.end());
    char resc[resv.size()+1];
    for(int i = 0; i < resv.size(); i ++)
    {
        resc[i] = resv[i];
    }
    resc[resv.size()] = '\0';
    string rt = resc;
    return rt;
}

int main()
{
    string raw;
    int k;
    cin >> raw >> k;
    if(test(raw) == true) 
    {
        cout << raw << endl;
        cout << 0;
        return 0;
    }
    for(int i = 1; i <= k; i ++)
    {
        raw = add(raw);
        if(test(raw) == true)
        {
            cout << raw << endl;
            cout << i;
            return 0;
        }
    }
    cout << raw << endl;
    cout << k;
    return 0;
}