class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = beginWord.size(), res = 1;
        unordered_map<string, bool> m;
        for(auto &s : wordList) m[s] = 1;
        queue<string> q;
        q.push(beginWord);
        while(q.size()){
            res++;
            int t = q.size();
            while(t--){
                string s = q.front();
                q.pop();
                m[s] = 0;
                for (int i = 0; i < n; i++)
                {
                    char temp = s[i];
                    for (int j = 0; j < 26; j++)
                    {
                        s[i] = 'a' + j;
                        if(m[s]){
                            if(s == endWord){
                                return res;
                            }
                            q.push(s);
                            m[s] = 0;
                        }
                    }
                    s[i] = temp;
                }
            }
        }
        return 0;
    }
};