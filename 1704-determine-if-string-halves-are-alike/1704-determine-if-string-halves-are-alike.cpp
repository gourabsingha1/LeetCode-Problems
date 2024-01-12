class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    
    bool halvesAreAlike(string s) {
        int n = s.size(), cnt = 0;
        for(int i = 0; i < n; i++) {
            if(isVowel(s[i])){
                if(i < n / 2) {
                    cnt++;
                }
                else {
                    cnt--;
                }
            }
        }
        return cnt == 0;
    }
};