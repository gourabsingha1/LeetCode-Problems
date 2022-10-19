class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        while(n--){
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
        }
        return s[k-1];
    }
};