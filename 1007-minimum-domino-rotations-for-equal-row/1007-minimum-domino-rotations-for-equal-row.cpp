class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> mp(7, 0);
        int n = tops.size(), num = 0;
        for (int i = 0; i < n; i++)
        {
            mp[tops[i]]++;
            if(tops[i] != bottoms[i]) {
                mp[bottoms[i]]++;
            }
            if(mp[tops[i]] == n) {
                num = tops[i];
            }
            if(mp[bottoms[i]] == n) {
                num = bottoms[i];
            }
        }
        if(num == 0) {
            return -1;
        }
        
        int res1 = 0, res2 = 0;
        for (int i = 0; i < n; i++)
        {
            if(tops[i] != num) {
                res1++;
            }
            if(bottoms[i] != num) {
                res2++;
            }
        }
        return min(res1, res2);
    }
};