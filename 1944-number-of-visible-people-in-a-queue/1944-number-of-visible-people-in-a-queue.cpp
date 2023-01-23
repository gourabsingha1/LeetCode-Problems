class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> res(n);
        stack<int> maxStackNext;
        for (int i = n - 1; i >= 0; i--)
        {
            int size = 1;
            while(maxStackNext.size() && heights[maxStackNext.top()] <= heights[i]){
                size++;
                maxStackNext.pop();
            }
            if(maxStackNext.size()){
                res[i] = size;
            }
            else{
                res[i] = size - 1;
            }
            maxStackNext.push(i);
        }
        return res;
    }
};