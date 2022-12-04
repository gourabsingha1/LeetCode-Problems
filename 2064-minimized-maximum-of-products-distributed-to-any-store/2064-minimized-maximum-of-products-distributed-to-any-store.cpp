class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1, h = *max_element(quantities.begin(), quantities.end()), res = INT_MAX;
        while(l <= h){
            int m = h + (l-h)/2, sum = 0;
            for(int &x : quantities){
                sum += ((x+m-1)/m);
            }
            if(sum <= n){
                res = min(res, m);
                h = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return res;
    }
};