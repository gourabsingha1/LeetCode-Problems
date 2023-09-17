class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(mid > 0 && nums[mid - 1] > nums[mid]) {
                return nums[mid];
            }
            if(low < high && nums[low] == nums[high]) {
                low++;
            }
            else if(nums[mid] > nums[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return nums[low];
    }
};