class Solution {
public:
    int countOdds(int low, int high) {
        int diff = high - low, res = diff / 2;
        if(diff & 1 || low & 1){
            res++;
        }
        return res;
    }
};