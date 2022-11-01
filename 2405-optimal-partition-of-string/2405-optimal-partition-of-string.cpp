class Solution {
public:
    int partitionString(string s) {
        int res = 1;
        unordered_map<int,int> m;
        for (int i = 0; i < s.size(); i++)
        {
            m[s[i]]++;
            if(m[s[i]] == 2){
                m.clear();
                m[s[i]]++;
                res++;
            }
        }
        return res;
    }
};