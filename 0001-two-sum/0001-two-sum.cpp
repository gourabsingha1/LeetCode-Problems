class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int &x : nums){
            m[x] = 1;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if(m[target - nums[i]]){
                for (int j = i+1; j < nums.size(); j++)
                {
                    if(nums[j] == target - nums[i]){
                        return {i, j};
                    }
                }
            }
        }
        return {-1, -1};
    }
};