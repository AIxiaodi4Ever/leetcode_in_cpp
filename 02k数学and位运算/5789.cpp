class Solution {
public:
    pair<int, int> get_hour_and_minute(string s) {
        int hour = stoi(s.substr(0, 2));
        int minute = stoi(s.substr(3, 2));
        return {hour, minute};
    }

    int numberOfRounds(string startTime, string finishTime) {
        auto [startHH, startMM] = get_hour_and_minute(startTime);
        auto [endHH, endMM] = get_hour_and_minute(finishTime);

        // ......原来可以直接比的。。。
        if (startTime > finishTime) {
            endHH += 24;
        }
        // 这个计算方法确实没先到
        // 还是对题解优化了一下，题解将结束时间设定在endHH+1时，最后减去需要补充分钟造成的多次计算
        // 先考虑小时数计算的游戏次数
        // 再减去开始分钟错过的游戏次数
        // 再加上结束分钟
        return (endHH - startHH) * 4 - (startMM + 14) / 15 + (endMM) / 15;
    }
};