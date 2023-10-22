class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int res = nums[0], n = nums.size();
        vector<int> dp(nums);
        deque<int> maxDeque;
        for (int i = 0; i < n; i++)
        {
            while(maxDeque.size() && maxDeque.front() < i - k){
                maxDeque.pop_front();
            }

            int mx = 0;
            if(maxDeque.size()){
                mx = dp[maxDeque.front()];
            }
            dp[i] = max(dp[i], nums[i] + mx);
            res = max(res, dp[i]);

            while(maxDeque.size() && dp[maxDeque.back()] <= dp[i]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(i);
        }
        return res;
    }
};