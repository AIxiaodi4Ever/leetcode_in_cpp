class Solution {
public:
    static constexpr char operations[4] = {'*', '/', '+', '-'};
    stack<int> nums;
    stack<char> ops;

    int cal()
    {
        int num2 = nums.top();
        nums.pop();
        int num1 = nums.top();
        nums.pop();
        char curOp = ops.top();
        ops.pop();
        switch(curOp) {
            case '*': return num1 * num2;
            case '/': return num1 / num2;
            case '+': return num1 + num2;
            case '-': return num1 - num2;
            default: break;
        }
        return 0;

    }

    int clumsy(int N) {
        unordered_map<char, int> pri;
        pri[')'] = 0;
        pri['+'] = pri['-'] = 1;
        pri['*'] = pri['/'] = 2;
        pri['('] = 3;

        int curOpIdx = 0;
        for (int i = N; i > 1; --i) {
            nums.push(i);
            char curOp = operations[curOpIdx];
            while (!ops.empty() && pri[ops.top()] >= pri[curOp]) {
                nums.push(cal());
            }
            ops.push(curOp);
            curOpIdx = (curOpIdx + 1) % 4;
        }

        nums.push(1);

        while (!ops.empty()) {
            nums.push(cal());
        }
        return nums.top();
    }
};