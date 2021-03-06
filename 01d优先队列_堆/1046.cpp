class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        priority_queue<int> SmashedStone;
        for (auto val : stones)
            SmashedStone.push(val);
        while (SmashedStone.size() > 1)
        {
            int sone = SmashedStone.top();
            SmashedStone.pop();
            int stwo = SmashedStone.top();
            SmashedStone.pop();
            // 大顶堆一定大于等于
            if (sone > stwo)
                SmashedStone.push(sone - stwo);
        }
        return SmashedStone.empty() ? 0 : SmashedStone.top();
    }
};