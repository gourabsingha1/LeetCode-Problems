class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string res;
        int i = 0, j = 0, n = sentence.size();
        unordered_map<string, bool> m;
        for (int i = 0; i < dictionary.size(); i++) m[dictionary[i]] = 1;
        while(i < n){
            res += sentence[i++];
            if(m[sentence.substr(j, i - j)]){
                while(i < n && sentence[i] != ' ') i++;
            }
            if(i < n && sentence[i] == ' '){
                j = i + 1;
            }
        }
        return res;
    }
};