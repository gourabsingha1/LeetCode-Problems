class Solution {
public:
    void helper(int currInd, string& nums, set<string> &st){
        int n = nums.size();
        if(currInd == n){
            st.insert(nums);
            return;
        }
        if(islower(nums[currInd])){
            nums[currInd] = toupper(nums[currInd]);
        }
        else if(isupper(nums[currInd])){
            nums[currInd] = tolower(nums[currInd]);
        }
        helper(currInd + 1, nums, st);
        if(islower(nums[currInd])){
            nums[currInd] = toupper(nums[currInd]);
        }
        else if(isupper(nums[currInd])){
            nums[currInd] = tolower(nums[currInd]);
        }
        helper(currInd + 1, nums, st);
    }
    vector<string> letterCasePermutation(string s) {
        set<string> st;
        helper(0, s, st);
        vector<string> res;
        res.assign(st.begin(), st.end());
        return res;
    }
};