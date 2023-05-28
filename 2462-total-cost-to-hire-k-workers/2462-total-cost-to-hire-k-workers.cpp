// breaking tie condition works because we push 0 if !right
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long res = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; // {value, right}
        int n = costs.size(), i = 0, j = n - 1;
        while(i < candidates)
        {
            pq.push({costs[i++], 0});
            if(j >= candidates) {
                pq.push({costs[j--], 1});
            }
        }

        while(k--) {
            int val = pq.top()[0], right = pq.top()[1];
            pq.pop();
            res += val;
            if(i <= j) {
                if(!right) {
                    pq.push({costs[i++], 0});
                }
                else {
                    pq.push({costs[j--], 1});
                }
            }
        }
        return res;
    }
};