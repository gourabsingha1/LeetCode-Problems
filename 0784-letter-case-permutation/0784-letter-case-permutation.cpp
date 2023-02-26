class Solution {
public:
    void helper(int currInd, string& nums, vector<string> &res){
        int n = nums.size();
        if(currInd == n){
            res.push_back(nums);
            return;
        }
        if(isdigit(nums[currInd])){
            helper(currInd + 1, nums, res);
        }
        else{
            nums[currInd] = toupper(nums[currInd]);
            helper(currInd + 1, nums, res);
            nums[currInd] = tolower(nums[currInd]);
            helper(currInd + 1, nums, res);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        helper(0, s, res);
        return res;
    }
};