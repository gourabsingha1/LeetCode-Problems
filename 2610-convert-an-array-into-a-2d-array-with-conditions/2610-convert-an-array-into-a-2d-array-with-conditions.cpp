// since constraints are small, iterate j from 1 to 201
// if j exists in nums, push it in the latest index of res and decrement its count

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> mp(201, 0);
        int ma = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ma = max(ma, ++mp[nums[i]]);
        }
        for (int i = 0; i < ma; i++)
        {
            vector<int> temp;
            for (int j = 1; j < 201; j++)
            {
                if(mp[j]) {
                    temp.push_back(j);
                    mp[j]--;
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};