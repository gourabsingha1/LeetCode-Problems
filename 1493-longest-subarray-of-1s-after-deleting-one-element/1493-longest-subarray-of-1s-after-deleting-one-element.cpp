class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0, cnt = 0;
        for (int i = 0, j = 0; i < nums.size(); i++)
        {
            if(!nums[i]) {
                cnt++;
            }
            while(cnt > 1) {
                if(!nums[j]) {
                    cnt--;
                }
                j++;
            }
            res = max(res, i - j);
        }
        return res;
    }
};