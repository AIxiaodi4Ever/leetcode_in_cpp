class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> quadruplets;
        if (nums.size() < 4)
            return quadruplets;
        sort(nums.begin(), nums.end());
        int length = nums.size();
        // 外层循环
        for (int i = 0; i < length - 3; ++i)
        {
            // 避免重复
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            // 两个剪枝
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break;
            if (nums[i] + nums[length - 1] + nums[length - 2] + nums[length - 3] < target)
                continue;

            // 内层循环
            for (int j = i + 1; j < length - 2; ++j)
            {
                // avoid duplication
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                // two pruning
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                    break;
                if (nums[i] + nums[j] + nums[length - 1] + nums[length - 2] < target)
                    continue;
                
                int left = j + 1, right = length - 1;
                // two pointer
                while (left < right)
                {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target)
                    {
                        quadruplets.push_back({nums[i], nums[j], nums[left], nums[right]});
                        // 避免重复，因为只剩下两个数，相等则一定会重复
                        while (left < right && nums[left] == nums[left + 1])
                            ++left;
                        while (left < right && nums[right] == nums[right - 1])
                            --right;
                        ++left;
                        // -- wrong write to ++
                        --right;
                    }
                    else if (sum < target)
                        ++left;
                    else
                        --right;
                } // two pointer 
            } //j
        } //i
        return quadruplets;
    }
};