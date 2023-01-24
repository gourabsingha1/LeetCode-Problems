class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string res;
        int n = sentence.size();
        unordered_map<string, bool> m;
        for (int i = 0; i < dictionary.size(); i++) m[dictionary[i]] = 1;
        for (int i = 0; i < n; i++){
            string s;
            bool flag = 1;
            while(i < n && sentence[i] != ' '){
                s += sentence[i++];
                if(m[s]){
                    res += s + " ";
                    flag = 0;
                    while(i < n && sentence[i] != ' ') i++;
                    break;
                }
            }
            if(flag){
                res.append(s + " ");
            }
        }
        res.pop_back();
        return res;
    }
};