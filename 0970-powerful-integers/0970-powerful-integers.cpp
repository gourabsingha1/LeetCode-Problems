class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> res;
        unordered_map<int, bool> m;
        int prevI = -1;
        for (int i = 1; i < bound && i != prevI; i *= x)
        {
            int prevJ = -1;
            for (int j = 1; i + j <= bound && j != prevJ; j *= y)
            {
                if(!m[i + j]){
                    res.push_back(i + j);
                    m[i + j] = 1;
                }
                prevJ = j;
            }
            prevI = i;
        }
        return res;
    }
};