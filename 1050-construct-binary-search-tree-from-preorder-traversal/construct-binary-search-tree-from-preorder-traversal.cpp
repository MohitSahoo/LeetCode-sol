class Solution {
public:
    TreeNode* buildTree1(vector<int> &preorder1, int prestart, int preend,
                         vector<int> &inorder, int instart, int inend,
                         map<int,int> &inMap) {
        if (prestart > preend || instart > inend) return nullptr;

        int rootVal = preorder1[prestart];
        TreeNode *root = new TreeNode(rootVal);

        int inroot = inMap[rootVal];
        int numsleft = inroot - instart;

        root->left = buildTree1(preorder1, prestart + 1, prestart + numsleft,
                                inorder, instart, inroot - 1, inMap);

        root->right = buildTree1(preorder1, prestart + numsleft + 1, preend,
                                 inorder, inroot + 1, inend, inMap);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        vector<int> preorder1 = preorder;

        
        sort(preorder.begin(), preorder.end());
        vector<int> &inorder = preorder;

        map<int,int> inMap;
        for (int i = 0; i < (int)inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        return buildTree1(preorder1, 0, (int)preorder1.size() - 1,
                          inorder, 0, (int)inorder.size() - 1, inMap);
    }
};
