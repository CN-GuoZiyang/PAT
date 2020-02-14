#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int k;
    scanf("%d", &k);
    int start=0, end=0, sum=-1;
    int tmpsum=0, tmpstart=0, tmpend=-1;
    bool allneg = true;
    vector<int> ints;
    for(int i = 0; i < k; i ++)
    {
        int tmp;
        scanf("%d", &tmp);
        ints.push_back(tmp);
        if(tmp >= 0) allneg = false;
        tmpsum += tmp;
        tmpend ++;
        if(tmpsum < 0)
        {
            tmpsum = 0;
            tmpstart = i+1;
            tmpend = i;
            continue;
        }
        if(tmpsum > sum)
        {
            start = tmpstart;
            end = tmpend;
            sum = tmpsum;
        }
    }
    if(allneg == true)
    {
        printf("0 %d %d", ints[0], ints[ints.size() - 1]);
        return 0;
    }
    printf("%d %d %d", sum, ints[start], ints[end]);
    return 0;
}