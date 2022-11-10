class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        for(auto &x : s){
            if(!ans.empty() && x == ans[ans.size()-1]){
                ans.pop_back();
            }
            else{
                ans.push_back(x);
            }
        }
        return ans;
    }
};