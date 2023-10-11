// sort flowers acc to startTime and people according to arrive time
// create timeIndex vector for getting the index after sorting people
// push endTime of flowers in minHeap while the startTime is <= time
// pop from minHeap as long as endTime < time
// answer should be the size of the minHeap

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = people.size(), j = 0, m = flowers.size();
        vector<int> res(n);
        vector<pair<int, int>> timeIndex;
        for (int i = 0; i < n; i++)
        {
            timeIndex.push_back({people[i], i});
        }
        sort(flowers.begin(), flowers.end());
        sort(timeIndex.begin(), timeIndex.end());

        priority_queue<int, vector<int>, greater<>> minHeap;
        for(auto& [time, index] : timeIndex) {
            while(j < m && flowers[j][0] <= time) {
                minHeap.push(flowers[j++][1]);
            }
            while(minHeap.size() && minHeap.top() < time) {
                minHeap.pop();
            }
            res[index] = minHeap.size();
        }
        return res;
    }
};