class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int& num : nums){
            if(pq.size() < k){
                pq.push(num);
            }
            else if(pq.size() == k && pq.top() < num) {
                pq.push(num);
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        if(pq.size() < k){
            pq.push(val);
        }
        else if(pq.size() == k && pq.top() < val) {
            pq.push(val);
            pq.pop();
        }
        return pq.top();
    }
};