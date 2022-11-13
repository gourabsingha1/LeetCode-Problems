class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for(string &s : strs){
            string p = s;
            sort(p.begin(), p.end());
            m[p].push_back(s);
        }
        for(auto &x : m){
            res.push_back(x.second);
        }
        return res;
    }
};