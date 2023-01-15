class Solution {
public:
    static bool sortbyvector(const vector<int> &a, const vector<int> &b){
        return a[1] < b[1];
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), sortbyvector);
        int curr = trips[0][0], ma = curr, n = trips.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        pq.push({trips[0][2], trips[0][0]});
        for (int i = 1; i < n; i++)
        {
            curr += trips[i][0];
            pq.push({trips[i][2], trips[i][0]});
            while(pq.size() && pq.top().first <= trips[i][1]){
                curr -= pq.top().second;
                pq.pop();
            }
            ma = max(ma, curr);
        }
        return ma <= capacity;
    }
};