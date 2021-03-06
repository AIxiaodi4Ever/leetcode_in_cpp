class MedianFinder {
public:
    multiset<int> data;
    multiset<int>::iterator mid;

    /** initialize your data structure here. */
    MedianFinder() : mid(data.end()) {}
    
    /* prev和next都是泛型算法，用法如函数名 */
    /* mid永远指向中值中较大的那个，如果是奇数个元素，则指向中值 */
    void addNum(int num) 
    {
        int n = data.size();
        data.insert(num);

        if (!n)
            mid = data.begin();
        else if (num < *mid)
            mid = n & 1 ? mid : prev(mid);
        else
            mid = n & 1 ? next(mid) : mid;

    }
    
    double findMedian() 
    {
        int n = data.size();
        return (*mid + *next(mid, n % 2 - 1)) * 0.5;    // 如果是偶数则后-1个，即前一个
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */