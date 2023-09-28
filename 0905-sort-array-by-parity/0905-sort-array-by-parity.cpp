class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, n = nums.size() - 1;
        while(i < n) {
            if(nums[i] & 1) {
                while(n >= 0 && nums[n] & 1) {
                    n--;
                }
                if(i < n) {
                    swap(nums[i++], nums[n--]);
                }
            }
            else {
                i++;
            }
        }
        return nums;
    }
};