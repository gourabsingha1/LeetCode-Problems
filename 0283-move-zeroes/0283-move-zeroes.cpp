class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(!nums[i]){
                zero++;
                nums.erase(nums.begin()+i, nums.begin()+i+1);
                i--;
            }
        }

        while(zero--){
            nums.push_back(0);
        }
        return;        
    }
};