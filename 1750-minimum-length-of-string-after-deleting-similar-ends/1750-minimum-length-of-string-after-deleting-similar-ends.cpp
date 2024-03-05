class Solution {
public:
    int minimumLength(string s) {
        int l = 0, r = s.size() - 1;
        while(l < r && s[l] == s[r]){
            if(l + 1 < r && s[l] == s[l + 1]){
                l++;
            }
            else if(l < r - 1 && s[r] == s[r - 1]){
                r--;
            }
            else{
                l++, r--;
            }
        }
        return r - l + 1;
    }
};