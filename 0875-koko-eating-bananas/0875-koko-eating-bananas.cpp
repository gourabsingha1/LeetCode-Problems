class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        while(low <= high){
            int k = high + (low-high)/2;
            int dH = 0;
            for(int &x : piles){
                dH += (x + k - 1)/k;
            }
            if(dH > h){
                low = k + 1;
            }
            else{
                high = k - 1;
            }
        }
        return low;
    }
};