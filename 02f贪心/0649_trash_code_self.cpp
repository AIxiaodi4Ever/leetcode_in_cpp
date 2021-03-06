class Solution {
public:
    string predictPartyVictory(string senate) {
        int rNum = 0, dNum = 0;
        for (const char &c : senate)
        {
            if (c == 'R')
                ++rNum;
            else
                ++dNum;
        }
        int length = senate.length();
        while (1)
        {
            for (int i = 0; i < length; ++i)
            {   if (dNum == 0)
                    return "Radiant";
                if (rNum == 0)
                    return "Dire";
                if (senate[i] == 'R')
                {
                    bool found = false;
                    for (int j = i + 1; j < length; ++j)
                    {
                        if (senate[j] == 'D')
                        {
                            senate[j] = 'B';
                            --dNum;
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                    {
                        for (int j = 0; j < i + 1; ++j)
                        {
                            if (senate[j] == 'D')
                            {
                                senate[j] = 'B';
                                --dNum;
                                found = true;
                                break;
                            }
                        }
                    }
                }
                else if (senate[i] == 'D')
                {
                    bool found = false;
                    for (int j = i + 1; j < length; ++j)
                    {
                        if (senate[j] == 'R')
                        {
                            senate[j] = 'B';
                            --rNum;
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                    {
                        for (int j = 0; j < i + 1; ++j)
                        {
                            if (senate[j] == 'R')
                            {
                                senate[j] = 'B';
                                --rNum;
                                found = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
};