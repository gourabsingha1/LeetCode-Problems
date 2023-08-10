class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] == target) {
                return 1;
            }
            else if(nums[low] == nums[mid] && nums[mid] == nums[high]) { // cant determine which side is in order. so we shrink both sides by 1
                low++, high--;
            }
            else if(nums[low] <= nums[mid]) { // first half in order
                if(nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            else { // second half in order
                if(nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }
        return 0;
    }
};