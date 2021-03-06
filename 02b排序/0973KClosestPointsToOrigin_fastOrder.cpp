class Solution {
public:
    void random_select(vector<vector<int>>& points, int left, int right, int K)
    {
        int pivot_id = uniform_int_distribution<int>{left, right}(gen);
        int pivot = points[pivot_id][0] * points[pivot_id][0] + points[pivot_id][1] * points[pivot_id][1];
        swap(points[pivot_id], points[right]);
        int i = left - 1;
        for (int j = left; j < right; ++j)
        {
            int dist = points[j][0] * points[j][0] + points[j][1] * points[j][1];
            if (dist <= pivot)
            {
                ++i;
                swap(points[i], points[j]);
            }
        }
        // 不小心把下面的写在了循环内
        ++i;
        swap(points[i], points[right]);
        if (K < i - left + 1)
            random_select(points, left, i, K);
        else if (K > i - left + 1)
            random_select(points, i + 1, right, K - (i - left + 1));
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) 
    {
        random_select(points, 0, points.size() - 1, K);
        return {points.begin(), points.begin() + K};
    }
private:
    mt19937 gen{random_device{}()};
};