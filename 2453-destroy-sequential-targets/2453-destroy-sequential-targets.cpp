class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int res = 0, n = nums.size(), mx = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i] % space]++;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if(mx < mp[nums[i] % space]) {
                mx = mp[nums[i] % space];
                res = nums[i];
            }
        }
        return res;
    }
};