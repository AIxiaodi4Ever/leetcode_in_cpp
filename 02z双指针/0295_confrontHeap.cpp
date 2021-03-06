// 两个堆
class MedianFinder {
public:
    // 大顶堆的元素数量和小顶堆相同或比小顶堆多1
    priority_queue<int> lo; // 维持一般较小元素的大顶堆
    priority_queue<int, vector<int>, greater<int>> hi;    // 维持较大一半元素的小顶堆

    /** initialize your data structure here. */
    MedianFinder() {}
    
    void addNum(int num) {
        lo.push(num);

        hi.push(lo.top());
        lo.pop();

        if (lo.size() < hi.size())
        {
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian() {
        // 除以2或右移一位可能会发生截断
        return (lo.size() == hi.size() ? (lo.top() + hi.top()) * 0.5 : lo.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */