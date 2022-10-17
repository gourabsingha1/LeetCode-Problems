class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(!nums[i]){
                zero++;
            }
            else if(zero){
                nums[i - zero] = nums[i];
                nums[i] = 0;
            }
        }
        return;        
    }
};