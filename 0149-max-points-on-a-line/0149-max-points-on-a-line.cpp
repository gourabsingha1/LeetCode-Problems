class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() == 1){
            return 1;
        }
        
        int res = 0;
        for (int i = 0; i < points.size(); i++)
        {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i+1; j < points.size(); j++)
            {
                int x2 = points[j][0], y2 = points[j][1];
                int cnt = 0;
                for (int k = 0; k < points.size(); k++)
                {
                    int x = points[k][0], y = points[k][1];
                    if((y1-y2)*(x-x1) == (x1-x2)*(y-y1)){
                        cnt++;
                    }
                }
                res = max(res, cnt);
            }
        }
        return res;
    }
};