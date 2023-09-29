class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0, n = arr.size();
        priority_queue<int> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push(arr[i]);
            if(pq.top() == i) {
                res++;
            }
        }
        return res;
    }
};