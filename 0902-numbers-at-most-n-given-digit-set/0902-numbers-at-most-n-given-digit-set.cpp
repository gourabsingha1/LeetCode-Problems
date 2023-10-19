// for all number with one less no of digits than n
// res += pow(digits.size(), size(n)--)
// rest, do dry run

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int res = 0, dSize = digits.size();
        string ns = to_string(n);
        for (int i = 1; i < ns.size(); i++)
        {
            res += pow(dSize, i);
        }
        
        for (int i = 0; i < ns.size(); i++)
        {
            bool hasSameNum = 0;
            for(auto& digit : digits) {
                char ch = digit[0];
                if(ch < ns[i]) {
                    res += pow(dSize, ns.size() - 1 - i);
                }
                else {
                    hasSameNum = ch == ns[i];
                    break;
                }
            }
            
            // if there is no same number, then there's no point of calculating further bc they are already included
            if(!hasSameNum) return res;
        }
        return res + 1;
    }
};