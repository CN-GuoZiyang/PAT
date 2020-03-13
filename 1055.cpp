#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct p {
    char name[10];
    int age;
    int money;
};

bool cmp(p a, p b) {
    if(a.money != b.money) {
        return a.money > b.money;
    } else if(a.age != b.age) {
        return a.age < b.age;
    } else {
         return strcmp(a.name, b.name) < 0;
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<p> people(n);
    for(int i = 0; i < n; i ++) {
        scanf("%s %d %d", people[i].name, &people[i].age, &people[i].money);
    }
    sort(people.begin(), people.end(), cmp);
    for(int i = 1; i <= k; i ++) {
        int count = 0;
        printf("Case #%d:\n", i);
        int num, min, max;
        scanf("%d %d %d", &num, &min, &max);
        for(int j = 0; j < n; j ++) {
            if(min <= people[j].age && people[j].age <= max) {
                count ++;
                printf("%s %d %d\n", people[j].name, people[j].age, people[j].money);
                if(count == num) break;
            }
        }
        if(count == 0) {
            printf("None\n");
        }
    }
    return 0;
}