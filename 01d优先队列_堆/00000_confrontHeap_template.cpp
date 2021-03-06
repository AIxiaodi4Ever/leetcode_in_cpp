/*************************************************************************************************/
/* �����ӳ�ɾ���ĶԶ���ģ��                                                                       */
/*                                           ������Ա˵��                                        */
/* small�������������н�С��һ�룬large�������������нϴ��һ��. С���ѵĴ�С�ȴ󶥶Ѷ�һ����֮��ͬ   */
/* smallSize,largeSize�ֱ𱣴���ߴ�С                                                            */
/* delayed��һ��hash��keyֵΪ�����Ϊɾ����Ԫ�أ�value�Ǹ�Ԫ��Ӧ�ñ�ɾ���Ĵ���                    */
/* kֵΪ�������ڵĴ�С���ǳ���������������������Ӷ����ӣ�k = smallSize + largeSize                 */
/*                                           ������Ա˵��                                        */
/* prune(): �������Ϊɾ����Ԫ�����˵��Ѷ�ʱ������Ԫ�أ�ֱ���Ѷ�Ԫ�ز��Ǳ����ɾ����Ϊֹ��            */
/*          ���ı�delayed�ж�Ӧ��valueֵ.                                                         */
/* makeBalance(): ����Ԫ�ػ�ɾ��Ԫ�غ�����ƽ�����ѵĴ�С��ϵ.                                     */
/* insert(num): ����Ԫ�أ�ע�����Ԫ�غ����ѵĴ�С��ϵ���ܲ����������������Ѷ�һ�����Ǳ����ɾ����.   */
/* erase(num): ɾ��Ԫ�أ�����delayed�ж�Ӧ��valueֵ�������Ԫ��λ�ڶѶ�������prune����.             */
/* getMedian()���õ���ǰ���ѱ����������ݵ���λ��                                                   */
/* ע���������еĲ�������֤�˲���������Ѷ�Ԫ�ز��Ǳ����Ϊɾ���ģ��������ĺô��ǲ����޸�getMedian()  */
/* ��ֻ��Ҫ��΢�޸�insert(num)����                                                                */
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
    /* ���������delayed���������heap���������Ϊ���ȱ�֤�˶Ѷ�Ԫ�ز��Ǳ����ɾ���ģ����Ա����ɾ����Ԫ��һ��λ��ĳ���ѵķǶѶ�Ԫ�أ���makebalance�����Ѷ�Ԫ��ʱ�������ɾ����Ԫ�ز��п��ܵ��Ѷ�������������һ��С�ڵ��ڴ����ѵĴ�С */
    template<typename T>
    void prune(T& heap)
    {
        while (!heap.empty())
        {
            int num = heap.top();
            //�ٷ�����
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
        // ��ת����double���ܻ����
        return k & 1 ? small.top() : ((double)small.top() + large.top()) / 2;
    }   
};