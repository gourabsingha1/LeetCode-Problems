class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        string push = "Push", pop = "Pop";
        int num = 1;
        for(auto& t : target) {
            while(num != t) {
                res.push_back(push);
                res.push_back(pop);
                num++;
            }
            res.push_back(push);
            num++;
        }
        return res;
    }
};