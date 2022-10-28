class Solution {
public:
    bool levelOrder(TreeNode *root){
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(q.size()){
            int n = q.size();
            vector<int> temp;
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            for (int i = 0; i < n-1; i++)
            {
                if(level%2==0 && !(temp[i]&1 && temp[i+1]&1 && temp[i] < temp[i+1]) || level%2 && !(temp[i]%2==0 && temp[i+1]%2==0 && temp[i] > temp[i+1])){
                    return 0;
                }
            }
            if(temp.size() == 1){
                if(level&1 && temp[0]&1 || level%2==0 && temp[0]%2==0){
                    return 0;
                }
            }
            level++;
        }
        return 1;
    }
    bool isEvenOddTree(TreeNode* root) {
        return levelOrder(root);
    }
};