class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size(), sum = 0, ma = 0;
        for (int i = 1; i < n; i++)
        {
            if(colors[i] == colors[i-1]){
                if(!ma){
                    sum += neededTime[i-1];
                    ma = neededTime[i-1];
                }
                sum += neededTime[i];
                ma = max(ma, (int)neededTime[i]);
            }
            else{
                sum -= ma;
                ma = 0;
            }
        }
        if(colors[n-1] == colors[n-2]){
            sum -= ma;
        }
        return sum;
    }
};