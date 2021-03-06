/* �����������ÿ�β��붼��������״̬ */
class MedianFinder {
public:
    vector<int> store;
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        // lower_bound()����ָ��С��num�ĵ�һ��Ԫ�صĵ�����
        // insert�ڸ���������֮ǰ����Ԫ�أ�������ָ���һ������Ԫ�صĵ�����
        store.insert(lower_bound(store.begin(), store.end(), num), num);
    }
    
    double findMedian() {
        int n = store.size();
        return (n & 1 ? store[n / 2] : (store[n / 2 - 1] + store[n / 2]) * 0.5);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */