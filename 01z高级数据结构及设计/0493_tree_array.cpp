class BIT{
private:
    vector<int> tree;
    int n;
public:
    BIT(int _n) : tree(_n + 1), n(_n) {}

    static constexpr int lowbit(int x)
    {
        return x &(~x + 1);
    }

    void updata(int x, int d)
    {   
        while (x <= n)
        {
            tree[x] += d;
            x += lowbit(x);
        }
    }

    int query(int x) const
    {
        int ans;
        // x不能等于0，不能用>=0作为条件
        while (x)
        {
            ans += tree[x];
            x -= lowbit(x);
        }
        return ans;
    }
};

class Solution {
public:
    int reversePairs(vector<int>& nums) 
    {
        set<long long> allNumbers;
        for (const int &number : nums)
        {
            allNumbers.insert(number);
            allNumbers.insert(2 * (long long)number);
        }
        unordered_map<long long, int> values;
        int idx = 0;
        for (long long x : allNumbers)
        {
            values[x] = ++idx;
        }
        int ret = 0;
        BIT bit(values.size());
        for (const int &number : nums)
        {
            int left = values[2 * (long long)number], right = values.size();
            ret += bit.query(right) - bit.query(left);
            bit.updata(values[number], 1);
        }
        return ret;
    }
};