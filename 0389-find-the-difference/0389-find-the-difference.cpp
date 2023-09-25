class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        s += t;
        for(auto &ch : s){
            res ^= ch;
        }
        return res;
    }
};