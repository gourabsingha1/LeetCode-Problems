class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int l = 0;
        if(left.size()) {
            l = *max_element(left.begin(), left.end());
        }
        int r = 0;
        if(right.size()) {
            r = n - *min_element(right.begin(), right.end());
        }
        return max(l, r);
    }
};