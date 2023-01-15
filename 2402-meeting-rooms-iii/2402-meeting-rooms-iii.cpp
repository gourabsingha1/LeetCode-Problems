#define ll long long int
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int rooms[101] = {};
        sort(meetings.begin(), meetings.end());
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>> > pq;
        for (int i = 0; i < n; i++)
        {
            pq.push({meetings[0][0], i});
        }
        for (int i = 0; i < meetings.size(); i++)
        {
            while(pq.top().first < meetings[i][0]){
                auto [time, room] = pq.top();
                pq.pop();
                pq.push({meetings[i][0], room});
            }
            auto [time, room] = pq.top();
            pq.pop();
            pq.push({time + meetings[i][1] - meetings[i][0], room});
            rooms[room]++;
        }
        return max_element(begin(rooms), end(rooms)) - begin(rooms);
    }
};