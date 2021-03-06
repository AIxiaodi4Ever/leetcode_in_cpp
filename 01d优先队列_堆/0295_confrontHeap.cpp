// ������
class MedianFinder {
public:
    // �󶥶ѵ�Ԫ��������С������ͬ���С���Ѷ�1
    priority_queue<int> lo; // ά��һ���СԪ�صĴ󶥶�
    priority_queue<int, vector<int>, greater<int>> hi;    // ά�ֽϴ�һ��Ԫ�ص�С����

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
        // ����2������һλ���ܻᷢ���ض�
        return (lo.size() == hi.size() ? (lo.top() + hi.top()) * 0.5 : lo.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */