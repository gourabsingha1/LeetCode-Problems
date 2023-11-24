class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> res;
        map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums[i].size(); j++)
            {
                mp[i + j].push_back(nums[i][j]);
            }
        }
        for(auto& [x, v] : mp) {
            for (int i = v.size() - 1; i >= 0; i--)
            {
                res.push_back(v[i]);
            }
        }
        return res;
    }
};