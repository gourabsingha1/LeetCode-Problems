class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int res = 0, cur = 0;
        vector<pair<int, pair<int, int>>> v;
        for(auto &x : tasks){
            v.push_back({x[1]-x[0], {x[0], x[1]}});
        }
        sort(v.rbegin(), v.rend());
        for(auto &[x,y] : v){
            if(cur < y.second){
                res += (y.second - cur);
                cur = y.second;
            }
            cur -= y.first;
        }
        return res;
    }
};