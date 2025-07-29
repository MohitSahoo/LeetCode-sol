class Solution {
public:
    void preorder(TreeNode* root, vector<int>& res) {
        if (root==NULL) {
            res.push_back(INT_MIN); 
            return;
        }

        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> pre1, pre2;
        preorder(p, pre1);
        preorder(q, pre2);
        return pre1 == pre2;
    }
};
