class Solution {
public:
    bool helper(int num, int target) {
        if(num <= target || target <= 0) {
            return num == target;
        }
        return helper(num / 10, target - num % 10) || helper(num / 100, target - num % 100) || helper(num / 1000, target - num % 1000);
    }
    
    int punishmentNumber(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if(helper(i * i, i)) {
                res += i * i;
            }
        }
        return res;
    }
};