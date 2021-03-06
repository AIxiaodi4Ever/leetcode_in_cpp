/*************************************************************************************************/
/* 包含延迟删除的对顶推模板                                                                       */
/*                                           变量成员说明                                        */
/* small保存所有输入中较小的一半，large保存所有输入中较大的一半. 小顶堆的大小比大顶堆多一或与之相同   */
/* smallSize,largeSize分别保存二者大小                                                            */
/* delayed是一个hash表，key值为被标记为删除的元素，value是该元素应该被删除的次数                    */
/* k值为滑动窗口的大小，非常量，可以随着输入的增加而增加，k = smallSize + largeSize                 */
/*                                           函数成员说明                                        */
/* prune(): 当被标记为删除的元素上滤到堆顶时弹出该元素，直到堆顶元素不是被标记删除的为止，            */
/*          并改变delayed中对应的value值.                                                         */
/* makeBalance(): 插入元素或删除元素后，重新平衡两堆的大小关系.                                     */
/* insert(num): 插入元素，注意插入元素后两堆的大小关系可能不满足条件，但两堆顶一定不是被标记删除的.   */
/* erase(num): 删除元素，增加delayed中对应的value值，如果该元素位于堆顶，调用prune弹出.             */
/* getMedian()：得到当前两堆保存所有数据的中位数                                                   */
/* 注：以上所有的操作都保证了操作结束后堆顶元素不是被标记为删除的，这样做的好处是不用修改getMedian()  */
/* ，只需要略微修改insert(num)即可                                                                */
/*************************************************************************************************/
class DualHeap {
private:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
    unordered_map<int, int> delayed;
    int k;
    int smallSize, largerSize;

public:
    DualHeap(int _k) : k(_k), smallSize(0), largerSize(0) {}

private:
    /* 并不会出现delayed里的数大于heap的情况，因为首先保证了堆顶元素不是被标记删除的，所以被标记删除的元素一定位于某个堆的非堆顶元素，当makebalance调整堆顶元素时，被标记删除的元素才有可能到堆顶，而它的数量一定小于等于次数堆的大小 */
    template<typename T>
    void prune(T& heap)
    {
        while (!heap.empty())
        {
            int num = heap.top();
            //官方代码
            /*if (delayed.count(num))
            {
                --delayed[num];
                heap.pop();
                if (!delayed[num])
                    delayed.erase(num);
            }*/
            if (delayed[num])
            {
                --delayed[num];
                heap.pop();
            }
            else    
                break;
        }
    }

    void makeBalance() 
    {
        if (smallSize > largerSize + 1)
        {
            large.push(small.top());
            small.pop();
            --smallSize;
            ++largerSize;
            prune(small);
        }
        else if (smallSize < largerSize)
        {
            small.push(large.top());
            large.pop();
            ++smallSize;
            --largerSize;
            prune(large);
        }
    }

public:
    void insert(int num)
    {
        if (small.empty() || num <= small.top())
        {
            small.push(num);
            ++smallSize;
        }
        else
        {
            large.push(num);
            ++largerSize;
        }
        makeBalance();
    }

    void erase(int num)
    {
        ++delayed[num];
        if (num <= small.top())
        {
            --smallSize;
            if (num == small.top())
                prune(small);
        }
        else
        {
            --largerSize;
            if (num == large.top())
                prune(large);
        }
        makeBalance();
    }

    double getMedian()
    {
        // 不转化成double可能会溢出
        return k & 1 ? small.top() : ((double)small.top() + large.top()) / 2;
    }   
};