class Solution {
public:
    int findPosition(bool left, int low, int high, vector<int>& nums, int target) {
        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] == target) {
                if(left) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            else if(nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        if(left) {
            return low;
        }
        return high;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int mid = findPosition(1, 0, n - 1, nums, target);
        if(mid == n || nums[mid] != target) {
            return {-1, -1};
        }
        
        int left = findPosition(1, 0, mid, nums, target);
        int right = findPosition(0, mid, n - 1, nums, target);
        return {left, right};
    }
};