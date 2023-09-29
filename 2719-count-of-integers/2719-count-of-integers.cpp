class Solution {
public:
    int dp[23][2][430], M = 1e9 + 7;

    int helper(int pos, int tight, int sum, string& s, int& min_sum, int& max_sum) {
        if(pos == s.size()) {
            return min_sum <= sum && sum <= max_sum;
        }
        if(dp[pos][tight][sum] != -1) {
            return dp[pos][tight][sum];
        }

        int res = 0;
        if(tight == 1) {
            for (int i = 0; i <= s[pos] - '0'; i++)
            {
                if(i == s[pos] - '0') {
                    res = (res + helper(pos + 1, 1, sum + i, s, min_sum, max_sum)) % M;
                }
                else {
                    res = (res + helper(pos + 1, 0, sum + i, s, min_sum, max_sum)) % M;
                }
            }
        }
        else {
            for (int i = 0; i <= 9; i++)
            {
                res = (res + helper(pos + 1, 0, sum + i, s, min_sum, max_sum)) % M;
            }
        }
        return dp[pos][tight][sum] = res;
    }

    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp, -1, sizeof(dp));
        int helper1 = helper(0, 1, 0, num1, min_sum, max_sum);
        memset(dp, -1, sizeof(dp));
        int helper2 = helper(0, 1, 0, num2, min_sum, max_sum);
        int sum = 0;
        for (auto& num : num1) {
            sum += (num - '0');
        }
        if(min_sum <= sum && sum <= max_sum) {
            helper1--;
        }
        
        return (helper2 - helper1 + M) % M;
    }
};