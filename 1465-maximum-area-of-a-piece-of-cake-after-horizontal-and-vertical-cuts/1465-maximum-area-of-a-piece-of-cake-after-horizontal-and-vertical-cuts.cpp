class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int M = 1e9 + 7;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int maxHor = max(horizontalCuts[0], h - horizontalCuts.back());
        int maxVer = max(verticalCuts[0], w - verticalCuts.back());
        for (int i = 1; i < horizontalCuts.size(); i++)
        {
            maxHor = max(maxHor, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        for (int i = 1; i < verticalCuts.size(); i++)
        {
            maxVer = max(maxVer, verticalCuts[i] - verticalCuts[i - 1]);
        }
        return (1LL * maxHor * maxVer) % M;
    }
};