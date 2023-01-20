class Solution {
public:
    void helper(int currInd, vector<int>& subs, set<vector<int>> &res, vector<int>& nums){
        if(currInd == nums.size()){
            if(subs.size() > 1){
                res.insert(subs);
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
        set<vector<int>> res;
        helper(0, subs, res, nums);
        return vector(res.begin(), res.end());
    }
};