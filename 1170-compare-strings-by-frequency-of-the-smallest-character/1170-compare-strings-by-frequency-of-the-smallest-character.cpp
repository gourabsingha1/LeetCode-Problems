class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> res;
        unordered_map<string,int> ms;
        for(auto &x : words){
            unordered_map<char,int> m;
            int mi = 'z';
            for(auto &y : x){
                m[y]++;
                mi = min(mi, (int)y);
            }
            ms[x] = m[(char)mi];
        }
        for(auto &x : queries){
            unordered_map<char,int> m;
            int mi = INT_MAX;
            for(auto &y : x){
                m[y]++;
                mi = min(mi, (int)y);
            }
            int c = 0;
            for(auto y : words){
                if(ms[y] > m[(char)mi]){
                    c++;
                }
            }
            res.push_back(c);
        }
        return res;
    }
};