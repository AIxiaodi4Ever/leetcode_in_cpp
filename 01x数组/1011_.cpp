class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left = *max_element(weights.begin(), weights.end()), right = accumulate(weights.begin(), weights.end(), 0);

         while (left < right) {
             int mid = left + (right - left) / 2;
             int need = 1, cur = 0;
             for (int& weight : weights) {
                if (cur + weight > mid) {
                    ++need;
                    cur = 0;
                }
                cur += weight;
                if (need > D) {
                    left = mid + 1;
                    break;
                }
             }
             if (need <= D) {
                 right = mid;
             }
         }
         return left;
    }
};