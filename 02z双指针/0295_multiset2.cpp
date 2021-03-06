class MedianFinder {
public:
    multiset<int> data;
    multiset<int>::iterator mid;

    /** initialize your data structure here. */
    MedianFinder() : mid(data.end()) {}
    
    /* prev��next���Ƿ����㷨���÷��纯���� */
    /* mid��Զָ����ֵ�нϴ���Ǹ��������������Ԫ�أ���ָ����ֵ */
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
        return (*mid + *next(mid, n % 2 - 1)) * 0.5;    // �����ż�����-1������ǰһ��
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */