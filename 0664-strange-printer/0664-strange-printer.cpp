// fore korum bal

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        int dp[n][n];
        for(int i = n -1; i>=0; --i){
            for(int j = 0; j<n; ++j){
                if(i == j) dp[i][j] = 1;
                else if(i > j) dp[i][j] = 0;
                else{
                    int ans = 1e9;
                    for(int k = i; k<j; ++k){
                        int t = dp[i][k] + dp[k + 1][j];
                        ans = min(ans, t);
                    }
                    if(s[i] == s[j]) --ans;
                    dp[i][j] = ans;  
                }
            }
        }
        return dp[0][n - 1];
    }
};