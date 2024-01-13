class Solution {
public:
    int minSteps(string s, string t) { 
        int res = 0;
        vector<int> freq(26, 0);
        for(int i = 0; i < s.size(); i++)
        {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++)
        {
            if(freq[i] > 0){
                res += freq[i];
            }
        }
        return res;
    }
};