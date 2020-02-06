#include <cstdio>
#include <queue>
using namespace std;

int n, m, k, q;
int usetime[1001];
int result[1001];

struct node {
	int poptime;
	int endtime;
	queue<int> q;
};

int main()
{
	scanf("%d %d %d %d", &n, &m, &k, &q);
	for(int i = 1; i <= k; i ++)
	{
		scanf("%d", &usetime[i]);
	}
	vector<node> windows(n + 1);
	vector<bool> sorry(k+1, false);
	int index = 1;
	
	// before yellowline
	for(int i = 1; i <= m; i ++)
	{
		for(int j = 1; j <= n; j ++)
		{
			if(index <= k)
			{
				windows[j].q.push(usetime[index]);
				if(windows[j].endtime >= 540)
				{
					sorry[index] = true;
				}
				windows[j].endtime += usetime[index];
				if(i == 1)
				{
					windows[j].poptime = windows[j].endtime;
				}
				result[index] = windows[j].endtime;
				index ++;
			}
		}
	}
	// after yellow line
	while(index <= k)
	{
		int tempmin = windows[1].poptime, tempwindow = 1;
		for(int i = 2; i <= n; i ++)
		{
			if(windows[i].poptime < tempmin)
			{
				tempmin = windows[i].poptime;
				tempwindow = i;
			}
		}
		windows[tempwindow].q.pop();
		windows[tempwindow].q.push(usetime[index]);
		windows[tempwindow].poptime += windows[tempwindow].q.front();
		if(windows[tempwindow].endtime >= 540)
		{
			sorry[index] = true;
		}
		windows[tempwindow].endtime += usetime[index];
		result[index] = windows[tempwindow].endtime;
		index ++;
	}
	for(int i = 0; i < q; i ++)
	{
		int query, res;
		scanf("%d", &query);
		res = result[query];
		if(sorry[query] == true)
		{
			printf("Sorry\n");
		} else {
			printf("%02d:%02d\n", (res + 480) / 60, (res + 480) % 60);
		}
	}
	return 0;
}
