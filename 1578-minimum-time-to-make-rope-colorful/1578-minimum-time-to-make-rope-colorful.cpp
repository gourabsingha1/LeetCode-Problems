// for a consecutive balloon subarray, calculate sum of their neededTimes - max(neededTimes)
// because greedy choice would be to leave the maximum neededTime as it is

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size(), res = 0;
        for (int i = 1; i < n; i++)
        {
            int mx = neededTime[i - 1], cur = neededTime[i - 1];
            while(i < n && colors[i - 1] == colors[i]){
                mx = max(mx, neededTime[i]);
                cur += neededTime[i++];
            }
            res += cur - mx;
        }
        return res;
    }
};