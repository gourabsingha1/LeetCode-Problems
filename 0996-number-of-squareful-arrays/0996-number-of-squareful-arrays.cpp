class Solution {
public:
    void helper(int currInd, vector<int> nums, int &res){
        int n = nums.size();
        if(currInd == n){
            res++;
            return;
        }
        for (int i = currInd; i < n; i++)
        {
            if(i != currInd && nums[i] == nums[currInd]) continue;
            swap(nums[i], nums[currInd]);
            if(currInd > 0 && !isSquare(nums[currInd - 1] + nums[currInd])) continue;
            helper(currInd + 1, nums, res);
        }
    }
    bool isSquare(int n){
        int sq = sqrt(n);
        return sq*sq == n;
    }
    int numSquarefulPerms(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        helper(0, nums, res);
        return res;
    }
};