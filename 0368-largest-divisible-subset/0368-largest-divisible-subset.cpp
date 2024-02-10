// Longest Divisible Subsequence (LDS)
// 1, 2, 4, 8, 16, 32 ..

class Solution {
public:
    vector<int> longestDivisibleSubsequence(vector<int>& nums) {
        int n = nums.size(), lis = 0, maxInd = 0;
        vector<int> dp(n, 1), prev(n), res;
        for (int i = 0; i < n; i++)
        {
            prev[i] = i;
            for (int j = 0; j < i; j++)
            {
                if(nums[i] % nums[j] == 0 && dp[i] < 1 + dp[j]){
                    dp[i] = 1 + dp[j];
                    prev[i] = j;
                }
            }
            if(lis < dp[i]) {
                lis = dp[i];
                maxInd = i;
            }
        }
        while(res.size() < lis) {
            res.push_back(nums[maxInd]);
            maxInd = prev[maxInd];
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return longestDivisibleSubsequence(nums);
    }
};