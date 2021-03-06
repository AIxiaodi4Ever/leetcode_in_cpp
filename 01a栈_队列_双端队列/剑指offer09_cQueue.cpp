// 剑指offer：09
/*
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead，
分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

示例 1：
输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]

示例 2：
输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]

提示：
    1 <= values <= 10000
    最多会对 appendTail、deleteHead 进行 10000 次调用

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

typedef struct {
    int *stack1;
    int *stack2;
    int top1;
    int top2;

} CQueue;


CQueue* cQueueCreate() {
    int len = 10000;
    // 要分配内存。。。
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
            // 这里也要有自减
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