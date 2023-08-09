// binary search the res
// we take adjacent elements after sorting (greedy)
// if nums[i + 1] - nums[i] <= mid, we found one pair
// so skip nums[i + 1] next

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int low = 0, high = 1e9;
        while(low <= high) {
            int mid = (low + high) / 2, P = p;
            for (int i = 0; i < nums.size() - 1 && P; i++)
            {
                if(nums[i + 1] - nums[i] <= mid) {
                    P--, i++;
                }
            }
            if(P == 0) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};