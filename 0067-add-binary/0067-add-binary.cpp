class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i = a.size(), j = b.size(), carry = 0;
        if(i < j){
            return addBinary(b, a);
        }
        while(i && j){
            char c = '0';
            int sum = a[--i] - '0' + b[--j] - '0';
            if(sum == 0){
                if(carry){
                    carry--;
                    c = '1';
                }
            }
            else if(sum == 1){
                if(!carry){
                    c = '1';
                }
            }
            else{
                if(carry){
                    c = '1';
                }
                else{
                    carry++;
                }
            }
            res += c;
        }
        while(i){
            char c = '0';
            if(a[--i] == '1'){
                if(!carry){
                    c = '1';
                }
            }
            else{
                if(carry){
                    carry--;
                    c = '1';
                }
            }
            res += c;
        }
        if(carry){
            res += '1';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};