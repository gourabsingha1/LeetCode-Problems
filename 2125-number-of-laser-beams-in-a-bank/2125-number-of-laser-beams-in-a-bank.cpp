// last = security_devices(banks[j]), cur = security_devices(banks[i])
// if(last > 0 && cur > 0) res += last * cur

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res = 0, last = 0;
        for(auto& b : bank) {
            int cur = 0;
            for(auto& cell : b) {
                cur += cell == '1';
            }
            if(cur) {
                res += last * cur;
                last = cur;
            }
        }
        return res;
    }
};