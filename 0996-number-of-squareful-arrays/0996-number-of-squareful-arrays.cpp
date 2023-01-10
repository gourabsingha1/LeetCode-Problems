class Solution {
public:
    void helper(int n, int prev, unordered_map<int, int> &m, vector<int> v, vector<vector<int>> &res){
        if(v.size() == n){
            res.push_back(v);
            return;
        }
        for(auto &[x, y] : m){
            if(!y || v.size() && !isSquare(prev + x)) continue;
            v.push_back(x);
            y--;
            helper(n, x, m, v, res);
            v.pop_back();
            y++;
        }
    }
    bool isSquare(int n){
        int sq = sqrt(n);
        return sq*sq == n;
    }
    int numSquarefulPerms(vector<int>& nums) {
        int ans = 0;
        vector<vector<int>> res;
        unordered_map<int, int> m;
        for(auto &x : nums) m[x]++;
        helper(nums.size(), 0, m, {}, res);
        for(auto &v : res){
            ans++;
            for (int i = 1; i < v.size(); i++)
            {
                if(!isSquare(v[i - 1] + v[i])){
                    ans--;
                    break;
                }
            }
        }
        return ans;
    }
};