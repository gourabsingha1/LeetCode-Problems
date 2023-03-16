class Solution {
public:
    string multiply(string num1, string num2) {
        string res;
        if(num1 == "0" || num2 == "0"){
            return "0";
        }
        
        int n = num1.size() + num2.size();
        for (int i = 0; i < n; i++)
        {
            res += '0';
        }
        
        int k = n - 1, carry = 0, K = k;
        for (int i = num1.size() - 1; i >= 0 ; i--)
        {
            for (int j = num2.size() - 1; j >= 0 ; j--)
            {
                int x = (num1[i] - '0') * (num2[j] - '0') + carry + res[k] - '0';
                res[k--] = x % 10 + '0';

                carry = x / 10;
            }
            if(carry){
                res[k] = carry + '0';
                carry = 0;
            }
            k = --K;
        }

        for (int i = 0; i < res.size(); i++)
        {
            if(res[i] != '0'){
                return res.substr(i, n - i);
            }
        }
        return res;
    }
};