class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int n) {
        int l = 1, h = 1e9;
        while(l <= h){
            int m = h + (l-h)/2, sum = 0;
            for(int &x : piles){
                sum += ((x+m-1)/m);
            }
            if(sum > n){
                l = m + 1;
            }
            else{
                h = m - 1;
            }
        }
        return l;
    }
};