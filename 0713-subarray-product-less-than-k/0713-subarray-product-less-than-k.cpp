class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 0, j = 0, n = nums.size(), curr = 0;
        long long x = 1;
        for (int i = 0; i < n; i++)
        {
            x *= nums[i];
            while(j < i && x >= k){
                x /= nums[j++];
                curr = max(0, --curr);
            }
            if(x < k){
                curr++;
                res += curr;
            }
        }
        return res;
    }
};