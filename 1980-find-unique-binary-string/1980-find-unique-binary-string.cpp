class Solution {
public:
    string res = "";
    
    void helper(string s, int n, vector<string>& nums, unordered_map<string, bool>& seen) {
        if(n == 0) {
            if(!seen[s]) {
                res = s;
            }
            return;
        }
        
        helper(s + "0", n - 1, nums, seen);
        if(res == "") {
            helper(s + "1", n - 1, nums, seen);
        }
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string, bool> seen;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            seen[nums[i]] = 1;
        }
        helper("", n, nums, seen);
        return res;
    }
};