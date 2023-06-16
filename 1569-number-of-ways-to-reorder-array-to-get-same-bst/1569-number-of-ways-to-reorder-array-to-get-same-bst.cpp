// res = nCr(n - 1, left.size()) * dfs(left) * dfs(right)

class Solution {
public:
    int M = 1e9 + 7;

    // **** nCr table ****
    vector<vector<int>> nCrTable(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res(n + 1, vector<int>(n + 1));
        res[0][0] = 1;
        for (int i = 1; i <= n; i++) 
        {
            res[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                res[i][j] = (res[i - 1][j - 1] + res[i - 1][j]) % M; // nCr = (n - 1)C(r - 1) + (n - 1)Cr
            }
        }
        return res;
    }

    int helper(vector<int>& nums, vector<vector<int>>& comb) {
        int n = nums.size();
        if(n <= 2) {
            return 1;
        }
        vector<int> left, right;
        for(int i = 1; i < n; i++) {
            if(nums[i] < nums[0]) {
                left.push_back(nums[i]);
            }
            else {
                right.push_back(nums[i]);
            }
        }
        int res = 1LL * comb[n - 1][left.size()] * helper(left, comb) % M * helper(right, comb) % M;
        return res;
    }

    int numOfWays(vector<int>& nums) {
        vector<vector<int>> comb = nCrTable(nums);
        return helper(nums, comb) - 1;
    }
};