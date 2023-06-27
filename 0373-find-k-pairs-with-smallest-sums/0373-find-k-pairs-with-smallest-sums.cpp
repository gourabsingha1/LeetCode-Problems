// run O(N^2) loop. push elements in max heap. if top is greater than curSum, then replace and continue

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, int>> pq; // sum, nums2[j]
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                int sum = nums1[i] + nums2[j];
                if(pq.size() < k) {
                    pq.push({sum, nums2[j]});
                }
                else if(sum < pq.top().first) {
                    pq.pop();
                    pq.push({sum, nums2[j]});
                }
                else {
                    break;
                }
            }
        }
        k = pq.size();
        vector<vector<int>> res(k);
        while(k--) {
            int num1 = pq.top().first - pq.top().second, num2 = pq.top().second;
            res[k] = {num1, num2};
            pq.pop();
        }
        return res;
    }
};