class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int res = -1, cnt = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < trust.size(); i++)
        {
            m[trust[i][0]] = -1000;
            m[trust[i][1]]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if(m[i] == n - 1){
                res = i;
                cnt++;
            }
        }
        if(cnt > 1){
            return -1;
        }
        return res;
    }
};