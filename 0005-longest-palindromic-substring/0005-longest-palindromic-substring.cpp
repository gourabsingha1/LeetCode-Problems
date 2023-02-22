class Solution {
public:
    bool isPal(string &s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--]){
                return 0;
            }
        }
        return 1;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string res;
        for (int i = 0; i < n && res.size() < n - i; i++)
        {
            for (int j = i; j < n; j++)
            {
                int size = j - i + 1;
                if(size > res.size() && isPal(s, i, j)){
                    res = s.substr(i, size);
                }
            }
        }
        return res;
    }
};