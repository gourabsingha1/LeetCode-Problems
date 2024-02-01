// greedy way is the select the closest elements
// i.e by sorting

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < 3) {
            return {};
        }

        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 2; i < n; i += 3)
        {
            vector<int> temp;
            if(nums[i] - nums[i - 2] <= k) {
                temp.push_back(nums[i - 2]);
                temp.push_back(nums[i - 1]);
                temp.push_back(nums[i]);
                res.push_back(temp);
            }
            else {
                return {};
            }
        }
        return res;
    }
};