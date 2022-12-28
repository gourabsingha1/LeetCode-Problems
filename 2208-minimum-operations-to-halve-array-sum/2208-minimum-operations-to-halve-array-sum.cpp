class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum = 0, res = 0;
        priority_queue<double> pq;
        for(auto &x : nums){
            pq.push(x);
            sum += x;
        }
        double temp = sum;
        while(temp > sum/2){
            res++;
            double x = pq.top();
            x /= 2;
            temp -= x;
            pq.pop(), pq.push(x);
        }
        return res;
    }
};