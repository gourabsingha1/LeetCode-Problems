class Solution {
public:
    static bool cmp(int& a, int& b) {
        int cntA = __builtin_popcount(a), cntB = __builtin_popcount(b);
        
        // return in ascending order
        if(cntA == cntB) {
            return a < b;
        }
        return cntA < cntB;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};