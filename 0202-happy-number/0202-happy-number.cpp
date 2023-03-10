class Solution {
public:
    int next(int n) {
        int res = 0;
        while(n) {
            int rem = n % 10;
            res += rem * rem, n /= 10;
        }
        return res;
    }
    bool isHappy(int n) {
        int slow = n, fast = n;
        while(1){
            slow = next(slow); // slow = slow->next
            fast = next(next(fast)); // fast = fast->next->next
            if(slow == fast){
                break;
            }
        }
        return slow == 1;
    }
};