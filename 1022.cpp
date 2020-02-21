#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

map<string, vector<string> > books;

void push(string key, string id)
{
    auto it = books.find(key);
    if(it == books.end())
    {
        vector<string> tmp;
        tmp.push_back(id);
        books[key] = tmp;
    } else {
        it->second.push_back(id);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)
    {
        string id;
        cin >> id;
        string tmp;
        getline(cin, tmp);
        push(id, id);
        string title, author, keys, publisher, year;
        getline(cin, title);
        push(title, id);
        getline(cin, author);
        push(author, id);
        getline(cin, keys);
        stringstream input(keys);
        string temp;
        while(getline(input, temp, ' '))
        {
            push(temp, id);
        }
        getline(cin, publisher);
        push(publisher, id);
        getline(cin, year);
        push(year, id);
    }
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)
    {
        char key[100];
        int id;
        scanf("%d: %[^\n]", &id, key);
        printf("%d: %s\n", id, key);
        string keyword = key;
        auto it = books.find(keyword);
        if(it != books.end())
        {
            vector<string> tmp = it->second;
            sort(tmp.begin(), tmp.end());
            int len = tmp.size();
            for(int j = 0; j < len; j ++)
            {
                cout << tmp[j] << endl;
            }
        } else {
            printf("Not Found\n");
        }
    }
    return 0;
}