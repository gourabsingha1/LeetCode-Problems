class Solution {
public:
    // if nums is increasing, then k = nums.size()
    int findK(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] >= nums[0]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }

    int findTarget(int low, int high, vector<int>& nums, int target) {
        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }

    int search(vector<int>& nums, int target) {
        int k = findK(nums), n = nums.size();
        int index = 0;
        if(nums[0] > target) {
            index = findTarget(k, n - 1, nums, target);
        }
        else {
            index = findTarget(0, k - 1, nums, target);
        }
        
        if(index == n || nums[index] != target) {
            return -1;
        }
        return index; 
    }
};