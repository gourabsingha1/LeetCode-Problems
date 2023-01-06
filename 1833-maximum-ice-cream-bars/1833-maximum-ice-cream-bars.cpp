class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int res = 0;
        for(auto &x : costs){
            coins -= x;
            if(coins < 0) break;
            res++;
        }
        return res;
    }
};