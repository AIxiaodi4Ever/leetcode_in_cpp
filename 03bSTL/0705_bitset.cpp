// 一开始用的vector，，评论有人说bitset，对这题来说确实可以，，跟计算hash的官方时间空间差不多
class MyHashSet {
public:
    bitset<1000001> hSet;
    /** Initialize your data structure here. */
    MyHashSet() {  }
    
    void add(int key) {
        hSet.set(key);
    }
    
    void remove(int key) {
        hSet.reset(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return hSet.test(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */