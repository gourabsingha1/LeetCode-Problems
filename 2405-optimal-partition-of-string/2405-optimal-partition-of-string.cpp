class Solution {
public:
    int partitionString(string s) {
        int res = 1;
        vector<int> m(26, 0), mp(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            m[s[i] - 'a']++;
            if(m[s[i] - 'a'] == 2){
                m = mp;
                m[s[i] - 'a']++;
                res++;
            }
        }
        return res;
    }
};