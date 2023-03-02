class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> res;
        vector<bool> inDegree(n);
        for (int i = 0; i < edges.size(); i++)
        {
            inDegree[edges[i][1]] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            if(!inDegree[i]) {
                res.push_back(i);
            }
        }
        return res;
    }
};