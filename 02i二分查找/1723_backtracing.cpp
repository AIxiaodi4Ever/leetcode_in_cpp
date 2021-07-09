class Solution {
public:
    bool backtracing(vector<int>& jobs, vector<int>& workerloads, int idx, int limit) {
        if (idx >= jobs.size()) {
            return true;
        }

        int cur = jobs[idx];
        for (int& workerload : workerloads) {
            workerload += cur;
            if (workerload <= limit) {
                if (backtracing(jobs, workerloads, idx + 1, limit)) {
                    return true;
                }
            }
            workerload -= cur;
            // 如果无法为当前工人分配工作，或者当前工人正好达到limit且回溯失败
            // 那由于对称性，无需枚举下一位工人
            if (workerload == 0 || workerload + cur == limit) {
                break;
            }
        }
        return false;
    }

    bool check(vector<int>& jobs, int k, int limit) {
        vector<int> workerloads(k, 0);
        return backtracing(jobs, workerloads, 0, limit);
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.begin(), jobs.end(), greater<int>());
        int l = jobs[0], r = accumulate(jobs.begin(), jobs.end(), 0);
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (check(jobs, k, mid)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
};