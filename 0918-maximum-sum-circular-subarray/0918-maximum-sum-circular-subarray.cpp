class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size(), sum = 0, maxSum = nums[0], minSum = nums[0], currMax = 0, currMin = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if(nums[i] + currMax > nums[i]){
                currMax += nums[i];
            }
            else{
                currMax = nums[i];
            }
            if(nums[i] + currMin < nums[i]){
                currMin += nums[i];
            }
            else{
                currMin = nums[i];
            }
            maxSum = max(maxSum, currMax);
            minSum = min(minSum, currMin);
        }
        if(maxSum < 0) return maxSum;
        return max(maxSum, sum - minSum);
    }
};