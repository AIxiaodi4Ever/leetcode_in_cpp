class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> factors = {2, 3, 5};
        priority_queue<long, vector<long>, greater<long>> heap;
        unordered_set<long> seen;

        int ans = 0;
        seen.insert(1L);
        heap.push(1L);
        for (int i = 0; i < n; ++i) {
            long curr = heap.top();
            heap.pop();
            ans = (int)curr;
            for (int factor : factors) {
                long next = curr * factor;
                if (!seen.count(next)) {
                    heap.push(next);
                    seen.insert(next);
                } 
            }
        }
        return ans;
    }
};