class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx == fx && sy == fy) return t != 1;
        int x = min(abs(fx - sx), abs(fy - sy));
        if(fx < sx) swap(fx, sx);
        if(fy < sy) swap(fy, sy);
        return x + (fx - sx - x) + (fy - sy - x) <= t;
    }
};