class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res, ml(26, 0), mr(26, 0);
        int n = s.size(), k = 0;
        for (int i = 0; i < n; i++) mr[s[i] - 'a']++;
        for (int i = 0; i < n; i++)
        {
            ml[s[i] - 'a']++;
            mr[s[i] - 'a']--;
            bool flag = 1;
            for (int j = 0; j < 26; j++)
            {
                if(ml[j] && mr[j]){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                res.push_back(i - k + 1);
                k = i + 1;
            }
        }
        return res;
    }
};