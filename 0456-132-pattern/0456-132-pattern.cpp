// numsK = current element
// numsJ = previous greater element of numsK
// numsI = minimum till (j - 1)

class Solution {
public:
    vector<int> prevGreaterElementIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> minStack;
        for (int i = n - 1; i >= 0; i--)
        {
            while(minStack.size() && nums[minStack.top()] < nums[i]){
                res[minStack.top()] = i;
                minStack.pop();
            }
            minStack.push(i);
        }
        return res;
    }

    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> PGE = prevGreaterElementIndex(nums), mini(n);
        mini[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            mini[i] = min(mini[i - 1], nums[i]);
        }

        for (int k = n - 1; k >= 2; k--)
        {
            int j = PGE[k];
            if(j > 0) {
                int numsI = mini[j - 1];
                if(numsI < nums[k] && nums[k] < nums[j]) {
                    return 1;
                }
            }
        }
        return 0;
    }
};