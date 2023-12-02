// brute force

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int res = 0;
        vector<int> freq(26, 0);
        for(auto& ch : chars) {
            freq[ch - 'a']++;
        }
        for(auto& word : words) {
            vector<int> temp = freq;
            bool exceed = 0;
            for(auto& ch : word) {
                if(--temp[ch - 'a'] < 0) {
                    exceed = 1;
                    break;
                }
            }
            if(!exceed) {
                res += word.size();
            }
        }
        return res;
    }
};