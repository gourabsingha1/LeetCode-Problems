class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rq, dq;
        int n = senate.size();
        for (int i = 0; i < n; i++)
        {
            if(senate[i] == 'R') {
                rq.push(i);
            }
            else {
                dq.push(i);
            }
        }
        while(rq.size() && dq.size()) {
            if(rq.front() < dq.front()) {
                rq.push(rq.front() + n);
            }
            else {
                dq.push(dq.front() + n);
            }
            rq.pop(), dq.pop();
        }
        if(rq.size()) return "Radiant";
        return "Dire";
    }
};