// Since we'll be progressing through courses as if we're progressing through time,
// we'll want to sort courses based on the courses' cutoffs (end)
// but when we backtrack to potentially remove a course
// we'll want to sort the courses we've accepted by their duration (dur).

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    int scheduleCourse(vector<vector<int>>& courses) {
        int cur = 0, n = courses.size();
        sort(courses.begin(), courses.end(), cmp);
        priority_queue<int> pq;
        for (int i = 0, j = 0; i < n; i++)
        {
            int duration = courses[i][0], time = courses[i][1];
            cur += duration;
            pq.push(duration);
            if(cur > time) {
                cur -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};