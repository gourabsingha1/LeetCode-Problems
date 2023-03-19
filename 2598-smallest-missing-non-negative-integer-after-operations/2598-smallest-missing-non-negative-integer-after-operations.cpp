class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> mp(value);
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < 0) {
                mp[(value + nums[i] % value) % value]++;
            }
            else {
                mp[abs(nums[i] % value)]++;
            }
        }
        int j = 0, mi = nums.size();
        for (int i = 0; i < value; i++)
        {
            mi = min(mi, mp[i]);
        }
        for (int i = 0; i < value; i++)
        {
            if(mp[i]) {
                j++;
            }
            else {
                break;
            }
        }
        if(j == value) {
            int res = mi * value;
            for (int i = 0; i < value; i++)
            {
                if(mp[i] - mi <= 0) {
                    break;
                }
                res++;
            }
            return res;
        }
        return j;
    }
};