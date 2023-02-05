class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ms(26,0), mp(26,0), res;
        for(char &c : p){
            mp[c - 'a']++;
        }
        int j = 0;
        for (int i = 0; i < s.size(); i++)
        {
            ms[s[i] - 'a']++;
            if(i + 1 >= p.size()){
                if(ms == mp){
                    res.push_back(j);
                }
                ms[s[j++] - 'a']--;
            }
        }
        return res;
    }
};