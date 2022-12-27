class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end()), h = accumulate(nums.begin(), nums.end(), 0);
        while(l <= h){
            int mid = h + (l-h)/2, sum = 0, curr = 1;
            for (int i = 0; i < nums.size(); i++)
            {
                sum += nums[i];
                if(sum > mid){
                    curr++;
                    sum = nums[i];
                }
            }
            if(curr > k){
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }
        return l;
    }
};