class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n, 1);
        for (int i = 1; i < n; i++)
        {
            if(ratings[i - 1] < ratings[i]){
                left[i] = left[i - 1] + 1;
            }
        }
        int res = left[n - 1], next = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if(ratings[i] > ratings[i + 1]){
                next++;
            }
            else{
                next = 1;
            }
            res += max(next, left[i]);
        }
        return res;
    }
};