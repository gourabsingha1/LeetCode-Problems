class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long res = 0;
        unordered_map<int, vector<string>> m;
        for (int i = 0; i < ideas.size(); i++)
        {
            m[ideas[i][0] - 'a'].push_back(ideas[i].substr(1));
        }
        for (int i = 0; i < 26; i++)
        {
            unordered_map<string, bool> mp;
            for (int j = 0; j < m[i].size(); j++)
            {
                mp[m[i][j]] = 1;
            }
            for (int j = i + 1; j < 26; j++)
            {
                int a = m[i].size(), b = m[j].size();
                for (int k = 0; k < m[j].size(); k++)
                {
                    if(mp[m[j][k]]){
                        a--, b--;
                    }
                }
                res += 2 * a * b;
            }
        }
        return res;
    }
};