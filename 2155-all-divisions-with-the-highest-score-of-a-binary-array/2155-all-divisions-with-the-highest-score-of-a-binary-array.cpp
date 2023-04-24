class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size(), pre[n];
        pre[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            pre[i] = nums[i] + pre[i - 1];
        }
        int ma = pre[n - 1];
        mp[ma] = {0};
        for (int i = 0; i < n; i++)
        {
            int left = i + 1 - pre[i], right = pre[n - 1] - pre[i];
            if(ma <= left + right) {
                ma = left + right;
                mp[ma].push_back(i + 1);
            }
        }
        return mp[ma];
    }
};