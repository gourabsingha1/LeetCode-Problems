class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int res = 0;
        char a[4] = {'A', 'C', 'G', 'T'};
        unordered_map<string, bool> m;
        for(auto& s : bank) m[s] = 1;
        if(!m[endGene]) return -1;
        queue<string> q;
        q.push(startGene);
        m[startGene] = 0;
        while(q.size()){
            int t = q.size();
            while(t--){
                string s = q.front();
                q.pop();
                if(s == endGene){
                    return res;
                }
                for (int i = 0; i < s.size(); i++)
                {
                    char temp = s[i];
                    for (int j = 0; j < 4; j++)
                    {
                        s[i] = a[j];
                        if(m[s]){
                            q.push(s);
                            m[s] = 0;
                        }
                    }
                    s[i] = temp;
                }
            }
            res++;
        }
        return -1;
    }
};