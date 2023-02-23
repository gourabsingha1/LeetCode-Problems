class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        priority_queue<int> maxHeap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        for (int i = 0; i < n; i++)
        {
            minHeap.push({capital[i], profits[i]});
        }
        while(k--){
            while(minHeap.size() && minHeap.top().first <= w){
                maxHeap.push(minHeap.top().second);
                minHeap.pop();
            }
            if(maxHeap.size()){
                w += maxHeap.top();
                maxHeap.pop();
            }
        }
        return w;
    }
};