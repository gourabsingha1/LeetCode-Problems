class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int flag = 0;
            for (int j = 0; j < s.size() - 1; j++)
            {
                if(s[j] == '0' && s[j + 1] == '1'){
                    swap(s[j], s[j++ + 1]);
                    flag = 1;
                }
            }
            res += flag;
        }
        return res;
    }
};