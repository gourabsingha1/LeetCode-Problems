class Solution {
public:
    string removeOccurrences(string s, string part) {
        for (int i = 0; i < s.size(); i++)
        {
            int ub = i + 1 - part.size(), lb = part.size();
            if(ub >= 0 && s.substr(ub, lb) == part){
                s.erase(ub, lb);
                i -= part.size();
            }
        }
        return s;
    }
};