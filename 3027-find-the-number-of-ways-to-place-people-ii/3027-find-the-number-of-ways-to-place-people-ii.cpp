// sort by x then get the correct y
// track maxY to check if a point lies in bw
// dry run on (4,8), (5,5), (7,6)
// if x & y are valid and the current y is the maximum, then we found a res

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if(a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }

    int numberOfPairs(vector<vector<int>>& points) {
        int res = 0, n = points.size();
        sort(points.begin(), points.end(), cmp);
        for (int i = 0; i < n; i++)
        {
            int maxY = INT_MIN;
            for (int j = i + 1; j < n; j++)
            {
                if(points[i][1] >= points[j][1] && maxY < points[j][1]) {
                    res++, maxY = points[j][1];
                }
            }
        }
        return res;
    }
};