class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int res = 0, y = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] < y){
                res++;
                if(intervals[i][1] < y){
                    y = intervals[i][1];
                }
            }
            else{
                y = intervals[i][1];
            }
        }
        return res;
    }
};