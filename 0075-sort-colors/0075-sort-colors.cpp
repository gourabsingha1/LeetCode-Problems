class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(!nums[i]) zero++;
            else if(nums[i] == 1) one++;
        }
        one += zero;
        for (int i = 0; i < nums.size(); i++)
        {
            if(i < zero){
                nums[i] = 0;
            }
            else if(i < one){
                nums[i] = 1;
            }
            else{
                nums[i] = 2;
            }
        }
        return;
    }
};