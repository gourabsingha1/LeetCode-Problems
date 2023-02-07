class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), res = 0, curr = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        if(k == n){
            return curr;
        }
        k = n - k;
        for (int i = 0, j = 0; i < n; i++)
        {
            curr -= cardPoints[i];
            if(i + 1 >= k){
                res = max(res, curr);
                curr += cardPoints[j++];
            }
        }
        return res;
    }
};