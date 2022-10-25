class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        int res = 0, M = 1e9 + 7;
        unordered_map<int,int> m;
        for (int i = 0; i < deliciousness.size(); i++)
        {
            for (int j = 1; j <= (1<<22); j*=2)
            {
                int target = j - deliciousness[i];
                if(m[target]){
                    res = (res + m[target])%M;
                }
            }
            m[deliciousness[i]]++;
        }
        return res;
    }
};