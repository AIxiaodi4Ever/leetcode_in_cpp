class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int sorted[m + n];
        int p1 = 0, p2 = 0;
        while (p1 < m || p2 < n) {
            if (p1 == m) {
                sorted[m + p2] = nums2[p2];
                ++p2;
            }
            else if (p2 == n) {
                sorted[n + p1] = nums1[p1];
                ++p1;
            }
            else if (nums1[p1] < nums2[p2]) {
                sorted[p1 + p2] = nums1[p1];
                ++p1;
            }
            else {
                sorted[p1 + p2] = nums2[p2];
                ++p2;
            }
        }

        for (int i = 0; i < m + n; ++i) {
            nums1[i] = sorted[i];
        }
    }
};