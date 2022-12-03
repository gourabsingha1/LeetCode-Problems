class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> m;
        for(auto &v : knowledge){
            m[v[0]] = v[1];
        }
        string res;
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i] != '('){
                res.push_back(s[i]);
            }
            else{
                string p;
                while(s[++i] != ')'){
                    p += s[i];
                }
                p = m[p];
                if(p.empty()) p = "?";
                res.append(p);
            }
        }
        return res;
    }
};