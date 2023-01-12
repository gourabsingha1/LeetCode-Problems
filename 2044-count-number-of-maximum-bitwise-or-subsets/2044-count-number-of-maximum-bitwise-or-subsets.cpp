class Solution {
public:
    void helper(int currInd, int currOR, int &OR, vector<int> &nums, int &res){
        if(currInd == nums.size()){
            if(currOR == OR) res++;
            return;
        }
        helper(currInd + 1, currOR | nums[currInd], OR, nums, res);
        helper(currInd + 1, currOR, OR, nums, res);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int OR = 0, res = 0;
        for(auto &x : nums) OR |= x;
        helper(0, 0, OR, nums, res);
        return res;
    }
};