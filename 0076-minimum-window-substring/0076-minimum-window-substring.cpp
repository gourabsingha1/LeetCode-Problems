class Solution {
public:
    string minWindow(string s, string t) {
        string res;
        unordered_map<char, int> ms, mt;
        for(char &c : t) mt[c]++;
        int have = 0, need = mt.size(), j = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if(mt[s[i]]){
                ms[s[i]]++;
                if(ms[s[i]] == mt[s[i]]) have++;
            }
            if(have == need){
                while(j<s.size() && ms[s[j]] >= mt[s[j]] && have == need){
                    if(ms[s[j]]){
                        ms[s[j]]--;
                        if(ms[s[j]] < mt[s[j]]) have--;
                    }
                    j++;
                }
                if(!res.size() || res.size() > i-j+2){
                    res = s.substr(j-1, i-j+2);
                }
            }
        }
        return res;
    }
};