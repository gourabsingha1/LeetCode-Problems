class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int pre[nums.size()];
        pre[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            pre[i] = nums[i] + pre[i-1];
        }
        for (auto &x : queries){
            int high = nums.size() - 1, low = 0;
            while(low<=high){
                int mid = high + (low-high)/2;
                if(pre[mid]>x){
                    high = --mid;
                }
                else{
                    low = ++mid;
                }
            }
            x = high+1;
        }
        return queries;
    }
};