// https://www.youtube.com/watch?v=eZr-6p0B7ME

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long res = 0, XOR = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            XOR ^= nums[i];
            res += mp[XOR];
            if(XOR == 0){
                res++;
            }
            mp[XOR]++;
        }
        return res;
    }
};