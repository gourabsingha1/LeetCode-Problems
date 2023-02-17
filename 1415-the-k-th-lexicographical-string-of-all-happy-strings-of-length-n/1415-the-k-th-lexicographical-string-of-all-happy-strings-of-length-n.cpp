class Solution {
public:
    string res;
    void helper(string curr, int n, int &k){
        if(!n){
            k--;
            if(!k){
                res = curr;
            }
            return;
        }
        for (char c = 'a'; c < 'd'; c++)
        {
            if(curr.back() != c){
                helper(curr + c, n - 1, k);
            }
        }
    }
    string getHappyString(int n, int k) {
        helper("", n, k);
        return res;
    }
};