class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()){
            return 0;
        }
        vector<int> w1(26, 0), w2(26, 0), a, b;
        for (int i = 0; i < word1.size(); i++)
        {
            w1[word1[i]-'a']++;
            w2[word2[i]-'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if(w1[i] && !w2[i] || !w1[i] && w2[i]) return 0;
            if(w1[i]) a.push_back(w1[i]);
            if(w2[i]) b.push_back(w2[i]);
        }
        sort(a.begin(), a.end()), sort(b.begin(), b.end());
        
        return a == b;
    }
};