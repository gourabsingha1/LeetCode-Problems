class Solution {
public:
    // pos, tight, prev
    int dp[100][2][11];

    int M = 1e9 + 7;

    int helper(string& s, int pos = 0, bool tight = 1, int prev = -1) {
        if(pos == s.size()) {
            return 1;
        }
        if(dp[pos][tight][prev + 1] != -1) {
            return dp[pos][tight][prev + 1];
        }

        int res = 0, ub = tight ? s[pos] - '0' : 9;
        for (int i = 0; i <= ub; i++)
        {
            if(prev == -1 && i == 0) { // leading zero
                res = (res + helper(s, pos + 1, tight & (i == ub), prev)) % M;
                continue;
            }
            if(prev == -1 || abs(prev - i) == 1) {
                res = (res + helper(s, pos + 1, tight & (i == ub), i)) % M;
            }
        }
        return dp[pos][tight][prev + 1] = res;
    }
    
    // str1 > str2
    string findDiff(string str1, string str2) {
        string str = ""; 
        int n1 = str1.length(), n2 = str2.length(), diff = n1 - n2, carry = 0; 
        for (int i = n2 - 1; i >= 0; i--) { 
            int sub = ((str1[i + diff] - '0') - (str2[i] - '0') 
                    - carry); 
            if (sub < 0) { 
                sub = sub + 10; 
                carry = 1; 
            } 
            else
                carry = 0; 
            str.push_back(sub + '0'); 
        } 
        for (int i = n1 - n2 - 1; i >= 0; i--) { 
            if (str1[i] == '0' && carry) { 
                str.push_back('9'); 
                continue; 
            } 
            int sub = ((str1[i] - '0') - carry); 
            if (i > 0 || sub > 0) 
                str.push_back(sub + '0'); 
            carry = 0; 
        }

        reverse(str.begin(), str.end()); 
        return str; 
    }

    int countSteppingNumbers(string low, string high) {
        low = findDiff(low, "1");
        memset(dp, -1, sizeof(dp));
        int res1 = helper(low);
        memset(dp, -1, sizeof(dp));
        int res2 = helper(high);
        return (res2 - res1 + M) % M;
    }
};