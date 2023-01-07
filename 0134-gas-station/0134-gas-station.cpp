class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int firstPos = 1, res = 0, sum = 0, limit = 0, n = gas.size();
        for (int i = 0; i < n; i++)
        {
            gas[i] -= cost[i];
            limit += gas[i];
            sum += gas[i];
            if(limit >= 0 && firstPos){
                res = i;
                firstPos = 0;
            }
            else if(limit < 0){
                limit = 0;
                firstPos = 1;
            }
        }
        if(sum < 0) return -1;
        return res;
    }
};