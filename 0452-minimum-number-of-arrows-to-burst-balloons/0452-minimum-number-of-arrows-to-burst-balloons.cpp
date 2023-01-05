class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int lb = points[0][0], ub = points[0][1], res = 1;
        for(auto &x : points){
            if(max(lb, x[0]) <= min(ub, x[1])){
                lb = max(lb, x[0]), ub = min(ub, x[1]);
            }
            else{
                res++;
                lb = x[0], ub = x[1];
            }
        }
        return res;
    }
};