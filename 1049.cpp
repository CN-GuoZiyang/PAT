#include<iostream>
#include<algorithm>

using namespace std;

int ans;

int main()
{
    int n;
    scanf("%d", &n);
    int a = 1, left, right;
    while (n / a)
    {
        int now = n / a % 10;
        left = n / (a * 10);
        right = n % a;
        if (now == 0) {
            ans += left * a;
        } else if (now == 1) {
            ans += left * a + 1 + right;
        } else if (now > 1) {
            ans += (left + 1) * a;
        }
        a *= 10;
    }
    printf("%d", ans);
    return 0;
}