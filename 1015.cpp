#include <cstdio>
#include <cmath>
using namespace std;

bool isPrime(int a)
{
	if(a < 2) return false;
	int half = sqrt(a) + 1;
	for(int i = 2; i < half; i ++)
	{
		if(a % i == 0) return false;
	}
	return true;
}

int main()
{
	while(true)
	{
		int n, d;
		scanf("%d", &n);
		if(n < 0) break;
		scanf("%d", &d);
		if(isPrime(n) == false)
		{
			printf("No\n");
			continue;
		}
		int temp, degit = 0;
		int tmp[100];
		while(true)
		{
			temp = n % d;
			tmp[degit] = temp;
			degit ++;
			n /= d;
			if(n == 0) break;
		}
		int after = 0;
		for(int i = 0; i < degit; i ++)
		{
			after += tmp[degit - i - 1] * pow(d, i);
		}
		if(isPrime(after) == true)
		{
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}
