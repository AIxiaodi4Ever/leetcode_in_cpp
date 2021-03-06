// ��ָoffer��09
/*
������ջʵ��һ�����С����е��������£���ʵ�������������� appendTail �� deleteHead��
�ֱ�����ڶ���β�������������ڶ���ͷ��ɾ�������Ĺ��ܡ�(��������û��Ԫ�أ�deleteHead �������� -1 )

ʾ�� 1��
���룺
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
�����[null,null,3,-1]

ʾ�� 2��
���룺
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
�����[null,-1,null,null,5,2]

��ʾ��
    1 <= values <= 10000
    ����� appendTail��deleteHead ���� 10000 �ε���

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

typedef struct {
    int *stack1;
    int *stack2;
    int top1;
    int top2;

} CQueue;


CQueue* cQueueCreate() {
    int len = 10000;
    // Ҫ�����ڴ档����
    CQueue *my_queue = (CQueue *)malloc(sizeof(CQueue));
    /*if (my_queue == NULL)
    {
        error("null pointer");
        exit(1);
    }*/
    my_queue->stack1 = (int *)malloc(sizeof(int) * len);
    my_queue->stack2 = (int *)malloc(sizeof(int) * len);
    /*if (my_queue->stack1 == NULL || my_queue->stack2 == NULL)
    {
        error("null pointer stack1 or stack2");
        exit(1);
    }*/
    my_queue->top1 = -1;
    my_queue->top2 = -1;
    return my_queue;
}

void cQueueAppendTail(CQueue* obj, int value) {
    obj->stack1[++obj->top1] = value;
}

int cQueueDeleteHead(CQueue* obj) {
    if (obj->top2 > -1)
    {
        return obj->stack2[obj->top2--];
    }
    else 
    {
        while (obj->top1 > -1)
        {
            obj->stack2[++obj->top2] = obj->stack1[obj->top1--];
        }

        if (obj->top2 < 0)
            return -1;
        else
            // ����ҲҪ���Լ�
            return obj->stack2[obj->top2--];
    }
}

void cQueueFree(CQueue* obj) {
    free(obj->stack1);
    free(obj->stack2);
    free(obj);
}

/**
 * Your CQueue struct will be instantiated and called as such:
 * CQueue* obj = cQueueCreate();
 * cQueueAppendTail(obj, value);
 
 * int param_2 = cQueueDeleteHead(obj);
 
 * cQueueFree(obj);
*/