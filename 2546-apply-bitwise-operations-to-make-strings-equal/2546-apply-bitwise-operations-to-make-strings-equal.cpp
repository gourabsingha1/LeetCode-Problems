class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        if(s == target) return 1;
        int one = 0;
        for(auto &c : s){
            if(c == '1'){
                one++;
                break;
            }
        }
        for(auto &c : target){
            if(c == '1'){
                one++;
                break;
            }
        }
        return one == 2;
    }
};