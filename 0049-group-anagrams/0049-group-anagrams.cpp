// sort to have a unique group leader

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for(string& s : strs){
            string p = s;
            sort(p.begin(), p.end());
            mp[p].push_back(s);
        }
        for(auto& [p, s] : mp){
            res.push_back(s);
        }
        return res;
    }
};