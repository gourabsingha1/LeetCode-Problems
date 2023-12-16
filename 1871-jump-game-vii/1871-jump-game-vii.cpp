// bfs 0 -> n - 1
// greedy choice = start next iteration from max(i + minJump, maxCovered + 1)

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if(s.back() != '0') {
            return 0;
        }

        int maxCovered = 0, n = s.size();
        queue<int> q;
        q.push(0);
        while(q.size()) {
            int i = q.front();
            q.pop();
            for (int j = max(i + minJump, maxCovered + 1); j <= min(i + maxJump, n - 1); j++)
            {
                if(s[j] == '0') {
                    q.push(j);
                    if(j == n - 1) {
                        return 1;
                    }
                }
            }
            maxCovered = i + maxJump;
        }
        return 0;
    }
};