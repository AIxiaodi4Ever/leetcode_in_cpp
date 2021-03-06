class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) noexcept
    {
        unordered_set<int> ns1, ns2;
        for (const auto &num : nums1)
            ns1.insert(num);
        for (const auto &num : nums2)
            ns2.insert(num);
        
        return getIntersection(ns1, ns2);
    }

    vector<int> getIntersection(unordered_set<int>& ns1, unordered_set<int>& ns2) noexcept
    {
        if (ns1.size() > ns2.size())
            return getIntersection(ns2, ns1);
        
        vector<int> ans;
        for (const auto& num : ns1)
        {
            if (ns2.count(num))
                ans.push_back(num);
        }
        return ans;
    }
};