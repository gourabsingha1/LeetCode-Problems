class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 0, j = 0, n = nums.size(), curr = 0, prod = 1;
        for (int i = 0; i < n; i++)
        {
            prod *= nums[i];
            while(j < i && prod >= k){
                prod /= nums[j++];
                curr = max(0, --curr);
            }
            if(prod < k){
                curr++;
                res += curr;
            }
        }
        return res;
    }
};