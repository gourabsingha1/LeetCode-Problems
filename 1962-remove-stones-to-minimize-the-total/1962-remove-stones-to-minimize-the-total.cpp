class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int res = 0;
        priority_queue<int> pq;
        for(auto &x : piles){
            pq.push(x);
            res += x;
        }
        while(k--){
            int x = pq.top();
            res -= x/2;
            x = (x+1)/2;
            pq.pop(), pq.push(x);
        }
        return res;
    }
};