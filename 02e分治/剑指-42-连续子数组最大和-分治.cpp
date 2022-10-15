class Solution {
public:
    struct Status{
        int lSum;
        int rSum;
        int mSum;
        int iSum;
    };

    Status getStatus(vector<int>& nums, int left, int right) {
        if (left == right) {
            return Status{nums[left], nums[left], nums[left], nums[left]};
        }
        
        int mid = (left + right) >> 1;
        Status leftStatus = getStatus(nums, left, mid);
        Status rightStatus = getStatus(nums, mid + 1, right);

        Status myStatus;
        myStatus.iSum = leftStatus.iSum + rightStatus.iSum;
        myStatus.lSum = max(leftStatus.lSum, leftStatus.iSum + rightStatus.lSum);
        myStatus.rSum = max(rightStatus.rSum, rightStatus.iSum + leftStatus.rSum);
        myStatus.mSum = max(max(leftStatus.mSum, rightStatus.mSum), leftStatus.rSum + rightStatus.lSum);

        return myStatus;
    }

    int maxSubArray(vector<int>& nums) {
        Status fullArrayStatus = getStatus(nums, 0, nums.size() - 1);
        return fullArrayStatus.mSum;
    }
};