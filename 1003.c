/**
 * 1003 Emergency
 * 
 * As an emergency rescue team leader of a city, you are given a special map of your country. 
 * The map shows several scattered cities connected by some roads. 
 * Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. 
 * When there is an emergency call to you from some other city, 
 * your job is to lead your men to the place as quickly as possible, and at the mean time, 
 * call up as many hands on the way as possible.
 * 
 * Input Specification:
 * Each input file contains one test case. 
 * For each test case, the first line contains 4 positive integers: N (≤500) - the number of cities 
 * (and the cities are numbered from 0 to N−1), 
 * M - the number of roads, C1 and C2 - the cities that you are currently in and that you must save, respectively. 
 * The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. 
 * Then M lines follow, each describes a road with three integers c1, c2 and L, 
 * which are the pair of cities connected by a road and the length of that road, respectively. 
 * It is guaranteed that there exists at least one path from C1 to C2.
 * 
 * Output Specification:
 * For each test case, print in one line two numbers: the number of different shortest paths between C​1 and C​2, 
 * and the maximum amount of rescue teams you can possibly gather. 
 * All the numbers in a line must be separated by exactly one space, 
 * and there is no extra space allowed at the end of a line.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int N = 0;
int leastLength = INT_MAX;
int roadsRes = -1;
int rescureRes = -1;
int rescueTeams[500];
int roadMap[500][500];
int visited[500];
int currentLength = 0;
int currentRescues = 0;

void DFS(int start, int end)
{
    currentRescues += rescueTeams[start];
    if(currentLength > leastLength || (currentLength == leastLength && start != end)) 
    {
        return;
    }
    if(start == end)
    {
        if(currentLength < leastLength)
        {
            leastLength = currentLength;
            roadsRes = 1;
            rescureRes = currentRescues;
        } else if(currentLength == leastLength)
        {
            roadsRes ++;
            if(rescureRes < currentRescues)
            {
                rescureRes = currentRescues;
            }
        }
        return;
    }
    visited[start] = 1;
    int i = 0;
    for(i = 0; i < N; i ++)
    {
        if(start != i)
        {
            if(visited[i] == 0 && roadMap[start][i] != -1)
            {
                currentLength += roadMap[start][i];
                DFS(i, end);
                currentLength -= roadMap[start][i];
                currentRescues -= rescueTeams[i];
            }
        }
    }
    visited[start] = 0;
    return;
}

int main()
{
    int M, C1, C2;
    scanf("%d %d %d %d", &N, &M, &C1, &C2);
    int i = 0;
    for(i = 0; i < N; i ++)
    {
        scanf("%d", &rescueTeams[i]);
        visited[i] = 0;
        int j = 0;
        for(j = 0; j < N; j ++)
        {
            roadMap[i][j] = -1;
        }
    }
    int a, b, c;
    for(i = 0; i < M; i ++)
    {
        scanf("%d %d %d", &a, &b, &c);
        roadMap[a][b] = c;
        roadMap[b][a] = c;
    }
    DFS(C1, C2);
    printf("%d %d\n", roadsRes, rescureRes);
    return 0;
}