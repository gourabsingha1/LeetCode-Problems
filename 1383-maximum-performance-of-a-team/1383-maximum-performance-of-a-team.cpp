class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        long long res = 0, curr = 0, M = 1e9 + 7;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({efficiency[i], speed[i]});
        }
        sort(v.rbegin(), v.rend());
        priority_queue<int, vector<int>, greater<>> minHeap;
        for (int i = 0; i < n; i++)
        {
            curr = (curr + v[i].second);
            minHeap.push(v[i].second);
            if(i >= k){
                curr -= minHeap.top();
                minHeap.pop();
            }
            res = max(res, curr * v[i].first);
        }
        return res % M;
    }
};