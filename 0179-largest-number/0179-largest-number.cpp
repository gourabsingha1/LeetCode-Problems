class Solution {
public:
    static bool cmp(string& s1, string& s2) {
        return s1 + s2 > s2 + s1;
    }
    string largestNumber(vector<int>& nums) {
        string res;
        int zero = 0; // [0, 0]
        vector<string> temp;
        for(auto& num : nums) {
            temp.push_back(to_string(num));
            if(num == 0) {
                zero++;
            }
        }
        if(zero == nums.size()) {
            return "0";
        }
        
        sort(temp.begin(), temp.end(), cmp);
        for(auto& s : temp) {
            res += s;
        }
        return res;
    }
};