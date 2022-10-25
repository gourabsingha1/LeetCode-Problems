class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size(), res = nums[0] + nums[1] + nums[n-1];
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n-2; i++)
        {
            int low = i + 1, high = n - 1;
            while(low < high){
                int x = nums[i] + nums[low] + nums[high];
                if(x < target){
                    low++;
                }
                else{
                    high--;
                }
                if(abs(target - x) < abs(target - res)){
                    res = x;
                }
            }
        }
        return res;
    }
};