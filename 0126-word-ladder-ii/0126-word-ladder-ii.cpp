class Solution {
public:
    vector<vector<string>> res;
    unordered_map<string, int> m;
    void dfs(string &beginWord, string word, vector<string>& seq){
        if(beginWord == word){
            reverse(seq.begin(), seq.end());
            res.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int steps = m[word];
        for (int i = 0; i < beginWord.size(); i++)
        { 
            char temp = word[i];
            for (char c = 'a'; c <= 'z'; c++)
            {
                word[i] = c;
                if(m.find(word) != m.end() && m[word] + 1 == steps){
                    seq.push_back(word);
                    dfs(beginWord, word, seq);
                    seq.pop_back();
                }
            }
            word[i] = temp;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = beginWord.size();
        unordered_map<string, bool> check;
        for(auto &s : wordList) check[s] = 1;
        queue<string> q;
        q.push(beginWord);
        while(q.size()){
            int t = q.size();
            while(t--){
                string s = q.front();
                q.pop();
                check[s] = 0;
                if(s == endWord){
                    vector<string> seq {endWord};
                    dfs(beginWord, endWord, seq);
                    return res;
                }
                int steps = m[s];
                for (int i = 0; i < n; i++)
                { 
                    char temp = s[i];
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        s[i] = c;
                        if(check[s]){
                            q.push(s);
                            m[s] = steps + 1;
                            check[s] = 0;
                        }
                    }
                    s[i] = temp;
                }
            }
        }
        return res;
    }
};