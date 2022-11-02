class Solution {
public:
    string customSortString(string order, string s) {
        string res;
        unordered_map<char,int>m;
        for(char &c : s){
            m[c]++;
        }
        for(char &c : order){
            while(m[c]){
                res += c;
                m[c]--;
            }
        }
        for(char &c : s){
            if(m[c]){
                res += c;
            }
        }
        return res;
    }
};