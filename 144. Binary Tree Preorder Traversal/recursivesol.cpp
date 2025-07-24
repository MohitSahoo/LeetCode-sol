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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>result;
        preorderT(root,result);
        return result;

        
    }
    void preorderT(TreeNode* node,vector <int>&result){
        if(node== NULL){
            return;
        }
        else{
            result.push_back(node->val);
            preorderT(node->left,result);
            preorderT(node->right,result);
        }
    }

};
