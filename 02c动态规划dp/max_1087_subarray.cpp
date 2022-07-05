#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    string k = "18000770000007";

    int n = k.size();

    vector<vector<int>> dp(4, vector<int>(n + 1, 0));
    vector<vector<int>> vis(4, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; ++i) 
    {
        // dp1:
        if (k[i - 1] == '1')
        {
            dp[0][i] = dp[0][i - 1] + 1;
            vis[0][i] = 1; //第i位前出现过1
        }
        else
        {
            dp[0][i] = dp[0][i - 1];
            vis[0][i] = vis[0][i - 1];
        }

        //dp2:
        if(k[i - 1]=='8'&&vis[0][i-1]) { //如果前面一位出现过1
            dp[1][i]=max(dp[1][i-1]+1,dp[0][i-1]+1); //max(最后一个是8，或者最后多个8)
            vis[1][i]=1; //第i位前出现过18
        }
        else {
            dp[1][i]=dp[1][i-1];
            vis[1][i]=vis[1][i-1];
        }

        //dp3:
        if(k[i - 1]=='0'&&vis[1][i-1]) { //如果前面一位出现过18
            dp[2][i]=max(dp[2][i-1]+1,dp[1][i-1]+1); //max(最后一个是0，或者最后多个0)
            vis[2][i]=1; //第i位前出现过180
        }
        else {
            dp[2][i]=dp[2][i-1];
            vis[2][i]=vis[2][i-1];
        }

        //dp4:
        if(k[i - 1]=='7'&&vis[2][i-1]) { //如果前面一位出现过180
            dp[3][i]=max(dp[3][i-1]+1,dp[2][i-1]+1); //max(最后一个是7，或者最后多个7)
        }
        else {
            dp[3][i]=dp[3][i-1];
            vis[3][i]=vis[3][i-1];
        }
    }
    cout << dp[3][n] << endl;
    return 0;
}
