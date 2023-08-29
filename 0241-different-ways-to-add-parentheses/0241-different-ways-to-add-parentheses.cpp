class Solution {
public:
    unordered_map<string, vector<int>> dp;

    vector<int> helper(string s) {
        if(dp.find(s) != dp.end()) {
            return dp[s];
        }

        vector<int> res;
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i] == '+' || s[i] == '-' || s[i] == '*') {
                vector<int> left = helper(s.substr(0, i));
                vector<int> right = helper(s.substr(i + 1));
                for(auto& l : left) {
                    for(auto& r : right) {
                        if(s[i] == '+') {
                            res.push_back(l + r);
                        }
                        else if(s[i] == '-') {
                            res.push_back(l - r);
                        }
                        else {
                            res.push_back(l * r);
                        }
                    }
                }
            }
        }
        
        if(res.size() == 0) {
            res.push_back(stoi(s));
        }
        return dp[s] = res;
    }

    vector<int> diffWaysToCompute(string expression) {
        return helper(expression);
    }
};