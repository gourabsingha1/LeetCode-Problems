class Solution {
public:
    TreeNode* helper(int i, int left, int right, unordered_map<int, int>& mp, vector<int>& preorder, vector<int>& postorder) {
        if(left > right || i >= preorder.size()) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[i]);
        if(left == right) {
            return root;
        }
        int mid = mp[preorder[i + 1]];
        root->left = helper(i + 1, left, mid, mp, preorder, postorder);
        root->right = helper(i + 1 + mid - left + 1, mid + 1, right - 1, mp, preorder, postorder);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        int n = postorder.size();
        for (int i = 0; i < n; i++)
        {
            mp[postorder[i]] = i;
        }
        return helper(0, 0, n - 1, mp, preorder, postorder);
    }
};