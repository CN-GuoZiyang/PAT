#include <vector>
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct stu
{
    string name;
    bool male;
    string id;
    int grade;
};

bool cmp(stu a, stu b)
{
    return a.grade > b.grade;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<stu> stus(n);
    bool hasM=false, hasF=false;
    for(int i = 0; i < n; i ++)
    {
        char gen;
        cin >> stus[i].name;
        cin >> gen;
        if(gen == 'M')
        {
            stus[i].male = true;
            hasM = true;
        }
        else 
        {
            stus[i].male = false;
            hasF = true;
        }
        cin >> stus[i].id >> stus[i].grade;
    }
    sort(stus.begin(), stus.end(), cmp);
    int m, f;
    if(!hasF)
    {
        printf("Absent\n");
    } else {
        for(int i = 0; i < n; i ++)
        {
            if(stus[i].male == false)
            {
                cout << stus[i].name << " " << stus[i].id << endl;
                f = stus[i].grade;
                break;
            }
        }
    }
    if(!hasM)
    {
        printf("Absent\n");
    } else {
        for(int i = n-1; i >= 0; i --)
        {
            if(stus[i].male == true)
            {
                cout << stus[i].name << " " << stus[i].id << endl;
                m = stus[i].grade;
                break;
            }
        }
    }
    if(hasM == false || hasF == false)
    {
        printf("NA\n");
    } else {
        printf("%d", abs(m-f));
    }
    return 0;
}