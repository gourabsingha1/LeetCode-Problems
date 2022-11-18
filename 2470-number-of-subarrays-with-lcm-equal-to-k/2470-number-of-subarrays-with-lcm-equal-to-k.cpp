class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++)
        {
            int lcm = nums[i];
            for (int j = i; j < n; j++)
            {
                if(k%nums[j] == 0){
                    lcm = (lcm*nums[j])/__gcd(lcm, nums[j]);
                    if(lcm == k){
                        res++;
                    }
                }
                else{
                    break;
                }
            }
        }
        return res;
    }
};