class Solution {
public:
    bool isNumber(string s) {
        int dot = 0, n = s.size(), eInd = n;
        if(n == 1 || s.substr(0, 2) == ".e") {
            return isdigit(s[0]);
        }
        // split the string at the position of 'e'
        for (int i = 0; i < n; i++)
        {
            if(s[i] == 'e' || s[i] == 'E') {
                eInd = i;
                if(eInd == 0 || eInd == n - 1) {
                    return 0;
                }
                break;
            }
        }
        if(eInd == 2 && (s.substr(0, 2) == "+." || s.substr(0, 2) == "-.")) {
            return 0;
        }
        // check if the part till 'e' is double / integer
        for (int i = 0; i < eInd; i++)
        {
            if(i == 0 && i + 1 < eInd && (s[i] == '+' || s[i] == '-')) {
                continue;
            }
            if(s[i] == '.') {
                dot++;
            }
            else if(!isdigit(s[i])) {
                return 0;
            }
        }
        // check if the part after 'e' is integer
        for (int i = eInd + 1; i < n; i++)
        {
            if(i == eInd + 1 && i + 1 < n && (s[i] == '+' || s[i] == '-')) {
                continue;
            }
            if(!isdigit(s[i])) {
                return 0;
            }
        }
        return dot < 2;
    }
};