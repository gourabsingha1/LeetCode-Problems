class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        int res = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        for(auto [x, y] : mp) {
            if(y == 1) return -1;
            res += (y + 2) / 3;
        }
        return res;
    }
};