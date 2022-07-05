// 类似于之前做过的身份证求最后一位的题(NE)
// 对于9进制字符串的这种处理其实是一个hash函数，冲突的概率很小，因此陷入循环的大概率是同一个数？
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回最终的个位数
     * @param num string字符串 初始九进制正整数
     * @return int整型
     */
    int mulDigits(string num) {
        if (num.size() == 1) {
            return num[0] - '0';
        }
        // write code here
        int cur = 1;
        string s = num;
        do {
            cur = 1;
            int n = s.size();
            for (int i = 0; i < n; ++i) {
                cur *= (s[i] - '0' + 1);
            }
            if (cur < 9) 
                break;
            else {
                int tmp = cur;
                string ss = s;
                s = "";
                while (tmp != 0) {
                    int lastBit = tmp % 9;
                    char lb = '0' + lastBit;
                    s  = lb + s;
                    tmp /= 9;
                }
                if (s == num || s == ss) {
                    cur = -1;
                    break;
                }
            }
        } while (cur >= 9);
        return cur;
    }
};