#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int timeCharges[25];

struct node
{
	string name;
	int status, month, day, hour, minute;
	int time;
};

bool cmp(node a, node b)
{
	return a.name != b.name ? a.name < b.name : a.time < b.time;
}

float calculateAll(node a)
{
	float total = a.minute * timeCharges[a.hour] + timeCharges[24] * 60 * a.day;
	for(int i = 0; i < a.hour; i ++)
	{
		total += timeCharges[i] * 60;
	}
	return total;
}

int main()
{
	for(int i = 0; i < 24; i ++)
	{
		scanf("%d", &timeCharges[i]);
		timeCharges[24] += timeCharges[i];
	}
	int N;
	scanf("%d", &N);
	vector<node> records(N);
	for(int i = 0; i < N; i ++)
	{
		cin >> records[i].name;
		scanf("%d:%d:%d:%d", &records[i].month, &records[i].day, &records[i].hour, &records[i].minute);
		string status;
		cin >> status;
		records[i].status = status == "on-line" ? 0 : 1;
		records[i].time = records[i].day * 24 * 60 + records[i].hour * 60 + records[i].minute;
	}
	sort(records.begin(), records.end(), cmp);
	map<string, vector<node> > shaixuan;
	for(int i = 0; i < N - 1; i ++)
	{
		if(records[i].name == records[i+1].name && records[i].status == 0 && records[i + 1].status == 1)
		{
			shaixuan[records[i].name].push_back(records[i]);
			shaixuan[records[i + 1].name].push_back(records[i + 1]);
		}
	}
	for(auto it : shaixuan)
	{
		vector<node> tmp = it.second;
		cout << it.first;
		printf(" %02d\n", tmp[0].month);
		double total = 0.0;
		for(int i = 1; i < tmp.size(); i += 2)
		{
			double t = (calculateAll(tmp[i]) - calculateAll(tmp[i - 1])) / 100;
			total += t;
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", tmp[i-1].day, tmp[i-1].hour, tmp[i-1].minute, tmp[i].day, tmp[i].hour, tmp[i].minute, tmp[i].time - tmp[i-1].time, t);
		}
		printf("Total amount: $%.2f\n", total);
	}
	return 0;
}
