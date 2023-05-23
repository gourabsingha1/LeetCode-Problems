class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = 0, cnt = 0, j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(!nums[i]) {
                cnt++;
            }
            while(cnt > k) {
                if(!nums[j]) {
                    cnt--;
                }
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};