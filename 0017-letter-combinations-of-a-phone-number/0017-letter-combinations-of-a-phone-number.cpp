class Solution {
public:
    vector<string> keypad = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        if(digits == ""){
            return {};
        }
        char ch = digits[0];
        string rest = digits.substr(1);
        vector<string> temp = {""};
        if(rest.size()){
            temp = letterCombinations(rest);
        }
        vector<string> res;
        for(string &s : temp){
            for (int i = 0; i < keypad[ch - '2'].size(); i++)
            {
                char c = keypad[ch - '2'][i];
                res.push_back(c + s);
            }
        }
        return res;
    }
};
// 456
// 4 + 56
// 4 = "ghi" // ch
// 56 = ["jm, jn, jo, km, kn,.."] // rest
// res = ["gjm", "gjn", "gjo",..]