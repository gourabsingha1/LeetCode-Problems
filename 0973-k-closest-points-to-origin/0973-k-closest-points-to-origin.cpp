class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<float, int>, vector<pair<float, int>>, greater<>> pq;
        for (int i = 0; i < points.size(); i++)
        {
            int x = points[i][0], y = points[i][1];
            float dist = x * x + y * y; // sqrt same for all. so we can omitt
            pq.push({dist, i});
        }
        while(k--) {
            int ind = pq.top().second;
            res.push_back(points[ind]);
            pq.pop();
        }
        return res;
    }
};