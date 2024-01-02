// res.size() = max freq of nums[i]
// after sorting, if adjacent nums are same, move res iterator (j)
// else initialize j with 0

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), sz = 1, cnt = 1;
        for (int i = 1; i < n; i++)
        {
            if(nums[i - 1] == nums[i]) {
                cnt++;
            }
            else {
                cnt = 1;
            }
            sz = max(sz, cnt);
        }
        
        vector<vector<int>> res(sz);
        int j = 0;
        res[j].push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            if(nums[i - 1] == nums[i]) {
                res[++j].push_back(nums[i]);
            }
            else {
                j = 0;
                res[j].push_back(nums[i]);
            }
        }
        return res;
    }
};