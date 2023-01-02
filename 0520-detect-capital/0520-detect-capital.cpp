class Solution {
public:
    bool detectCapitalUse(string word) {
        int res = 0, upper = 0, n = word.length();
        for(char &c : word){
            if(isupper(c)) upper++;
        }
        return upper == n || !upper || upper == 1 && isupper(word[0]);
    }
};