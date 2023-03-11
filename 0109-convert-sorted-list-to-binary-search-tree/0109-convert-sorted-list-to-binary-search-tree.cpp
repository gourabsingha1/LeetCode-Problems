class Solution {
public:
    TreeNode* buildBST(int l, int r, vector<int>& nums) {
        if(l > r) {
            return NULL;
        }
        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildBST(l, mid - 1, nums);
        root->right = buildBST(mid + 1, r, nums);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) {
            return NULL;
        }
        vector<int> nums;
        while(head) {
            nums.push_back(head->val);
            head = head->next;
        }
        return buildBST(0, nums.size() - 1, nums);
    }
};