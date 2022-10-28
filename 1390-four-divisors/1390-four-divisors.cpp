class Solution {
public:
    int res = 0;
    void divisors(int &n){
        int cnt = 0, sum = 0;
        vector<int> v;
        for (int i = 1; i <= sqrt(n); i++)
        {
            if(n%i == 0){
                cnt += 2;
                sum += i + n/i;
            }
            if(i*i == n){
                cnt--;
                sum -= i;
            }
        }
        if(cnt == 4){
            res += sum;
        }
        return;
        
    }
    int sumFourDivisors(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            divisors(nums[i]);
        }
        return res;
    }
};