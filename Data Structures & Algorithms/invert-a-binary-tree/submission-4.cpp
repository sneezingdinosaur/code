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
    // void invert (TreeNode* curr){
    //     TreeNode* temp;
    //     TreeNode* temp1;

    //     if(curr->left && curr->right){
    //         temp = curr->left;
    //         temp1 = curr->right;
    //         curr->right = temp;
    //         curr->left = temp1;
    //         invert(temp1);
    //         invert(temp);
    //     }
    //     else if(curr->right){
    //         curr->left = curr->right;
    //         invert(curr->left);
    //         curr->right = nullptr;
    //     }
    //     else if(curr->left){
    //         curr->right = curr->left;
    //         invert(curr->right);
    //         curr->left = nullptr;
    //     }
    // }


    TreeNode* invertTree(TreeNode* root) {
        // TreeNode* curr = root;
        // if(!curr){return nullptr;}

        // invert(curr);
        // return root;

        if(!root){return nullptr;}
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
