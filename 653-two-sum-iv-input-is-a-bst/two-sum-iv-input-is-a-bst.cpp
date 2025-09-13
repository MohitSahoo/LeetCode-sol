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
    void inorder(TreeNode* root,vector<int>&inorder1){
        if(root ==NULL){
            return;
        }
        inorder(root->left,inorder1);
        inorder1.push_back(root->val);
        inorder(root->right,inorder1);
        
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder1;
        inorder(root,inorder1);
        int left =0;
        int right =inorder1.size()-1;
        while(left<right){
            if(inorder1[left]+inorder1[right]==k){
                return true;
            }else if(inorder1[left]+inorder1[right]<k){
                left++;
            }else{
                right--;
            }
        }
        return false;

        
    }
};