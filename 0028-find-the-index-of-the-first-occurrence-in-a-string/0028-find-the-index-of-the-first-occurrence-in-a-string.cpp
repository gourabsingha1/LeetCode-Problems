class Solution {
public:
    vector<int> lps(string &s) {
        int n = s.size(), i = 1, prevLPS = 0;
        vector<int> LPS(n, 0);
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
        return LPS;
    }
    int strStr(string haystack, string needle) {
        vector<int> LPS = lps(needle);
        int i = 0, j = 0;
        while(i < haystack.size()){
            if(haystack[i] == needle[j]){
                i++, j++;
            }
            else if(j == 0){
                i++;
            }
            else{
                j = LPS[j-1];
            }
            if(j == needle.size()){
                return i - needle.size();
            }
        }
        return -1;
    }
};