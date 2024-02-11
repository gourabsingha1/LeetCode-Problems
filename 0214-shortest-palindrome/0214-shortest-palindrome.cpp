// longest palindromic substring starting with index 0 will remain in the shortest pal
// add the reverse of remaining string in front

class Solution {
public:
    // **** Longest Prefix Suffix (LPS) - O(N), O(N) ****
    int longestPrefixLength(string& s) {
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
        return prevLPS;
    }
    
    string shortestPalindrome(string s) {
        string p = s;
        reverse(p.begin(), p.end());
        string tot = s + "$" + p;
        int n = longestPrefixLength(tot);
        
        string suf = s.substr(n, s.size() - n);
        reverse(suf.begin(), suf.end());
        return suf + s;
    }
};