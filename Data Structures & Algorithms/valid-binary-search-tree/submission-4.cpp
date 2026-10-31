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
    // bool search(TreeNode* root, int upper, int lower){
    //     if(!root){return true;}
    //     if(root->right){
    //         if (root->val >= root->right->val || root->right->val >= upper) return false;
    //     }
    //     if(root->left){
    //         if (root->val <= root->left->val || root->left->val <= lower) return false;
    //     }
    //     return search(root->left, min(upper, root->val), lower) && search(root->right, upper, max(lower, root->val));
    // }

    bool valid(TreeNode* node, int left, int right){
        if(!node){return true;}
        if(!(node->val < right && node->val > left)){
            return false;
        }
        return valid(node->left, left, node->val) && valid(node->right, node->val, right);
    }

    bool isValidBST(TreeNode* root) {
        // return search(root, 1000000001, -1000000001);
        return valid(root, -1000000001, 1000000001);
        
    }
};
