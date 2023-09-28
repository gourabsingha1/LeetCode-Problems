class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end()), high = 1e9;
        while(low <= high){
            int mid = (low + high) / 2, subarray = 0, curK = 1;
            for (int i = 0; i < nums.size(); i++)
            {
                subarray += nums[i];
                if(subarray > mid){
                    curK++;
                    subarray = nums[i];
                }
            }
            if(curK > k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
};