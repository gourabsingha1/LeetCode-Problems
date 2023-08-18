// push same column {row, value} pairs. sort them and push them in res in order

class Solution {
public:
    map<int, vector<pair<int, int>>> columns; // col = {row, value}

    void dfs(int row, int col, TreeNode* root) {
        if(!root) {
            return;
        }
        
        columns[col].push_back({row, root->val});
        dfs(row + 1, col - 1, root->left);
        dfs(row + 1, col + 1, root->right);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        dfs(0, 0, root);
        for(auto& [col, vec] : columns) {
            sort(vec.begin(), vec.end());
            vector<int> cur;
            for(auto& [row, value] : vec) {
                cur.push_back(value);
            }
            res.push_back(cur);
        }
        return res;
    }
};