class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), res = 0;
        if(n == 1) return 0;
        for (int i = 0; i < n; i++)
        {
            res++;
            int j = i, x = nums[i], ma = nums[i] + i;
            if(ma >= n-1){
                return res;
            }
            i++;
            while(i<n && x--){
                if(nums[i] + i >= ma){
                    ma = nums[i] + i;
                    j = i;
                }
                i++;
            }
            i = j - 1;
        }
        return -1;
    }
};