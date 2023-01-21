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
                string s = q.front(), p = s;
                q.pop();
                m[s] = 0;
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < 26; j++)
                    {
                        int temp = p[i];
                        p[i] = 'a' + j;
                        if(m[p]){
                            if(p == endWord){
                                return res;
                            }
                            q.push(p);
                            m[p] = 0;
                        }
                        p[i] = temp;
                    }
                }
            }
        }
        return 0;
    }
};