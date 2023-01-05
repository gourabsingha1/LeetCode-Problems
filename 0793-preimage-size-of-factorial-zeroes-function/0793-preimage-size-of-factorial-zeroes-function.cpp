class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while(n){
            n /= 5;
            res += n;
        }
        return res;
    }
    int preimageSizeFZF(int k) {
        int low = 0, high = 1e9;
        if(k == high) return 5;
        
        while(low <= high){
            int mid = high + (low - high)/2;
            int zeroCnt = trailingZeroes(mid);
            if(zeroCnt == k) return 5;
            else if(zeroCnt > k) high = mid - 1;
            else low = mid + 1;
        }
        return 0;
    }
};