class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int j = 0, res = 0, maxProfit = 0, f = 1, sum = 0, add = 0, n = gas.size();
        for (int i = 0; i < n; i++)
        {
            gas[i] -= cost[i];
            add += gas[i];
            sum += gas[i];
            // if(gas[i] >= 0){
            //     sum += gas[i];
            // }
            // else{
            //     sum = 0;
            //     j = i + 1;
            // }
            // if(sum > maxProfit){
            //     maxProfit = sum;
            //     res = j;
            // }
            if(add >= 0){
                if(f){
                    res = i;
                    f = 0;
                }
            }
            else{
                add = 0;
                f = 1;
            }
        }
        if(sum < 0) return -1;
        return res;
    }
};