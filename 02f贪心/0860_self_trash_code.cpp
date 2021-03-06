class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> hands;
        hands[20] = 0;
        hands[10] = 0;
        hands[5] = 0;
        for (const int &bill : bills)
        {
            int change = bill - 5;
            if (change == 0)
            {
                hands[5] = hands[5] + 1;
                continue;
            }
            else if (change == 5)
            {
                if (hands[5] != 0)
                {
                    --hands[5];
                    ++hands[10];
                    continue;
                }
                else
                    return false;
            }
            else if (change == 15)
            {
                if (hands[10] != 0 && hands[5] >= 1)
                {
                        --hands[10];
                        --hands[5];
                        ++hands[20];
                        continue;
                }
                else if (hands[5] >= 3)
                {
                    hands[5] = hands[5] - 3;
                    ++hands[20];
                    continue;
                }
                else
                    return false;

            }
        }
        return true;
    }
};