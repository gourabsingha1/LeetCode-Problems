class Solution {
public:
    TreeNode* helper(int i, int left, int right, unordered_map<int, int>& mp, vector<int>& preorder, vector<int>& inorder) {
        if(left > right) {
            return NULL;
        }
        int mid = mp[preorder[i]];
        TreeNode* root = new TreeNode(preorder[i]);
        root->left = helper(i + 1, left, mid - 1, mp, preorder, inorder);
        root->right = helper(i + 1 + mid - left, mid + 1, right, mp, preorder, inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        int n = inorder.size();
        for (int i = 0; i < n; i++)
        {
            mp[inorder[i]] = i;
        }
        return helper(0, 0, n - 1, mp, preorder, inorder);
    }
};