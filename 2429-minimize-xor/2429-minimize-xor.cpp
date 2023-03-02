class Solution {
public:
    string decToBin(int n){
        string res;
        while(n){
            if(n & 1) res = '1' + res;
            else res = '0' + res;
            n /= 2;
        }
        return res;
    }
    int binToDec(string& s){
        int n = s.size(), cnt = 0, res = 0;
        while(n--){
            res += (s[n] == '1') * (1 << cnt);
            cnt++;
        }
        return res;
    }
    int minimizeXor(int num1, int num2) {
        string s = decToBin(num1);
        int cnt = __builtin_popcount(num2), n = s.size();
        string res(n, '0');
        for (int i = 0; i < n && cnt; i++)
        {
            if(s[i] == '1') {
                res[i] = '1';
                cnt--;
            }
        }
        if(cnt) {
            while(n-- && cnt) {
                if(s[n] == '0') {
                    res[n] = '1';
                    cnt--;
                }
            }
            string temp(cnt, '1');
            res = temp + res;
        }
        return binToDec(res);
    }
};