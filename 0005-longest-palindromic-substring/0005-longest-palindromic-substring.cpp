// let s[i] is the middle element of palindrome
// expand left and right

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), j = 0, size = 0;
        for (int i = 0; i < n; i++)
        {
            // odd length
            int l = i, r = i, curr = -1;
            while(l >= 0 && r < n && s[l] == s[r]){
                curr += 2, l--, r++;
            }
            if(curr > size){
                size = curr;
                j = l + 1;
            }
            
            // even length
            l = i, r = i + 1, curr = 0;
            while(l >= 0 && r < n && s[l] == s[r]){
                curr += 2, l--, r++;
            }
            if(curr > size){
                size = curr;
                j = l + 1;
            }
        }
        return s.substr(j, size);
    }
};