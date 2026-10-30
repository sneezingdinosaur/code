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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if(!p){if (q) return false; else return true;}
        if(!q){if (p) return false;}
        if(p->val!=q->val){return false;}

        return isSameTree(p->left, q->left) && isSameTree(q->right, p->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot){return true;}
        if(!root){return false;}
        if (root->val == subRoot->val){
            if (isSameTree(root, subRoot)){return true;}
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);

    }
};
