/*
#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
*/


// ����˼·:ʹ�����ÿ���������void qsort(void *base, int nelem, unsigned int width, int ( * pfCompare)( const void *, const void *));
// ��**events���ս���ʱ���С��������qsort��Ӧ�Ĳ����ֱ�Ϊ���������������ʼ��ַ������Ԫ�ظ�����ÿ��Ԫ�ش�С��ָ��ȽϺ����ĺ���ָ��
// �ȽϺ����У���p1Ӧ����p2ǰ�棬�򷵻ظ�ֵ��������ֵ�����ⷵ��0�����޸ķ���ֵ���������������
// ����һ������attended[100001]��¼��Ӧ�ĵ����Ƿ�μ��˻��飬0Ϊδ�μӣ�1Ϊ�μӡ�����enent_num��¼�μӵĻ�����
// �ӽ���ʱ������Ļ��鿪ʼ�������û��鿪ʼʱ�䵽����ʱ���ÿһ�죬�������һ��û�μӻ��飬�����Ӧ��attendedΪ1��event_num+1
// ��󷵻�event_num��Ϊ��
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

