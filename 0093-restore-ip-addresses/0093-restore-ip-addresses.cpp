class Solution {
public:
    void helper(int i, int dots, string curr, string ip, vector<string> &res, string &s){
        if(curr.size() > 1 && curr[0] == '0' && curr[1] != '.' || ip[0] == '.' || ip.size() > 1 && ip.substr(ip.size() - 2) == ".." || curr.size() && stoi(curr) > 255 || dots > 3){
            return;
        }
        if(i == s.size()){
            if(dots == 3){
                res.push_back(ip);
            }
            return;
        }
        helper(i + 1, dots, curr + s[i], ip + s[i], res, s);
        helper(i, dots + 1, "", ip + '.', res, s);
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        helper(0, 0, "", "", res, s);
        return res;
    }
};