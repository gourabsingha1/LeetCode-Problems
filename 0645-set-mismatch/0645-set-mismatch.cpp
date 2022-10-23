class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int a, b;
        for (int i = 0; i < nums.size(); i++)
        {
            int x = abs(nums[i]) - 1;
            if(nums[x] < 0){
                a = x + 1;
            }
            else{
                nums[x] = -nums[x];
            }
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0){
                b = i + 1;
            }
        }
        return {a, b};
    }
};