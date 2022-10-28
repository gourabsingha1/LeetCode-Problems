class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0, pre = 0, suf = 0, zero = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] && !zero){
                pre++;
            }
            else if(pre && !nums[i]){
                zero++;
            }
            else if(zero == 1){
                suf++;
            }
            else if(pre){
                res = max(res, pre + suf);
                if((zero == 2 && nums[i-1] != nums[i-2])){
                    pre = suf;
                    zero = 1;
                    suf = 1;
                }
                else{
                    pre = 1;
                    zero = 0;
                    suf = 0;
                }
            }
        }
        res = max(res, pre + suf);
        if(res == nums.size()){
            res--;
        }
        return res;
    }
};