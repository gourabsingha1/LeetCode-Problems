// do dry run on n = 1 and n = 2 and you'll find that
// 1 'a' increases count of 'e', 'u', 'i' by 1
// 1 'e' increases count of 'i', 'a' by 1
// 1 'i' increases count of 'e', 'o' by 1
// 1 'o' increases count of 'i' by 1
// 1 'u' increases count of 'i', 'o' by 1 in next iteration

class Solution {
public:
    unordered_map<char, int> cnt = {{'a', 1}, {'e', 1}, {'i', 1}, {'o', 1}, {'u', 1}};

    int countVowelPermutation(int n) {
        int res = 0, M = 1e9 + 7;
        while(--n) {
            unordered_map<char, int> temp;
            temp['a'] = cnt['e'];
            temp['e'] = (0LL + cnt['a'] + cnt['i']) % M;
            temp['i'] = (0LL + cnt['a'] + cnt['e'] + cnt['o'] + cnt['u']) % M;
            temp['o'] = (0LL + cnt['i'] + cnt['u']) % M;
            temp['u'] = cnt['a'];
            cnt = temp;
        }
        
        for(auto& [ch, freq] : cnt) {
            res = (res + freq) % M;
        }
        return res;
    }
};