// sum = sum + freq * dist
// res[i] = pre[sum[i]] + suf[sum[i]]

class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int, vector<long long>> mp; // arr[i] = {lastInd, sum, freq}
        int n = arr.size();
        vector<long long> res(n), pre(n, 0), suf(n, 0);
        
        for(int i = 0; i < n; i++) {
            if(mp.find(arr[i]) != mp.end()) {
                int dist = i - mp[arr[i]][0];
                mp[arr[i]] = {i, mp[arr[i]][1] + mp[arr[i]][2] * dist, mp[arr[i]][2] + 1};
            }
            else {
                mp[arr[i]] = {i, 0, 1};
            }
            pre[i] = mp[arr[i]][1];
        }
        
        mp.clear();
        for(int i = n - 1; i >= 0; i--) {
            if(mp.find(arr[i]) != mp.end()) {
                int dist = mp[arr[i]][0] - i;
                mp[arr[i]] = {i, mp[arr[i]][1] + mp[arr[i]][2] * dist, mp[arr[i]][2] + 1};
            }
            else {
                mp[arr[i]] = {i, 0, 1};
            }
            suf[i] = mp[arr[i]][1];
            
            res[i] = pre[i] + suf[i];
        }
        return res;
    }
};