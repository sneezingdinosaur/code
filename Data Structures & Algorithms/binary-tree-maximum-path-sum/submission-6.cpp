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
    int best = INT_MIN;

    int down(TreeNode* root){
        if (!root) return 0;
        int l = max(0,down(root->left));
        int r = max(0,down(root->right));
        best = max(best, root->val + l + r);
        return root->val + max(l,r);
    }


    int maxPathSum(TreeNode* root) {
        down(root);
        return best;
    }
};
