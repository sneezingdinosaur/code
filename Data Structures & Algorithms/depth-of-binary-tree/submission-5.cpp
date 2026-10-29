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
    // int traverse(TreeNode*root){
    //     if(!root){return 0;}

    //     if(root->left && root->right){
    //         return 1 + max(traverse(root->left),traverse(root->right));
    //     }
    //     else if(root->right){
    //         return 1 + traverse(root->right);
    //     }
    //     else if(root->left){
    //         return 1 + traverse(root->left);
    //     }
    //     return 1;
    // }








    int maxDepth(TreeNode* root) {


        if(!root){return 0;}
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
