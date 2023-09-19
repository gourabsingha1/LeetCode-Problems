// index 0 is pointing at some index, and that index is pointing at some other index
// this forms a linkedlist and now we just apply floyds algo

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0, slow = 0;
        while(1){
            fast = nums[nums[fast]];
            slow = nums[slow];
            if(fast == slow){
                break;
            }
        }
        slow = 0;
        while(fast != slow){
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};