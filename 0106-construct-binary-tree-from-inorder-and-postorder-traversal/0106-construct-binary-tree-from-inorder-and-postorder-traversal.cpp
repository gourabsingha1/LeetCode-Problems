class Solution {
public:
    TreeNode* helper(int i, int left, int right, unordered_map<int, int>& mp, vector<int>& postorder, vector<int>& inorder) {
        if(left > right) {
            return NULL;
        }
        int mid = mp[postorder[i]];
        TreeNode* root = new TreeNode(postorder[i]);
        root->left = helper(i - 1 - right + mid, left, mid - 1, mp, postorder, inorder);
        root->right = helper(i - 1, mid + 1, right, mp, postorder, inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        int n = inorder.size();
        for (int i = 0; i < n; i++)
        {
            mp[inorder[i]] = i;
        }
        return helper(n - 1, 0, n - 1, mp, postorder, inorder);
    }
};