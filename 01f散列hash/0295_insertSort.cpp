/* 插入排序可以每次插入都保持排序状态 */
class MedianFinder {
public:
    vector<int> store;
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        // lower_bound()返回指向不小于num的第一个元素的迭代器
        // insert在给定迭代器之前插入元素，并返回指向第一个插入元素的迭代器
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