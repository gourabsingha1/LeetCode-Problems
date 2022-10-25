class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        int res = 0, M = 1e9 + 7;
        unordered_map<int,int> m;
        for (int &x : deliciousness)
        {
            for (int j = 1; j <= (1<<22); j*=2)
            {
                int target = j - x;
                if(target >= 0 && m[target]){
                    res = (res + m[target])%M;
                }
            }
            m[x]++;
        }
        return res;
    }
};