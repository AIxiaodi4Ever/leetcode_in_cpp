class MedianFinder {
public:
    multiset<int> data;
    multiset<int>::iterator lo_median, hi_median;

    /** initialize your data structure here. */
    MedianFinder() : lo_median(data.end()), hi_median(data.end()) {}
    
    /* ������� */
    /* 1.����ʱmultisetΪ�� */
    /* 2.����ʱmultiset��Ԫ������Ϊ���� */
    /* 3.����ʱmultiset��Ԫ������Ϊż�� */
    void addNum(int num) {
        int n = data.size();
        data.insert(num);

        if (!n)
            lo_median = hi_median = data.begin();
        
        /***************************************************/
        /* ���������ͬԪ�أ��²����Ԫ�ز���������ͬԪ��֮�� */
        /***************************************************/

        /* ������Ԫ�أ���ָ��ָ����ͬԪ��                    */
        /* С����ֵ���С��һ��Ԫ�������ӣ����Խ�С��ָ������ */
        /* ������ֵͬ��                                     */
        else if (n & 1)  
        {   
            if (num < *lo_median)
                --lo_median;
            else
                ++hi_median;
        }
        /* ż����Ԫ�أ���ָ��ֱ�ָ����ֵ�н�С�ͽϴ��Ԫ��      */
        /* �����ֵ������֮�䣬���Ϊ�µ���ֵ����ָ��ָ����ͬ    */
        /* ����Ԫ�ش��ڽϴ��ߣ���ǰ�Ĵ�ֵ��Ϊ�µ���ֵ          */
        /* ������*lo_medianʱ����Ԫ�ز���lo_median֮��������  */
        /* lo_median = --hi_median���԰����������             */
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