#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    char before[10001];
    int c[1000];
    int index = 0;
    char ch;
    while(true) {
        scanf("%c", &ch);
        if(ch == '\n') break;
        before[index] = ch;
        index ++;
    }
    while(true) {
        scanf("%c", &ch);
        if(ch == '\n') break;
        else c[ch] = 1;
    }
    for(int i = 0; i < index; i ++) {
        if(c[before[i]] != 1) {
            printf("%c", before[i]);
        }
    }
    return 0;
}