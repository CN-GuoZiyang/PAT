#include <cstdio>

using namespace std;

int main() {
    long long a, b, c, d, e, f, suma, sumb, total;
    scanf("%lld.%lld.%lld %lld.%lld.%lld", &a, &b, &c, &d, &e, &f);
    suma = a*17*29 + b*29 + c;
    sumb = d*17*29 + e*29 + f;
    total = suma + sumb;
    printf("%lld.%lld.%lld", total/17/29, (total-(total/17/29)*17*29)/29, total%29);
}