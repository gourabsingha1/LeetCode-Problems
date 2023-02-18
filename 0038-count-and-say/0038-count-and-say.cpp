class Solution {
public:
    string helper(int curr, string s, int n){
        if(curr == n){
            return s;
        }
        string p;
        int i = 0;
        while(i < s.size()) {
            int j = i, cnt = 0;
            while(i < s.size() && s[j] == s[i]){
                cnt++, i++;
            }
            p += to_string(cnt) + s[i - 1];
        }
        return helper(curr + 1, p, n);
    }
    string countAndSay(int n) {
        return helper(1, "1", n);
    }
};