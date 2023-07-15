

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int res = 0, curDay = 1, i = 0, n = events.size();
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<>> pq; // endDay
        while(i < n || pq.size()) {
            if(pq.size() == 0) {
                curDay = events[i][0];
            }
            while(i < n && events[i][0] == curDay) {
                pq.push(events[i++][1]);
            }
            pq.pop();
            res++, curDay++;
            while(pq.size() && pq.top() < curDay) {
                pq.pop();
            }
        }
        return res;
    }
};