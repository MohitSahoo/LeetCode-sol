/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()){
            return NULL;
        }
        unordered_map<int, int> mpp;
        for(int i =0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return buildTree1(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mpp);
    }
    TreeNode* buildTree1(vector<int>&inorder,int instart,int inend,vector<int>&postorder,int poststart,int postend,unordered_map<int,int>&mpp){
        if(postend < poststart || inend <instart){
            return NULL;
        }
        TreeNode * root = new TreeNode(postorder[postend]);
        int inRoot = mpp[postorder[postend]];
        int numsleft = inRoot - instart;
        root->left = buildTree1(inorder,instart,inRoot-1,postorder,poststart,poststart+numsleft-1,mpp);
        root->right= buildTree1(inorder,inRoot+1,inend,postorder,poststart+numsleft,postend-1,mpp);
        return root;
    }
};