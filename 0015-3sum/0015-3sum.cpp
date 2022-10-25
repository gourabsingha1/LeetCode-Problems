class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2; i++)
        {
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            int low = i + 1, high = nums.size() - 1;
            while(low < high){
                int x = nums[i] + nums[low] + nums[high];
                if(!x){
                    res.push_back({nums[i], nums[low], nums[high]});
                    while(low < nums.size()-1 && nums[low]==nums[low+1]){
                        low++;
                    }
                    while(high > 0 && nums[high]==nums[high-1]){
                        high--;
                    }
                    low++;
                    high--;
                }
                else if(x > 0){
                    high--;
                }
                else{
                    low++;
                }
            }
        }
        return res;
    }
};