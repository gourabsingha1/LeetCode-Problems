// say we store current subsequence elements in temp vector
// we only need the last element of temp to find the next element
// store the count of prev elements in the map of last element
// to get the longest subsequence in O(1)

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int res = 1;
        unordered_map<int, int> dp;
        for (int i = 0; i < arr.size(); i++)
        {
            int temp = arr[i] - difference;
            int tempRes = 1 + dp[temp];
            dp[arr[i]] = tempRes;
            res = max(res, dp[arr[i]]);
        }
        return res;
    }
};