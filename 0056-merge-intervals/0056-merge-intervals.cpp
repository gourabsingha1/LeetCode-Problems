class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        for (int i = 0; i < n; i++)
        {
            int x = intervals[i][0], y = intervals[i][1];
            while(i < n && y >= intervals[i][0]){
                y = max(y, intervals[i++][1]);
            }
            i--;
            res.push_back({x, y});
        }
        return res;
    }
};