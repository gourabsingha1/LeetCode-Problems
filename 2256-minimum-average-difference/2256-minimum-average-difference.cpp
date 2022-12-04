class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long int n = nums.size(), avg = INT_MAX, res = 0, pre = 0, suf = 0;
        for(int &x : nums) suf += x;
        for (int i = 0; i < n; i++){
            pre += nums[i], suf -= nums[i];
            long long int x = pre/(i+1);
            if(i != n-1) x = abs(pre/(i+1)-suf/(n-1-i));
            if(x < avg){
                avg = x;
                res = i;
            }
        }
        return res;
    }
};