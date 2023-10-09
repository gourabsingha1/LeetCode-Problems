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
        return low;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = findPosition(1, 0, n - 1, nums, target);
        if(left == n || nums[left] != target) {
            return {-1, -1};
        }
        
        int right = findPosition(0, left, n - 1, nums, target) - 1;
        return {left, right};
    }
};