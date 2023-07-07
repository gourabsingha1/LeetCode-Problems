class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        unordered_map<char, bool> mp;
        for(auto& ch : s) {
            mp[ch] = 1;
        }
        
        for (char ch = 'A'; ch <= 'Z'; ch++)
        {
            if(!mp[ch]) continue;
            
            int cnt = 0;
            for (int i = 0, j = 0; i < s.size(); i++)
            {
                if(s[i] != ch) {
                    cnt++;
                }
                while(cnt > k) {
                    if(s[j] != ch) {
                        cnt--;
                    }
                    j++;
                }
                int size = i - j + 1;
                res = max(res, size);
            }
        }
        return res;
    }
};