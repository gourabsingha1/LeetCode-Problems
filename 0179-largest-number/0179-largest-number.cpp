class Solution {
public:
    static bool cmp(int& x, int& y) {
        string s1 = to_string(x), s2 = to_string(y);
        return s1 + s2 > s2 + s1;
    }
    string largestNumber(vector<int>& nums) {
        string res;
        sort(nums.begin(), nums.end(), cmp);
        for(auto& num : nums) {
            res += to_string(num);
        }
        if(res[0] == '0') {
            return "0";
        }
        return res;
    }
};