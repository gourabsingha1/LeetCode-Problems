// remove the least frequently appeared integers

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        priority_queue<int, vector<int>, greater<>> pq;
        for(auto& a : arr) {
            freq[a]++;
        }
        for(auto& [_, y] : freq) {
            pq.push(y);
        }
        while(pq.size()) {
            // pq holds freq, k is also freq
            if(pq.top() <= k) {
                k -= pq.top();
                pq.pop();
            }
            else {
                break;
            }
        }
        return pq.size();
    }
};