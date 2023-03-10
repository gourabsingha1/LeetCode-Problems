class Solution {
public:
    vector<int> nums;
    Solution(ListNode* head) {
        while(head) {
            nums.push_back(head->val);
            head = head->next;
        }
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};