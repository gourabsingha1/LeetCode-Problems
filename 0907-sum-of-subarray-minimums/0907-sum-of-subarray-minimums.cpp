class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(), res = 0, M = 1e9 + 7;
        stack<int> minStackPrev, minStackNext;
        vector<int> left(n), right(n);
        for (int i = 0; i < n; i++)
        {
            while(minStackPrev.size() && arr[minStackPrev.top()] > arr[i]){
                minStackPrev.pop();
            }
            if(minStackPrev.size()) left[i] = i - minStackPrev.top();
            else left[i] = i + 1;
            minStackPrev.push(i);

            int j = n - 1 - i;
            while(minStackNext.size() && arr[minStackNext.top()] >= arr[j]){
                minStackNext.pop();
            }
            if(minStackNext.size()) right[j] = minStackNext.top() - j;
            else right[j] = i + 1;
            minStackNext.push(j);
        }
        for (int i = 0; i < n; i++)
        {
            res = (res + 1LL * left[i] * right[i] * arr[i]) % M;
        }
        // for(auto &x : left) cout<<x<<" "; cout<<endl;
        // for(auto &x : right) cout<<x<<" "; cout<<endl;
        return res;
    }
};