class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        if(!intervals.size()){
            return {newInterval};
        }
        int n = intervals.size(), x = newInterval[0], y = newInterval[1];
        if(y < intervals[0][0]){
            res.push_back({x, y});
            x = INT_MAX;
        }

        for (int i = 0; i < n; i++)
        {
            // overlaps
            if(x <= intervals[i][1]){
                if(y < intervals[i][0]){
                    res.push_back({x, y});
                    x = INT_MAX;
                    i--;
                    continue;
                }
                x = min(x, intervals[i][0]);
                while(i + 1 < n && y >= intervals[i + 1][0]) i++;
                y = max(y, intervals[i][1]);
                res.push_back({x, y});
                x = INT_MAX;
            }
            // doesn't overlap
            else{
                res.push_back(intervals[i]);
            }
        }

        if(x != INT_MAX){
            res.push_back({x, y});
        }
        return res;
    }
};