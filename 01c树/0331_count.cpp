class Solution {
public:
    bool isValidSerialization(string preorder) 
    {
        int n = preorder.size();
        int slots = 1;
        int i = 0;
        while (i < n)
        {
            if (slots == 0)
                return false;
            if (preorder[i] == ',')
                ++i;
            else if (preorder[i] == '#')
            {
                --slots;
                ++i;
            }
            else 
            {
                // read a number
                while (i < n && preorder[i] != ',')
                    ++i;
                ++slots;
            }
        }
        return slots == 0;
    }
};