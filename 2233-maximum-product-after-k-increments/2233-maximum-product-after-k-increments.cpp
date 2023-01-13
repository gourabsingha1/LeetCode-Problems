class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        long long res = 1, M = 1e9 + 7;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int &x : nums) pq.push(x);
        while(k--){
            int x = pq.top();
            pq.pop();
            pq.push(x + 1);
        }
        while(pq.size()){
            res = (res * pq.top())%M;
            pq.pop();
        }
        return res;
    }
};