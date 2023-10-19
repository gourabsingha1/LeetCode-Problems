class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> st1, st2;
        for(auto& ch : s) {
            if(ch != '#') {
                st1.push_back(ch);
            }
            else if(st1.size()) {
                st1.pop_back();
            }
        }
        for(auto& ch : t) {
            if(ch != '#') {
                st2.push_back(ch);
            }
            else if(st2.size()) {
                st2.pop_back();
            }
        }
        return st1 == st2;
    }
};