class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        int n = sentence1.size() - 1, m = sentence2.size() - 1;
        if(n < m){
            return areSentencesSimilar(sentence2, sentence1);
        }
        else if(n == m){
            return sentence1 == sentence2;
        }

        if(sentence1[m + 1] == ' ' && sentence1.substr(0, m + 1) == sentence2 || sentence1[n - m - 1] == ' ' &&  sentence1.substr(n - m, m + 1) == sentence2){
            return 1;
        }
        while(m >= 0 && sentence1[n] == sentence2[m]){
            n--, m--;
        }
        return sentence1.substr(0, m + 2) == sentence2.substr(0, m + 2) && sentence1[m + 1] == ' ';
    }
};