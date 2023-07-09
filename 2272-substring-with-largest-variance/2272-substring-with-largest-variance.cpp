class Solution {
public:
    int helper(string& s) {
        int res = 0;
        for (char ch1 = 'a'; ch1 <= 'z'; ch1++)
        {
            for (char ch2 = 'a'; ch2 <= 'z'; ch2++)
            {
                int cnt1 = 0, cnt2 = 0;
                for(char& ch : s) {
                    cnt1 += ch == ch1;
                    cnt2 += ch == ch2;
                    if(cnt1 < cnt2) {
                        cnt1 = cnt2 = 0;
                    }
                    else if(cnt2) {
                        res = max(res, cnt1 - cnt2);
                    }
                }
            }
        }
        return res;
    }

    int largestVariance(string s) {
        int same = helper(s);
        reverse(s.begin(), s.end());
        int reverse = helper(s);
        return max(same, reverse);
    }
};