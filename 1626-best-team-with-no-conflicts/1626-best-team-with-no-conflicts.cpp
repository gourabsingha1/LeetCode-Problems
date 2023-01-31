class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size(), res = 0;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({ages[i], scores[i]});
        }
        sort(v.begin(), v.end());
        vector<int> LIS(n);
        for (int i = n - 1; i >= 0; i--)
        {
            LIS[i] = v[i].second;
            int curr = 0;;
            for (int j = i + 1; j < n; j++)
            {
                if(v[i].second <= v[j].second){
                    curr = max(curr, LIS[j]);
                }
            }
            LIS[i] += curr;
            res = max(res, LIS[i]);
        }
        return res;
    }
};