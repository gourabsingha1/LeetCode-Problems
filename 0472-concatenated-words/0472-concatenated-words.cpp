class Solution {
public:
    bool dfs(int i, string curr, string &s, unordered_map<string, bool> &m){
        if(i == s.size()) return m[curr] && curr != s;
        bool again = 0;
        if(m[curr]){
            again = dfs(i, "", s, m);
        }
        return dfs(i + 1, curr + s[i], s, m) || again;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        unordered_map<string, bool> m;
        for (int i = 0; i < words.size(); i++)
        {
            m[words[i]] = 1; 
        }
        for (int i = 0; i < words.size(); i++)
        {
            if(dfs(0, "", words[i], m)){
                res.push_back(words[i]);
            }
        }
        return res;
    }
};