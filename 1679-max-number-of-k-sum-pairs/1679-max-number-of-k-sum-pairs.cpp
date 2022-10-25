class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int high = nums.size() - 1, low = 0;
        while(low < high){
            if(nums[low] + nums[high] == k){
                res++;
                low++;
                high--;
            }
            else if(nums[low] + nums[high] > k){
                high--;
            }
            else{
                low++;
            }
        }
        return res;
    }
};