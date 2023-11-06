// the smallest unreserved number will be reserved first

class SeatManager {
public:
    int size = 0;
    priority_queue<int, vector<int>, greater<>> minHeap;

    SeatManager(int n) {
        
    }
    
    int reserve() {
        size++;
        if(minHeap.size()) {
            int top = minHeap.top();
            minHeap.pop();
            return top;
        }
        return size;
    }
    
    void unreserve(int seatNumber) {
        minHeap.push(seatNumber);
        size--;
    }
};