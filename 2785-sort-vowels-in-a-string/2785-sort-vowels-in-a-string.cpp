class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    
    string sortVowels(string s) {
        string res(s.size(), '.'), vowels;
        for (int i = 0; i < s.size(); i++)
        {
            if(!isVowel(s[i])) {
                res[i] = s[i];
            }
            else {
                vowels.push_back(s[i]);
            }
        }
        sort(vowels.begin(), vowels.end());
        for (int i = 0, j = 0; i < s.size() && j < vowels.size(); i++)
        {
            if(res[i] == '.') res[i] = vowels[j++];
        }
        return res;
    }
};