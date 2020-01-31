/**
 * 1008 Elevator
 * 
 * The highest building in our city has only one elevator. 
 * A request list is made up with N positive numbers. 
 * The numbers denote at which floors the elevator will stop, in specified order. 
 * It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor. 
 * The elevator will stay for 5 seconds at each stop.
 * 
 * For a given request list, you are to compute the total time spent to fulfill the requests on the list. 
 * The elevator is on the 0th floor at the beginning and does not have to return to the ground floor when the requests are fulfilled.
 * 
 * Input Specification:
 * Each input file contains one test case. Each case contains a positive integer N, followed by N positive numbers. 
 * All the numbers in the input are less than 100.
 * 
 * Output Specification:
 * For each test case, print the total time on a single line.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i;
    scanf("%d", &N);
    int sum = 0;
    int lastStop = 0;
    int next;
    for(i = 0; i < N; i ++)
    {
        scanf("%d", &next);
        if(next > lastStop)
        {
            sum += 6 * (next - lastStop) + 5;
        } else if(next < lastStop)
        {
            sum += 4 * (lastStop - next) + 5;
        } else {
            sum += 5;
        }
        lastStop = next;
    }
    printf("%d\n", sum);
    return 0;
}