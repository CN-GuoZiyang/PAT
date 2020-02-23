#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

struct s
{
    int num;
    string name;
    int grade;
};

int n, c;

bool cmp(s a, s b)
{
    if(c == 1)
    {
        return a.num < b.num;
    } else if(c == 2)
    {
        if(a.name != b.name) return a.name <= b.name;
        else return a.num < b.num;
    } else {
        if(a.grade != b.grade) return a.grade <= b.grade;
        else return a.num < b.num;
    }
}

int main()
{
    scanf("%d %d", &n, &c);
    vector<s> ss(n);
    for(int i = 0; i < n; i ++)
    {
        cin >> ss[i].num >> ss[i].name >> ss[i].grade;
    }
    sort(ss.begin(), ss.end(), cmp);
    for(int i = 0; i < n; i ++)
    {
        printf("%06d ", ss[i].num);
        cout << ss[i].name << " " << ss[i].grade << endl;
    }
    return 0;
}