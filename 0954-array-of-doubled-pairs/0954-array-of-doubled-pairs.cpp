class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n = arr.size(), cnt = 0, zero = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[arr[i]]++, zero += !arr[i];
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++)
        {
            if(arr[i] && m[arr[i]] && m[2 * arr[i]]){
                m[arr[i]]--, m[2 * arr[i]]--;
                cnt += 2;
            }
        }
        return cnt + zero == n;
    }
};