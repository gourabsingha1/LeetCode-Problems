class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int res = 0, flag = 0;
        map<string, int> m;
        for(auto &s : words) m[s]++;
        for(auto &[x, y] : m){
            string p;
            p += x[1], p += x[0];
            if(x[0] == x[1]){
                res += ((y/2)*4);
                y = y % 2;
                if(!flag) flag = y;
            }
            else if(m[p]){
                int mi = min(y, m[p]);
                res += mi * 4;
                y -= mi, m[p] -= mi;
            }
        }
        if(flag){
            res += 2;
        }
        return res;
    }
};