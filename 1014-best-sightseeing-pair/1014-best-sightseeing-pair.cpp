/*
values[i] + values[j] + i - j
= (values[i] + i) + (values[j] - j) || maximize it
*/
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int i = 0, res = 0;
        for (int j = 1; j < values.size(); j++)
        {
            res = max(res, values[i] + values[j] + i - j);
            if(values[j] + j > values[i] + i) {
                i = j;
            }
        }
        return res;
    }
};