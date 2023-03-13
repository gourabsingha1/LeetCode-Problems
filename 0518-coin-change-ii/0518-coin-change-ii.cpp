class Solution {
public:
    // space optimization
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount + 1);
        for (int i = 0; i < n; i++)
        {
            vector<int> cur(amount + 1);
            for (int j = 0; j <= amount; j++)
            {
                if(i == 0) {
                    cur[j] = j % coins[i] == 0;
                }
                else {
                    int take = 0;
                    if(j - coins[i] >= 0) {
                        take = cur[j - coins[i]];
                    }
                    int notTake = prev[j];
                    cur[j] = take + notTake;
                }
            }
            prev = cur;
        }
        return prev[amount];
    }
};