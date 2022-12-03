class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int res = 0, cur = 0;
        for(auto &x : tasks){
            x[0] = x[1] - x[0];
        }
        sort(tasks.rbegin(), tasks.rend());
        for(auto &x : tasks){
            if(cur < x[1]){
                res += (x[1] - cur);
                cur = x[1];
            }
            cur -= (x[1]-x[0]);
        }
        return res;
    }
};