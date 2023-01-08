class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int i = 0, j = 0, n = s.size();
        while(i < n){
            while(i < n && s[i] == ' ') i++;
            int k = i;
            while(i < n && s[i] != ' ') i++;
            reverse(s.begin() + k, s.begin() + i);
            while(k < n && s[k] != ' ') s[j++] = s[k++];
            while(i < n && s[i] == ' ') i++;
            if(i < n) s[j++] = ' ';
        }
        return s.substr(0, j);
    }
};