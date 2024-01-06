// binary search on answer
// if mid is eligible, we wanna minimize it. so, high = mid - 1

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1, high = 1e5;
        while(low <= high){
            int mid = (low + high) / 2, sum = 0;
            for(auto& x : quantities){
                sum += (x + mid - 1) / mid;
            }
            if(sum <= n){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};