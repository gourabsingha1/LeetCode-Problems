class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = 1, mn = 1, res = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            // to handle -ve case
            if(nums[i] < 0) {
                swap(mx, mn);
            }

            // to handle 0 case. consider new subarray
            mx = max(mx * nums[i], nums[i]);
            mn = min(mn * nums[i], nums[i]);
            
            res = max(res, mx);
        }
        return res;
    }
};