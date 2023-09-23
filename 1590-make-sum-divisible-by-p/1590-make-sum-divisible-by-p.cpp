// target = sum % p
// pre = want + target
// find the latest index of "want" to get the smallest subarray

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size(), res = n, pre = 0, target = 0;
        for (int i = 0; i < n; i++)
        {
            target = (target + nums[i]) % p;
        }
        unordered_map<int, int> mp; // num, index
        mp[0] = -1; // initial cumulative sum = 0 and that sum % p will be equal to 0 always
        for (int i = 0, j = 0; i < n; i++)
        {
            pre = (pre + nums[i]) % p;
            mp[pre] = i;
            int want = (pre - target + p) % p;
            if(mp.find(want) != mp.end()) {
                res = min(res, i - mp[want]);
            }
        }
        
        if(res == n) {
            return -1;
        }
        return res;
    }
};