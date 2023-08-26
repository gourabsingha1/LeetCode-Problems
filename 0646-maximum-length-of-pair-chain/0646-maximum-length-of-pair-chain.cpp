class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b){
        return a[1] < b[1];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int res = 1;
        sort(pairs.begin(), pairs.end(), cmp);
        for (int i = 1, j = 0; i < pairs.size(); i++)
        {
            if(pairs[j][1] < pairs[i][0]) {
                res++, j = i;
            }
        }
        return res;
    }
};