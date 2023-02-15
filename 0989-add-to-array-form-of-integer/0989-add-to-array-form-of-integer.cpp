class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> res;
        int n = num.size();
        bool carry = 0;
        while(n && k){
            int sum = num[--n] + k % 10 + carry;
            res.push_back(sum % 10);
            carry = sum > 9;
            k /= 10;
        }
        while(n--){
            int sum = num[n] + carry;
            res.push_back(sum % 10);
            carry = sum > 9;
        }
        while(k){
            int sum = k % 10 + carry;
            res.push_back(sum % 10);
            carry = sum > 9;
            k /= 10;
        }
        if(carry){
            res.push_back(1);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};