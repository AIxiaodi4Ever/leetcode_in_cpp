class BIT
{
private:
    vector<int> tree;
    int n;
public:
    BIT(int _n) : n(_n), tree(_n + 1) {}

    static constexpr int lowbit(int x) 
    {
        return x & (~x + 1);
    }

    void update(int x, int d)
    {
        while (x <= n)
        {
            tree[x] += d;
            x += lowbit(x);
        }
    }

    int query(int x)
    {
        int ret = 0;
        while (x)
        {
            ret += tree[x];
            x -= lowbit(x);
        }
        return ret;
    }
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) 
    {
        long long sum = 0;
        vector<long long> Presums{0};
        for (const int &v : nums)
        {
            sum += v;
            Presums.push_back(sum);
        }

        set<long long> allNumbers;
        for (long long x : Presums)
        {
            allNumbers.insert(x);
            allNumbers.insert(x - lower);
            allNumbers.insert(x - upper);
        }
        // ���ù�ϣ�������ɢ��
        unordered_map<long long, int> values;
        int idx = 0;
        for (const long long x : allNumbers)
        {
            values[x] = idx;
            ++idx;
        }

        int ret = 0;
        BIT bit(values.size());
        for (long long _presum : Presums)
        {
            int left = values[_presum - upper], right = values[_presum - lower];
            // update�����1��ʼ����Ϊ��״�����update���������1��ʼ(����idx��1��ʼ)
            // ���Խ���right + 1��left��������right��left-1
            ret += bit.query(right + 1) - bit.query(left);
            bit.update(values[_presum] + 1, 1);
        }
        return ret;
    }
};