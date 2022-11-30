class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long res = 0;
        int a = INT_MAX, c = 0;
        for(auto &v : matrix){
            for(auto &x : v){
                res += abs(x);
                if(x < 0){
                    c++;
                }
                a = min(a, abs(x));
            }
        }
        if(c&1){
            res -= 2*a;
        }
        return res;
    }
};