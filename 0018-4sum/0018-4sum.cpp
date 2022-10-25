class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int j = 0; j < n-3; j++)
        {
            if(j>0 && nums[j] == nums[j-1]){
                continue;
            }
            for (int i = j+1; i < n-2; i++)
            {
                if(i > j+1 && nums[i] == nums[i-1]){
                    continue;
                }
                int low = i + 1, high = n - 1;
                while(low < high){
                    long long int x = nums[j] + nums[i];
                    x += nums[low] + nums[high];
                    if(x < target){
                        low++;
                    }
                    else if(x > target){
                        high--;
                    }
                    else{
                        vector<int> v = {nums[j], nums[i], nums[low], nums[high]};
                        res.push_back(v);
                        low++;
                        while(low < high && nums[low]==nums[low-1]){
                            low++;
                        }
                    }
                }
            }
        }
        return res;
    }
};