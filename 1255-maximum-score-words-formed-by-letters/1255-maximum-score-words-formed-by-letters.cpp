class Solution {
public:
    // recursion
    int helper(int i, vector<string>& words, vector<int>& letters, vector<int>& score) {
        if(i == words.size()) {
            return 0;
        }
        vector<int> freq(26, 0);
        for(auto& c : words[i]) {
            freq[c - 'a']++;
        }
        bool flag = 0;
        for (int j = 0; j < 26; j++)
        {
            if(freq[j] > letters[j]) {
                flag = 1;
                break;
            }
        }
        if(flag) {
            return helper(i + 1, words, letters, score);
        }
        int take = 0;
        for (int j = 0; j < 26; j++)
        {
            letters[j] -= freq[j];
            take += score[j] * freq[j];
        }
        take += helper(i + 1, words, letters, score);
        for (int j = 0; j < 26; j++)
        {
            letters[j] += freq[j];
        }
        int notTake = helper(i + 1, words, letters, score);
        return max(take, notTake);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> le(26, 0);
        for (int i = 0; i < letters.size(); i++)
        {
            le[letters[i] - 'a']++;
        }
        return helper(0, words, le, score);
    }
};