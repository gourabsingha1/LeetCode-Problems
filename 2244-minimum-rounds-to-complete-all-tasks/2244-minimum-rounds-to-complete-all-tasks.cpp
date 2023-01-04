class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int res = 0;
        unordered_map<int, int> m;
        for(auto &x : tasks) m[x]++;
        for(auto &[x, y] : m){
            if(y == 1) return -1;
            res += y/3 + 1;
            if(y%3 == 0) res--;
        }
        return res;
    }
};