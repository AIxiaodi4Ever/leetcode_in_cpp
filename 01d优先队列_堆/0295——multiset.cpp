class MedianFinder {
public:
    multiset<int> data;
    multiset<int>::iterator lo_median, hi_median;

    /** initialize your data structure here. */
    MedianFinder() : lo_median(data.end()), hi_median(data.end()) {}
    
    /* 三种情况 */
    /* 1.插入时multiset为空 */
    /* 2.插入时multiset中元素数量为奇数 */
    /* 3.插入时multiset中元素数量为偶数 */
    void addNum(int num) {
        int n = data.size();
        data.insert(num);

        if (!n)
            lo_median = hi_median = data.begin();
        
        /***************************************************/
        /* 如果存在相同元素，新插入的元素插在所有相同元素之后 */
        /***************************************************/

        /* 奇数个元素，两指针指向相同元素                    */
        /* 小于中值则较小的一半元素数增加，所以较小的指针左移 */
        /* 大于中值同理                                     */
        else if (n & 1)  
        {   
            if (num < *lo_median)
                --lo_median;
            else
                ++hi_median;
        }
        /* 偶数个元素，两指针分别指向中值中较小和较大的元素      */
        /* 插入的值在两者之间，则成为新的中值，两指针指向相同    */
        /* 插入元素大于较大者，则当前的大值成为新的中值          */
        /* 当等于*lo_median时，新元素插在lo_median之后，所以令  */
        /* lo_median = --hi_median，以包含所有情况             */
        else     
        {
            if (num > *lo_median && num < *hi_median)
            {
                ++lo_median;
                --hi_median;
            }
            else if (num >= *hi_median)
                ++lo_median;
            else    // <= *lo_median
                lo_median = --hi_median;
        }
    }
    
    double findMedian() {
        return (*lo_median + *hi_median) * 0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */