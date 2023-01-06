class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size(), LPS[n], i = 1, prevLPS = 0;
        LPS[0] = 0;
        while(i < n){
            if(s[i] == s[prevLPS]){
                LPS[i] = prevLPS + 1;
                prevLPS++, i++;
            }
            else if(prevLPS == 0){
                LPS[i] = 0, i++;
            }
            else{
                prevLPS = LPS[prevLPS - 1];
            }
        }
        return s.substr(0, prevLPS);
    }
};