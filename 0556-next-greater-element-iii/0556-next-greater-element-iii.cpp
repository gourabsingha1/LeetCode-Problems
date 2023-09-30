class Solution {
public:
    string nextPermutation(string s) {
        int i = s.size() - 1;
        while(i > 0 && s[i - 1] >= s[i]) {
            i--;
        }
        if(i == 0) {
            return "-1";
        }

        int j = s.size() - 1;
        while(j > 0 && s[j] <= s[i - 1]) {
            j--;
        }
        swap(s[j], s[i - 1]);
        reverse(s.begin() + i, s.end());
        return s;
    }

    int nextGreaterElement(int n) {
        string next = nextPermutation(to_string(n));
        long res = stol(next);
        if(res == -1 || res > INT_MAX) {
            return -1;
        }
        return res;
    }
};