class Solution {
public:
    string helper(int curr, string& s, int& n){
        if(curr == n){
            return s;
        }
        
        string p;
        int i = 0, m = s.size();
        while(i < m) {
            int j = i;
            while(i < m && s[j] == s[i]){
                i++;
            }
            p += to_string(i - j) + s[j];
        }
        return helper(curr + 1, p, n);
    }
    
    string countAndSay(int n) {
        string s = "1";
        return helper(1, s, n);
    }
};