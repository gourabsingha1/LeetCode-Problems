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
            int c = y;
            while(c--) bucket[y].push_back(x);
        }
        for (int i = n; i >= 0; i--)
        {
            if(bucket[i] != "") res += bucket[i];
        }
        return res;
    }
};