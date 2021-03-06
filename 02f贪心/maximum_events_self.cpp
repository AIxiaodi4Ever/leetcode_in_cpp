/*
#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
*/


// 解题思路:使用内置快速排序函数void qsort(void *base, int nelem, unsigned int width, int ( * pfCompare)( const void *, const void *));
// 将**events按照结束时间从小到大排序，qsort对应的参数分别为，待排序数组的起始地址，数组元素个数，每个元素大小，指向比较函数的函数指针
// 比较函数中，若p1应排在p2前面，则返回负值，后面正值，任意返回0，可修改返回值觉得正序或倒序排列
// 声明一个数组attended[100001]记录对应的当天是否参加了会议，0为未参加，1为参加。声明enent_num记录参加的会议数
// 从结束时间最早的会议开始，遍历该会议开始时间到结束时间的每一天，如果存在一天没参加会议，则令对应的attended为1，event_num+1
// 最后返回event_num即为解
int compare(void *p1, void *p2)
{
    int *eve1 = *(int **)p1;
    int *eve2 = *(int **)p2;

    return eve1[1] - eve2[1];
}

int maxEvents(int** events, int eventsSize, int* eventsColSize)
{
    int attended[100001] = {0};
    int event_num = 0;
    //memset(attended, 0, sizeof(attended));

    qsort(events, eventsSize, sizeof(int) * (*eventsColSize), compare);

    for (int i = 0; i < eventsSize; i++)
    {
        for (int j = events[i][0]; j <= events[i][1]; j++)
        {
            if (attended[j])
            {
                continue;
            }
            else
            {
                attended[j] = 1;
                event_num++;
                break;
            }
        }
    }
    return event_num;
}

