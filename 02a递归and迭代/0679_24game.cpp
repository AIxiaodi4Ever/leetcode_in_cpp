class Solution {
public:
    static constexpr int TARGET = 24;
    static constexpr double EPSILON = 1e-6;
    // 没有左右括号是因为算法中的随机选择两个数字进行运算已经包含了左右括号在里面
    // 加法和乘法在前面是因为满足交换律便于优化
    static constexpr int ADD = 0, MULTIPLY = 1, SUBTRACT = 2, DIVEDE = 3;

    bool judgePoint24(vector<int>& nums) 
    {
        vector<double> dnums;
        for (const int& num : nums)
        {
            dnums.emplace_back(static_cast<double>(num));
        }
        return solve(dnums);
    }

    bool solve(vector<double> &dnums)
    {
        // 测试中这种情况不会发生，但题解中有下面的if语句
        /*if (dnums.size() == 0)
            return false;*/
        
        // 当只剩下一个数字是判断是否为24
        if (dnums.size() == 1)
            return fabs(dnums[0] - TARGET) < EPSILON;

        int size = dnums.size();
        // 都从0开始是因为10和01不一样
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                // 相同的数之间无法运算
                if (i != j)
                {
                    vector<double> dnums2{};
                    for (int k = 0; k < size; ++k)
                    {
                        if (k != i && k != j)
                            dnums2.emplace_back(dnums[k]);
                    }

                    // 这里是k < 4而不是k < size。。。
                    for (int k = 0; k < 4; ++k)
                    {
                        // 对交换律的优化
                        if ( k < 2 && i < j )
                            continue;

                        // 一次只能进行一个运算所以用if else if的形式
                        if (k == ADD)
                            dnums2.emplace_back(dnums[i] + dnums[j]);                 
                        else if (k == MULTIPLY)
                            dnums2.emplace_back(dnums[i] * dnums[j]);
                        else if (k == SUBTRACT)
                            dnums2.emplace_back(dnums[i] - dnums[j]);
                        else if (k == DIVEDE)
                        {
                            // 防止除以0，这里也要用绝对值
                            if (fabs(dnums[j]) < EPSILON)
                                continue;
                            dnums2.emplace_back(dnums[i] / dnums[j]);
                        }

                        // 先判断是否为真，再决定是否返回
                        // 为真的信息因此会一直返回到第一层递归
                        // 而为假的信息只会进行下一个运算符的计算或返回到上一层
                        if (solve(dnums2))
                            return true;
                        dnums2.pop_back();
                    }
                }
            }
        }
        return false;
    }
};
