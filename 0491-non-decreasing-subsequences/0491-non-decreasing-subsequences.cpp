class Solution {
public:
    void helper(int currInd, vector<int>& subs, vector<vector<int>> &res, vector<int>& nums){
        if(currInd == nums.size()){
            if(subs.size() > 1){
                res.push_back(subs);
            }
            return;
        }
        if(!subs.size() || subs.back() <= nums[currInd]){
            subs.push_back(nums[currInd]);
            helper(currInd + 1, subs, res, nums);
            subs.pop_back();
        }
        helper(currInd + 1, subs, res, nums);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> subs;
        vector<vector<int>> res, ans;
        helper(0, subs, res, nums);
        set<vector<int>> s(res.begin(), res.end());
        ans.assign(s.begin(), s.end());
        return ans;
    }
};