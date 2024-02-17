// always use ladder for larger difference
// when h[i - 1] < h[i], bricks -= diff and push that diff in maxHeap
// bricks < 0, use ladder for the largest diff and add the used bricks back

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int> pq;
        for (int i = 1; i < n; i++)
        {
            if(heights[i - 1] < heights[i]) {
                int diff = heights[i] - heights[i - 1];
                pq.push(diff);
                bricks -= diff;
                if(bricks < 0) {
                    if(ladders) {
                        bricks += pq.top();
                        pq.pop();
                        ladders--;
                    }
                    else {
                        return i - 1;
                    }
                }
            }
        }
        return n - 1;
    }
};