class Solution {
public:
    int countRangeSumRecursive(vector<long>& presums, int left, int right, int lower, int upper)
    {
        // �ݹ���ֹ����
        if (left == right)
            return 0;
        // �ݹ�
        int mid = left + (right - left) / 2;
        int ret = 0;
        int n1 = countRangeSumRecursive(presums, left, mid, lower, upper);
        int n2 = countRangeSumRecursive(presums, mid + 1, right, lower, upper);
        ret = n1 + n2;

        // ����ò�������������ǰ׺��
        int l = mid + 1, r = mid + 1;
        int i = left;
        while (i <= mid)
        {
            while (l <= right && presums[l] - presums[i] < lower)
                ++l;
            while (r <= right && presums[r] - presums[i] <= upper)  // �����д��--r
                ++r;
            ret += (r - l);
            ++i;    // ��������д++i
        }

        // �鲢����ϲ���������
        vector<int> temp(right - left + 1);
        int p1 = left, p2 = mid + 1;
        int p = 0;
        while (p1 <= mid || p2 <= right)
        {
            if (p1 > mid)
                temp[p++] = presums[p2++];
            else if (p2 > right)
                temp[p++] = presums[p1++];
            else
            {
                if (presums[p1] < presums[p2])
                    temp[p++] = presums[p1++];
                else
                    temp[p++] = presums[p2++];
            }
        }

        for (int idx = 0; idx < right - left + 1; ++idx)
            presums[left + idx] = temp[idx];

        return ret; 
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) 
    {
        vector<long> presums{0};
        long s = 0;
        for (const int& num : nums)
        {
            s += num;
            presums.push_back(s);
        }
        return countRangeSumRecursive(presums, 0, nums.size(), lower, upper);
    }
};