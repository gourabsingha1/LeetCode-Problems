class Solution {
public:
    string removeOccurrences(string s, string part) {
        string p;
        for (int i = 0; i < s.size(); i++)
        {
            p += s[i];
            int ub = p.size() - part.size(), lb = part.size();
            if(p.size() >= part.size() && p.substr(ub, lb) == part){
                p.erase(ub, lb);
            }
        }
        return p;
    }
};