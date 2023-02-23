class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> maxHeap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        for (int i = 0; i < profits.size(); i++)
        {
            minHeap.push({capital[i], profits[i]});
        }
        while(k--){
            while(minHeap.size() && minHeap.top().first <= w){
                maxHeap.push(minHeap.top().second);
                minHeap.pop();
            }
            if(!maxHeap.size()){
                break;
            }
            w += maxHeap.top();
            maxHeap.pop();
        }
        return w;
    }
};