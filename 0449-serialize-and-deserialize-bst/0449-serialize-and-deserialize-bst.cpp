class Codec {
public:
    string serialize(TreeNode* root) {
        if(!root) {
            return "n";
        }
        string s = to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
        return s;
    }
    TreeNode* Deserialize(int& i, string& data) {
        int n = data.size();
        if(i < n && data[i] == ',') i++;
        if(i >= n || !isdigit(data[i])) {
            i++;
            return NULL;
        }
        int j = i;
        while(i < n && isdigit(data[i])) {
            i++;
        }
        TreeNode* root = new TreeNode(stoi(data.substr(j, i - j)));
        root->left = Deserialize(i, data);
        root->right = Deserialize(i, data);
        return root;
    }
    TreeNode* deserialize(string data) {
        int i = 0;
        return Deserialize(i, data);
    }
};