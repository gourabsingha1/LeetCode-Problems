class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_map<char,int> m;
        int j = 0;
        for (int i = 0; i < s.size(); i++)
        {
            while(m[s[i]]){
                m[s[j]]--;
                j++;
            }
            res = max(res, i-j+1);
            m[s[i]]++;
        }
        return res;
    }
};