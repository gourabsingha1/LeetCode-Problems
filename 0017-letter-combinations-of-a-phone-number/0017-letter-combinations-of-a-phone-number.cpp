class Solution {
public:
    vector<string> keypad = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void helper(string& temp, int i, string& digits, vector<string>& res) {
        if(i == digits.size()){
            res.push_back(temp);
            return;
        }
        
        for(auto& ch : keypad[digits[i] - '2'])
        {
            temp.push_back(ch);
            helper(temp, i + 1, digits, res);
            temp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(!digits.size()) {
            return {};
        }
        
        vector<string> res;
        string temp;
        helper(temp, 0, digits, res);
        return res;
    }
};