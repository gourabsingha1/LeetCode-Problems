class Solution {
public:
    unordered_map<int, int> m;
    int dfs(int n){
        if(!m[n]){
            return 0;
        }
        if(m[n] > 1){
            return m[n];
        }
        return m[n] = dfs(n + 1) + 1;
    }
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++)
        {
            m[nums[i]] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            res = max(res, dfs(nums[i]));
        }
        return res;
    }
};