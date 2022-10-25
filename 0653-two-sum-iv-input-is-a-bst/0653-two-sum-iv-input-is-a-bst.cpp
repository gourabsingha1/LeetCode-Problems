class BSTIterator {
public:
    stack<TreeNode*> st;
    bool reverse; // reverse = 1, descending order
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        inputStack(root);
    }
    
    int next() {
        TreeNode *curr = st.top();
        st.pop();
        if(reverse){
            inputStack(curr->left); // go to left and push all the rights
        }
        else{
            inputStack(curr->right); // go to right and push all the lefts
        }
        return curr->val;
    }

    void inputStack(TreeNode* curr){
        while(curr){
            st.push(curr);
            if(reverse){
                curr = curr->right;
            }
            else{
                curr = curr->left;
            }
        }
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root, 0); // low
        BSTIterator r(root, 1); // high
        int low = l.next();
        int high = r.next();

        while(low < high){
            if(low + high == k){
                return 1;
            }
            else if(low + high > k){
                high = r.next();
            }
            else{
                low = l.next();
            }
        }
        return 0;
    }
};