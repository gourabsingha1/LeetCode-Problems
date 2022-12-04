class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long int l = 1, h = 1e7;
        while(l <= h){
            long long int m = h + (l-h)/2, sum = 0;
            for(int &x : candies){
                sum += x/m;
            }
            if(sum >= k){
                l = m + 1;
            }
            else{
                h = m - 1;
            }
        }
        return h;
    }
};