class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        double x1 = coordinates[0][0], y1 = coordinates[0][1], x2 = coordinates[1][0], y2 = coordinates[1][1];
        double m = (x1 - x2) / (y1 - y2);
        for (int i = 0; i < n; i++)
        {
            x1 = coordinates[i][0], y1 = coordinates[i][1];
            for (int j = i + 1; j < n; j++)
            {
                if(y1 == y2) continue;
                x2 = coordinates[j][0], y2 = coordinates[j][1];
                double m1 = (x1 - x2) / (y1 - y2);
                if(m != m1) {
                    return 0;
                }
            }
        }
        return 1;
    }
};