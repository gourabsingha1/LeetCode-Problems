class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size(), j = 0;
        vector<int> m1(26, 0), m2(26, 0);
        for(char &c : s1){
            m1[c-'a']++;
        }

        for (int i = 0; i < m; i++)
        {
            m2[s2[i]-'a']++;
            if(i+1-j == n){
                if(m1 == m2){
                    return 1;
                }
                m2[s2[j++]-'a']--;
            }
        }
        return 0;
    }
};