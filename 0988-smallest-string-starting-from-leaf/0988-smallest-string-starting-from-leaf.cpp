class Solution {
public:
    void dfs(TreeNode* root, string s, string &res){
        if(!root) return;
        
        if(!root->left && !root->right){
            string temp = s + (char)(root->val + 'a');
            reverse(temp.begin(), temp.end());
            if(res == "") res = temp;
            else res = min(res, temp);
            return;
        }
        dfs(root->left, s + (char)(root->val + 'a'), res);
        dfs(root->right, s + (char)(root->val + 'a'), res);
    }

    string smallestFromLeaf(TreeNode* root) {
        string res = "";
        dfs(root, "", res);
        return res;
    }
};