class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = high + (low - high) / 2;
            if(mid & 1){
                if(nums[mid - 1] == nums[mid]){
                    low = mid + 1;
                }
                else if(nums[mid] == nums[mid + 1]){
                    high = mid - 1;
                }
                else{
                    return nums[mid];
                }
            }
            else{
                if(mid && nums[mid - 1] == nums[mid]){
                    high = mid - 1;
                }
                else if(nums[mid] == nums[mid + 1]){
                    low = mid + 1;
                }
                else{
                    return nums[mid];
                }
            }
        }
        return -1;
    }
};