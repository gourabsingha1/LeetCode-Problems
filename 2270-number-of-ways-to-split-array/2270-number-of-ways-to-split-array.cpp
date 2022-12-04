class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long int n = nums.size(), res = 0, pre = 0, suf = 0;
        for(int &x : nums) suf += x;
        for (int i = 0; i < n-1; i++){
            pre += nums[i], suf -= nums[i];
            if(pre >= suf){
                res++;
            }
        }
        return res;
    }
};