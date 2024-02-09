// 1, 2, 4, 8, 16, 32 ..

class Solution {
public:
    unordered_map<int, vector<int>> dp;

    vector<int> helper(int i, vector<int>& nums) {
        if(i == nums.size()) {
            return {};
        }
        if(dp.find(i) != dp.end()) {
            return dp[i];
        }
        
        vector<int> res = {nums[i]};
        for (int j = i + 1; j < nums.size(); j++)
        {
            if(nums[j] % nums[i] == 0) {
                vector<int> take = helper(j, nums);
                take.push_back(nums[i]);
                if(res.size() < take.size()) {
                    res = take;
                }
            }
        }
        return dp[i] = res;
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            vector<int> temp = helper(i, nums);
            if(res.size() < temp.size()) {
                res = temp;
            }
        }
        return res;
    }
};