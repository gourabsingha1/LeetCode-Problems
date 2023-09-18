class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res(k, 0);
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < mat.size(); i++)
        {
            int low = 0, high = mat[0].size() - 1;
            while(low <= high) {
                int mid = (low + high) / 2;
                if(mat[i][mid] == 1) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
            if(pq.size() == k) {
                if(pq.top().first > low) {
                    pq.pop();
                    pq.push({low, i});
                }
            }
            else {
                pq.push({low, i});
            }
        }
        while(k-- && pq.size()) {
            res[k] = pq.top().second;
            pq.pop();
        }
        return res;
    }
};