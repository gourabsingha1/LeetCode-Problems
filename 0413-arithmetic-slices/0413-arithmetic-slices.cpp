class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        int n = nums.size(), j = 0, d = nums[1] - nums[0], res = 0;
        for (int i = 2; i < n; i++)
        {
            int size = i - j;
            if(nums[i] - nums[i-1] != d){
                res += ((size-1)*(size-2))/2;
                d = nums[i] - nums[i-1];
                j = i-1;
            }
            else if(i == n-1){
                size++;
                res += ((size-1)*(size-2))/2;
            }
        }
        return res;
    }
};