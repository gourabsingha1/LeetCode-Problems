class Solution {
public:
    int helper(int n, vector<int>& nums, vector<int>& cookies, int& k) {
        if(n < 0) {
            int ma = *max_element(nums.begin(), nums.end());
            return ma;
        }
        int res = INT_MAX;
        for (int i = 0; i < k; i++)
        {
            nums[i] += cookies[n];
            res = min(res, helper(n - 1, nums, cookies, k));
            nums[i] -= cookies[n];
        }
        return res;
    }

    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> nums(k, 0);
        return helper(cookies.size() - 1, nums, cookies, k);
    }
};