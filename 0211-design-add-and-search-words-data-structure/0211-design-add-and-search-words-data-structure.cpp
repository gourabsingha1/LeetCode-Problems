class WordDictionary {
public:
    vector<string> words;
    
    void addWord(string word) {
        words.push_back(word);
    }
    
    bool search(string word) {
        for(auto& s : words) {
            if(s.size() != word.size()) continue;
            for (int i = 0; i < s.size(); i++)
            {
                if(word[i] != '.' && s[i] != word[i]) {
                    break;
                }
                if(i == word.size() - 1) {
                    return 1;
                }
            }
        }
        return 0;
    }
};