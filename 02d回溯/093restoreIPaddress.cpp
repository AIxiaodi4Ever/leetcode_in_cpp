/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.
A valid IP address consists of exactly four integers (each integer is between 0 and 255) separated by single points.

Example:
Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/restore-ip-addresses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
private:
    static constexpr int SEG_COUNT = 4;
    vector<string> ans;
    vector<int> segments;
public:
    void dfs(const string& s, int segId, int segStart)
    {
        // 如果找到了4段IP地址，且遍历完了字符串，则将IP地址压入ans
        if (segId == SEG_COUNT)
        {
            if (segStart == s.size())
            {
                string temp;
                for (int i = 0; i < SEG_COUNT; ++i)
                {
                    temp += to_string(segments[i]);
                    if (i != SEG_COUNT - 1)
                    {
                        temp += ".";
                    }
                }
                ans.push_back(temp);
            }
            // return必须在这，包含压入和不压入两种情况
            return;
        }

        // 如果没找到4段IP就遍历完了字符串，提前回溯
        /*if (segStart == s.size())
            return;*/

        // 如果前置位为0，则该段IP只能是0
        if (s[segStart] == '0')
        {
            segments[segId] = 0;
            dfs(s, segId + 1, segStart + 1);
        }

        // 一般情况，遍历所有可能的IP
        int addr = 0;
        for (int segEnd = segStart; segEnd < s.size(); ++segEnd)
        {
            addr = addr * 10 + s[segEnd] - '0';
            if (addr > 0 && addr <= 0xFF)
            {
                segments[segId] = addr;
                if (segId < SEG_COUNT - 1 && segEnd == s.size() - 1)
                    return;
                dfs(s, segId + 1, segEnd + 1);
            }
            else
                break;
        }
    }

    vector<string> restoreIpAddresses(string s) 
    {
        segments.resize(SEG_COUNT);
        dfs(s, 0, 0);
        return ans;
    }
};