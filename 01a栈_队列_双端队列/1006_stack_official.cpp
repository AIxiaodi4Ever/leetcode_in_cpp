class Solution {
public:
    int clumsy(int N) {
        stack<int> nums;
        nums.push(N);
        --N;
        int idx = 0;

        while (N > 0) {
            switch (idx % 4) {
                case 0: 
                    nums.top() *= N;
                    break;
                case 1:
                    nums.top() /= N;
                    break;
                case 2:
                    nums.push(N);
                    break;
                case 3:
                    nums.push(-N);
                    break;
                default:
                    break;
            }
            --N;
            ++idx;
        }

        int sum = 0;
        while (!nums.empty()) {
            sum += nums.top();
            nums.pop();
        }

        return sum;
    }
};