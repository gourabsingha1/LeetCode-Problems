class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        unordered_map<string, int> mp;
        for (int i = 0; i < words.size(); i++)
        {
            mp[words[i]]++;
        }
        vector<pair<int, string>> freq_word;
        for(auto& [s, x] : mp) {
            freq_word.push_back({x, s});
        }
        sort(freq_word.rbegin(), freq_word.rend());
        int i = 0, n = freq_word.size();
        while(i < k)
        {
            int cnt = freq_word[i].first;
            vector<string> temp;
            while(i < n && freq_word[i].first == cnt) {
                temp.push_back(freq_word[i++].second);
            }
            sort(temp.begin(), temp.end());
            for(auto& t : temp) {
                if(res.size() == k) return res;
                res.push_back(t);
            }
        }
        return res;
    }
};