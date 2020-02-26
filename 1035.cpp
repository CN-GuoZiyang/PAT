#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{

    int n;
    scanf("%d", &n);
    vector<pair<string, string> > res;
    for(int i = 0; i < n; i ++)
    {
        string name, tmp;
        cin >> name >> tmp;
        int len = tmp.size();
        bool flag = false;
        for(int i = 0; i < len; i ++)
        {
            if(tmp[i] == '1') {tmp[i] = '@'; flag = true;}
            if(tmp[i] == '0') {tmp[i] = '%'; flag = true;}
            if(tmp[i] == 'l') {tmp[i] = 'L'; flag = true;}
            if(tmp[i] == 'O') {tmp[i] = 'o'; flag = true;}
        }
        if(flag) res.push_back(make_pair(name, tmp));
    }
    if(res.size() == 0)
    {
        if(n == 1) printf("There is 1 account and no account is modified");
        else printf("There are %d accounts and no account is modified", n);
    } else {
        printf("%lu\n", res.size());
        for(int i = 0; i < res.size(); i ++)
        {
            cout << res[i].first << " " << res[i].second << endl;
        }
    }
    return 0;
}