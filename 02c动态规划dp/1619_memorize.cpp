class Solution {
public:
    // 尝试过简化dfs函数, 使其更好理解, 但最终发现还是像官方题解这样加一个-1来处理最为方便...
    bool check(const vector<int> &a, const vector<int> &b) {
        return a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        for (auto & v : cuboids) {
            sort(v.begin(), v.end());
        }
        sort(cuboids.begin(), cuboids.end(), [](const vector<int> & a, const vector<int> & b) {
            return a[0] + a[1] + a[2] < b[0] + b[1] + b[2];
        });

        /**
        * memo[i] store the height that maxmize (cuboids[i][2] + height) when cuboids[i] is on top of the stack.
        * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        * be aware that memo[i] NOT stores the direct maxHeight when cuboids[i] is on top of the stack. It stores (maxHeight - cuboids[i][2])
        * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        */
        vector<int> memo(n, -1);
        
        /**
        * @param top:       index of the top cuboid in cuboids.
        * @param topNext:   recursion start index. We recursively search from topNext to cuboids.size() to find the height that make 
        *                       (cuboids[top][2] + height) be the maximum height when cuboids[top] is on top of the stack
        * @return:          height that maxmize (cuboids[i][2] + height) when cuboids[top] in on top of the stack
        */
        function<int(int, int)> dfs = [&](int top, int topNext)->int {
            if (topNext == n) {
                return 0;
            }

            if (top != -1 && memo[top] != -1) {
                return memo[top];
            }

            // step1: search the range [topNext + 1, n)
            int height = dfs(top, topNext + 1);
            // step2: if cuboids[top] can be placed on top of cuboids[topNext], return the maximum height between the ans from step1 with the maximum height when cuboids[topNext] is 
            //        on top of the stack. the result value will be the height that maxmize '(cuboids[top][2] + height)' when cuboids[top] is on top of the stack......
            if (top == -1 || check(cuboids[top], cuboids[topNext])) {
                height = max(height, cuboids[topNext][2] + dfs(topNext, topNext + 1));
            }

            if (top != -1) {
                memo[top] = height;
            }

            return height;
        };

        // index -1 indicate that we put a cuboids with (0,0,0) size before cuboids[0].
        // we recursively search from 0 to cuboids.size() to find theHeight that makes 'cuboids[-1][2] + theHeight' be the maximum height when cuboids[-1] is on the top of the stack,
        // in this case, theHeight will be the maximum height of the problem.
        return dfs(-1, 0);
    }
};