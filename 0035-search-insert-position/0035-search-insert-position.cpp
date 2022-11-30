class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size(), low = 0, mid, high = n-1;
        if(target<=nums[0]) return 0;
        else if (target>nums[n-1]) return n;
        while(high-low>1){
            mid = (high+low)/2;
            if(nums[mid]<target){
                low = mid;
            }
            else if(nums[mid]>target){
                high = mid;
            }
            else{
                return mid;
            }
        }
        return high;
    }
};