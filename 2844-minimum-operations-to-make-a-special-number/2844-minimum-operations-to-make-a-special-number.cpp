class Solution {
public:
    unordered_map<string, int> dp;

    int helper(int rem, int i, string& num) {
        if(i == num.size()) {
            if(rem == 0) {
                return 0;
            }
            return -1e3;
        }
        string memo = to_string(rem) + "*" + to_string(i);
        if(dp.find(memo) != dp.end()) {
            return dp[memo];
        }

        int take = 1 + helper((rem * 10 + num[i] - '0') % 25, i + 1, num);
        int notTake = helper(rem, i + 1, num);
        return dp[memo] = max(take, notTake);
    }

    int minimumOperations(string num) {
        return num.size() - helper(0, 0, num);
    }
};