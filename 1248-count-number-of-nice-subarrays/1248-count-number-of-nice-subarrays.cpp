class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int res = 0, cnt = 0, j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] & 1) {
                cnt++;
            }
            if(cnt == k) {
                int left = 1;
                while(j < nums.size() && nums[j] % 2 == 0) {
                    left++, j++;
                }

                i++;
                int right = 1;
                while(i < nums.size() && nums[i] % 2 == 0) {
                    right++, i++;
                }
                res += left * right;
                
                j++, cnt--, i--;
            }
        }
        return res;
    }
};