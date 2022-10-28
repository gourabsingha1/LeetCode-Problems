class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int n = queries.size();
        vector<bool> res(n,1);
        for(int ind = 0; ind < n; ind++)
        {
            int m = pattern.size(), j = 0, flag = 0;
            for (int i = 0; i < queries[ind].size(); i++)
            {
                if(j < m && queries[ind][i] == pattern[j]){
                    j++;
                }
                else if(isupper(queries[ind][i])){
                    flag = 1;
                    break;
                }
            }
            if(j != m || flag){
                res[ind] = 0;
            }
        }
        return res;
    }
};