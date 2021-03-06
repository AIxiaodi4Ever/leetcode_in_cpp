class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) noexcept
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
    
        vector<int> ans;
        int len1 = nums1.size(), len2 = nums2.size();
        int i = 0, j = 0;
        while (i < len1 && j < len2)
        {
            int ele1 = nums1[i], ele2 = nums2[j];
            if (ele1 == ele2)
            {
                if (ans.empty() || ele1 != ans.back())
                    ans.push_back(ele1);
                ++i;
                ++j;
            }
            else if (ele1 < ele2)
                ++i;
            else
                ++j;
        }
        return ans;
    }
};