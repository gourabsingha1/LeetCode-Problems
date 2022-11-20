class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        vector<int> pre(n, 1), suff(n, 1);
        for (int i = 1; i < n; i++)
        {
            if(nums[i-1] >= nums[i]){
                pre[i] = pre[i-1] + 1;
            }
        }
        for (int i = n-2; i > 0; i--)
        {
            if(nums[i+1] >= nums[i]){
                suff[i] = suff[i+1] + 1;
            }
        }
        for (int i = k; i < n-k; i++)
        {
            if(pre[i-1] >= k && suff[i+1] >= k){
                res.push_back(i);
            }
        }
        return res;
    }
};