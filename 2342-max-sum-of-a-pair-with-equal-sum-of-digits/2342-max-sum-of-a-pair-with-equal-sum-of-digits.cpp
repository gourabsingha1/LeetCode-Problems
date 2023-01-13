class Solution {
public:
    int digitsSum(int a){
        int res = 0;
        while(a){
            res += a%10;
            a /= 10;
        }
        return res;
    }
    int maximumSum(vector<int>& nums) {
        int res = -1;
        unordered_map<int, priority_queue<int>> m;
        for(auto &x : nums){
            m[digitsSum(x)].push(x);
        }
        for(auto &[x, y] : m){
            if(y.size() == 1) continue;
            int a = y.top(), b; y.pop();
            b = y.top();
            res = max(res, a + b);
        }
        return res;
    }
};