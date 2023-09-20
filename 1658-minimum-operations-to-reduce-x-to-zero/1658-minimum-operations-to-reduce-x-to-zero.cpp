// find subarray of sum - x
// res = n - size

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), target = accumulate(nums.begin(), nums.end(), 0) - x, res = 1e9, cur = 0;
        if(target < 0) {
            return -1;
        }
        if(target == 0 && n == 1) {
            return 1;
        }
        
        for (int i = 0, j = 0; i < n; i++)
        {
            cur += nums[i];
            while(j < n && cur >= target) {
                if(cur == target) {
                    res = min(res, n - (i - j + 1));
                }
                cur -= nums[j++];
            }
        }
        
        if(res == 1e9) {
            return -1;
        }
        return res;
    }
};