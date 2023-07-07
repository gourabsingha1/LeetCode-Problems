// Number of Subarrays with xor k, where k = 0

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long res = 0, XOR = 0;
        unordered_map<int, int> mp;
        mp[XOR]++;
        for (int i = 0; i < nums.size(); i++)
        {
            XOR ^= nums[i];
            int x = XOR ^ 0; // k = 0

            res += mp[x];
            mp[x]++;
        }
        return res;
    }
};