class Solution {
public:
    bool isValidSerialization(string preorder) 
    {
        int n = preorder.size();
        stack<int> stk;
        stk.push(1);
        int i = 0;
        while (i < n)
        {
            if (stk.empty())
                return false;
            if (preorder[i] == ',')
                ++i;
            else if (preorder[i] == '#')
            {
                --stk.top();
                if (stk.top() == 0)
                    stk.pop();
                ++i;
            }
            else 
            {
                while (i < n && preorder[i] != ',')
                    ++i;
                --stk.top();
                if (stk.top() == 0)
                    stk.pop();
                stk.push(2);
            }
        }
        return stk.empty();
    }
};