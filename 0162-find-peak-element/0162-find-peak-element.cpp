class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1;i < n - 1; i++){
            if(nums[i-1] < nums[i] && nums[i] > nums[i+1]){
                return i;
            }
        }
        if(nums[0] > nums[n - 1]) return 0;
        return n - 1;
    }
};