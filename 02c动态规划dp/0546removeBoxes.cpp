/*
Given several boxes with different colors represented by different positive numbers.
You may experience several rounds to remove boxes until there is no box left. Each 
time you can choose some continuous boxes with the same color (composed of k boxes, k >= 1), remove them and get k*k points.
Find the maximum points you can get.

Example 1:
Input: boxes = [1,3,2,2,2,3,4,3,1]
Output: 23
Explanation:
[1, 3, 2, 2, 2, 3, 4, 3, 1] 
----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
----> [1, 3, 3, 3, 1] (1*1=1 points) 
----> [1, 1] (3*3=9 points) 
----> [] (2*2=4 points)

Constraints:
    1 <= boxes.length <= 100
    1 <= boxes[i] <= 100

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/remove-boxes
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    int dp[100][100][100];
    int removeBoxes(vector<int>& boxes) 
    {
        memset(dp, 0, sizeof(dp));
        return calculatePoint(boxes, 0, boxes.size() - 1, 0);
    }

    int calculatePoint(vector<int>& boxes, int l, int r, int k)
    {
        if (l > r)
            return 0;
        if (dp[l][r][k])
            return dp[l][r][k];
        while (r > 0 && boxes[r] == boxes[r - 1])
        {
            --r;
            ++k;
        }
        dp[l][r][k] = calculatePoint(boxes, l, r - 1, 0) + (k + 1) * (k + 1);
        for (int i = l; i < r; ++i)
        {
            if (boxes[i] == boxes[r])
            {
                dp[l][r][k] = max(dp[l][r][k], calculatePoint(boxes, l, i, k + 1) + 
                calculatePoint(boxes, i + 1, r - 1, 0));
            }
        }
        return dp[l][r][k];
    }
};