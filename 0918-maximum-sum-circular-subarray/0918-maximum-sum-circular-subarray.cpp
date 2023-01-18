class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        priority_queue<int> pq;
        int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0), res = INT_MIN, pre = 0, kadanes = 0;
        for (int i = 0; i < n; i++)
        {
            if(nums[i] + kadanes > nums[i]){
                kadanes += nums[i];
            }
            else{
                kadanes = nums[i];
            }
            pre += nums[i];
            sum -= nums[i];
            pq.push(pre);
            res = max({res, pq.top() + sum, kadanes});
        }
        return res;
    }
};