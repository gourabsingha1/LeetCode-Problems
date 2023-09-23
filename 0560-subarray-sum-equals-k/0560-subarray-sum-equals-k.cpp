class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, n = nums.size(), pre = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            pre += nums[i];
            if(pre == k) {
                res++;
            }
            res += mp[pre - k];
            mp[pre]++;
        }
        return res;
    }
};