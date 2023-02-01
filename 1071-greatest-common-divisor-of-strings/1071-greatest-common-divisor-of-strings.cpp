class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string res;
        if(str1 + str2 != str2 + str1) return "";
        res = str1.substr(0, gcd(str1.size(), str2.size()));
        return res;
    }
};