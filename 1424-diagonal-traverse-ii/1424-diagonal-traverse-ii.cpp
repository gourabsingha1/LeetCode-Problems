// group i + j elements
// which comes first in columnwise, will come first in result

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> res;
        unordered_map<int, vector<int>> mp;
        int n = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums[i].size(); j++)
            {
                mp[i + j].push_back(nums[i][j]);
                n = max(n, i + j);
            }
        }

        for (int i = 0; i <= n; i++)
        {
            for (int j = mp[i].size() - 1; j >= 0; j--)
            {
                res.push_back(mp[i][j]);
            }
        }
        return res;
    }
};