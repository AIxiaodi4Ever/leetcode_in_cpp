struct SegNode
{
    int lo, hi, add;
    SegNode *lchild, *rchild;
    SegNode(int left, int right) : lo(left), hi(right), add(0), lchild(nullptr), rchild(nullptr) {}
};

class Solution {
public:
    SegNode* build(int left, int right)
    {
        SegNode* node = new SegNode(left, right);
        if (left == right)
            return node;
        int mid = left + (right - left) / 2;
        node->lchild = build(left, mid);
        node->rchild = build(mid + 1, right);
        return node; 
    }

    void insert(SegNode *root, int val)
    {
        root->add++;
        if (root->lo == root->hi)   
            return;
        int mid = root->lo + (root->hi - root->lo) / 2;
        if (val <= mid)
            insert(root->lchild, val);
        else
            insert(root->rchild, val);
    }

    int count(SegNode* root, int left, int right) const
    {
        if (left > root->hi || right < root->lo)
            return 0;
        if (left <= root->lo && right >= root->hi)
            return root->add;
        return count(root->lchild, left, right) + count(root->rchild, left, right);
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) 
    {
        long long sum = 0;
        vector<long long> presum{0};
        for (const int& v : nums)
        {
            sum += v;
            presum.push_back(sum);
        }

        set<long long> allNumbers;
        for (long long x : presum)
        {
            allNumbers.insert(x);
            allNumbers.insert(x - upper);
            allNumbers.insert(x - lower);
        }

        // hash¿Î…¢
        unordered_map<long long, int> values;
        int idx = 0;
        for (long long x : allNumbers)
        {
            values[x] = idx;
            ++idx;
        }

        SegNode* root = build(0, values.size() - 1);
        int ret = 0;
        for (long long x : presum)
        {
            int left = values[x - upper], right = values[x - lower];
            ret += count(root, left, right);
            insert(root, values[x]);
        }
        return ret;
    }
};