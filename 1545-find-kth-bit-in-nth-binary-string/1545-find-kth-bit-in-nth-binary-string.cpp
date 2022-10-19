class Solution {
public:
    string recurr(int n, string &s){
        if(!n){
            return s;
        }
        string p;
        for(char &c : s){
            if(c == '1'){
                p += '0';
            }
            else{
                p += '1';
            }
        }
        reverse(p.begin(), p.end());
        s += '1';
        s += p;

        recurr(n-1, s);
        return s;
    }
    char findKthBit(int n, int k) {
        string s = "0";
        recurr(n, s);
        return s[k-1];
    }
};