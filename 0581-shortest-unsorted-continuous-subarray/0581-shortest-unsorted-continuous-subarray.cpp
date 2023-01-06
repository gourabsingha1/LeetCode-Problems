class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), j = 0, k = -1;
        for (int i = 1; i < n; i++)
        {
            if(nums[i-1] > nums[i]){
                int mi = nums[i];
                while(i < n) mi = min(mi, nums[i++]);
                while(j < n && mi >= nums[j]) j++;
                break;
            }
        }
        for (int i = n-2; i >= 0; i--)
        {
            if(nums[i] > nums[i+1]){
                int ma = nums[i];
                k = n - 1;
                while(i >= 0) ma = max(ma, nums[i--]);
                while(k >= 0 && ma <= nums[k]) k--;
                break;
            }
        }
        return k - j + 1;
    }
};