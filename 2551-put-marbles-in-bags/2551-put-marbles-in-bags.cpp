// a  |  b  |  c  |  d  |  e  |  f
//  (a+b) (b+c) (c+d) (d+e) (e+f) these are pairs out of which we need to
// select (k-1) minimum and maximum pairs
// the leftmost and rightmost element will make a pair and we have to include that always.

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if(n == 1) {
            return 0;
        }
        
        vector<int> pairs;
        for (int i = 1; i < n; i++)
        {
            pairs.push_back(weights[i - 1] + weights[i]);
        }
        sort(pairs.begin(), pairs.end());

        long long minScore = weights[0] + weights[n - 1];
        long long maxScore = weights[0] + weights[n - 1];
        for (int i = 0; i < k - 1; i++)
        {
            minScore += pairs[i];
            maxScore += pairs[n - 2 - i];
        }
        return maxScore - minScore;
    }
};