class Solution {
public:
    void dfs(int i, string p, string &s, vector<string> v, vector<vector<string>> &res){
        if(i == s.size()){
            if(isPalindrome(p)){
                v.push_back(p);
                res.push_back(v);
            }
            return;
        }
        dfs(i + 1, p + s[i], s, v, res);
        if(isPalindrome(p)){
            v.push_back(p);
            string temp; temp += s[i];
            dfs(i + 1, temp, s, v, res);
            v.pop_back();
        }
    }
    bool isPalindrome(string &s){
        if(!s.size()) return 0;
        int i = 0, j = s.size() - 1;
        while(i < j){
            if(s[i++] != s[j--]) return 0;
        }
        return 1;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        dfs(0, "", s, {}, res);
        return res;
    }
};