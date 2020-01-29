/**
 * 1004 Counting Leaves
 * 
 * A family hierarchy is usually presented by a pedigree tree. 
 * Your job is to count those family members who have no child.
 * 
 * Input Specification:
 * Each input file contains one test case. 
 * Each case starts with a line containing 0<N<100, 
 * the number of nodes in a tree, and M (<N), the number of non-leaf nodes. 
 * Then M lines follow, each in the format:
 * ID K ID[1] ID[2] ... ID[K]
 * where ID is a two-digit number representing a given non-leaf node, 
 * K is the number of its children, followed by a sequence of two-digit ID's of its children. 
 * For the sake of simplicity, let us fix the root ID to be 01.
 * The input ends with N being 0. That case must NOT be processed.
 * 
 * Output Specification:
 * For each test case, you are supposed to count those family members who have no child for every seniority level starting from the root. 
 * The numbers must be printed in a line, separated by a space, 
 * and there must be no extra space at the end of each line.
 * The sample case represents a tree with only 2 nodes, 
 * where 01 is the root and 02 is its only child. Hence on the root 01 level, 
 * there is 0 leaf node; and on the next level, there is 1 leaf node. Then we should output 0 1 in a line.
 */

#include <stdio.h>
#include <stdlib.h>

struct nodeStruct{
    int label;
    int children;
    int child[99];
};

typedef struct {
    int data[102];
    int front;  // 第一个元素 - 1
    int rear;   // 标志最后一个元素
    int size;
} Queue;

void addToQueue(Queue* q, int item)
{
    q->rear ++;
    q->size ++;
    q->data[q->rear] = item;
}

int outQueue(Queue* q)
{
    q->front ++;
    q->size --;
    return q->data[q->front];
}

int main()
{
    int i, j, N, M;
    scanf("%d %d", &N, &M);
    if(N == 0) return 0;
    struct nodeStruct nodes[N+1];
    for(i = 1; i <= N; i ++)
    {
        nodes[i].label = -1;
        nodes[i].children = 0;
    }
    int k, label;
    for(i = 0; i < M; i ++)
    {
        scanf("%d %d", &label, &k);
        nodes[label].label = label;
        nodes[label].children = k;
        for(j = 0; j < k; j ++)
        {
            int childLabel;
            scanf("%d", &childLabel);
            if(nodes[childLabel].label == -1)
            {
                nodes[childLabel].label = childLabel;
                nodes[childLabel].children = 0;
            }
            nodes[label].child[j] = childLabel;
        }
    }
    Queue* q = (Queue *)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    struct nodeStruct root = nodes[1];
    if(N == 1)
    {
        printf("1\n");
        return 0;
    }
    printf("0");
    int level = root.children;
    for(i = 0; i < level; i ++)
    {
        addToQueue(q, root.child[i]);
    }
    int res = 0;
    int nextLevel = 0;
    while(1)
    {
        res = 0;
        nextLevel = 0;
        for(i = 0; i < level; i ++)
        {
            int label = outQueue(q);
            if(nodes[label].children == 0) res ++;
            else {
                for(j = 0; j < nodes[label].children; j ++)
                {
                    addToQueue(q, nodes[label].child[j]);
                    nextLevel ++;
                }
            }
        }
        printf(" %d", res);
        if(nextLevel == 0) break;
        level = nextLevel;
    }
    printf("\n");
    return 0;
}