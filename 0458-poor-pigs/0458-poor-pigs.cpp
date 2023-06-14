class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        float t = minutesToTest / minutesToDie + 1;
        int res = ceil(log(buckets) / log(t));
        return res;
    }
};