// numbers which occurs even no of times will cancel out each other

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x = 0;
        for(int i = 1; i <= nums.size(); i++){
            x = x ^ i ^ nums[i - 1];
        }
        return x;
    }
};