class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long int n = nums.size(), avg = INT_MAX, res = 0, pre[n], suf[n];
        pre[0] = nums[0], suf[n-1] = nums[n-1];
        for (int i = 1; i < n; i++) pre[i] = pre[i-1] + nums[i];
        for (int i = n-2; i >= 0; i--) suf[i] = suf[i+1] + nums[i];
        for (int i = 0; i < n; i++){
            long long int a = pre[i]/(i+1), b = 0, x = a;
            if(i != n-1) x = abs(a-suf[i+1]/(n-1-i));
            if(x < avg){
                avg = x;
                res = i;
            }
        }
        return res;
    }
};