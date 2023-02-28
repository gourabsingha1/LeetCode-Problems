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
        if(i >= n || !isdigit(data[i])) {
            i++;
            return NULL;
        }
        int num = 0;
        while(i < n && isdigit(data[i])) {
            num = num * 10 + data[i++] - '0';
        }
        TreeNode* root = new TreeNode(num);
        if(i < n && data[i] == ',') i++;
        root->left = Deserialize(i, data);
        if(i < n && data[i] == ',') i++;
        root->right = Deserialize(i, data);
        if(i < n && data[i] == ',') i++;
        return root;
    }
    TreeNode* deserialize(string data) {
        int i = 0;
        return Deserialize(i, data);
    }
};