/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.
A valid IP address consists of exactly four integers (each integer is between 0 and 255) separated by single points.

Example:
Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/restore-ip-addresses
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
private:
    static constexpr int SEG_COUNT = 4;
    vector<string> ans;
    vector<int> segments;
public:
    void dfs(const string& s, int segId, int segStart)
    {
        // ����ҵ���4��IP��ַ���ұ��������ַ�������IP��ַѹ��ans
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
            // return�������⣬����ѹ��Ͳ�ѹ���������
            return;
        }

        // ���û�ҵ�4��IP�ͱ��������ַ�������ǰ����
        /*if (segStart == s.size())
            return;*/

        // ���ǰ��λΪ0����ö�IPֻ����0
        if (s[segStart] == '0')
        {
            segments[segId] = 0;
            dfs(s, segId + 1, segStart + 1);
        }

        // һ��������������п��ܵ�IP
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