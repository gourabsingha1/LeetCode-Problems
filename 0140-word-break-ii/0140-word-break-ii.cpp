class Solution {
public:
    // recursion
    vector<string> res;
    void helper(int n, string temp, string& s, unordered_map<string, bool>& dict, vector<int>& dp) {
        if(n < 0) {
            temp.pop_back();
            res.push_back(temp);
            return;
        }
        bool res = 0;
        for (int i = n; i >= 0; i--)
        {
            if(dict[s.substr(i, n + 1 - i)]) {
                helper(i - 1, s.substr(i, n + 1 - i) + " " + temp, s, dict, dp);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> dict;
        vector<int> dp(s.size(), -1);
        for(auto& s : wordDict) {
            dict[s] = 1;
        }
        helper(s.size() - 1, "", s, dict, dp);
        return res;
    }
};