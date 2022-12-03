class Solution {
public:
    string frequencySort(string s) {
        string res;
        int n = s.size();
        unordered_map<char,int> m;
        vector<string> bucket(n+1, "");
        for(char &c : s) m[c]++;
        for(auto &[x,y] : m){
            if(!x) return res;
            bucket[y].append(y, x);
        }
        for (int i = n; i > 0; i--)
        {
            if(!bucket[i].empty()) res.append(bucket[i]);
        }
        return res;
    }
};