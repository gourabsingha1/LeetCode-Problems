class Solution {
public:
    vector<string> keypad = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void helper(string temp, int i, string& digits, vector<string>& res) {
        if(i == digits.size()){
            res.push_back(temp);
            return;
        }
        
        for(auto& ch : keypad[digits[i] - '2'])
        {
            helper(temp + ch, i + 1, digits, res);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(!digits.size()) {
            return {};
        }
        
        vector<string> res;
        helper("", 0, digits, res);
        return res;
    }
};