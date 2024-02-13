class Solution {
public:
    // **** Palindrome or not ****
    bool isPal(string s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--]){
                return 0;
            }
        }
        return 1;
    }
    
    string firstPalindrome(vector<string>& words) {
        for(auto& word : words) {
            if(isPal(word, 0, word.size() - 1)) {
                return word;
            }
        }
        return "";
    }
};