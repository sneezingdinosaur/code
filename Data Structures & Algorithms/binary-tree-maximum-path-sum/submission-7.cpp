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
    // int best = INT_MIN;

    // int down(TreeNode* root){
    //     if (!root) return 0;
    //     int l = max(0,down(root->left));
    //     int r = max(0,down(root->right));
    //     best = max(best, root->val + l + r);
    //     return root->val + max(l,r);
    // }

    vector<int>result;
    

    int dfs (TreeNode* root){
        if(!root){return 0;}
        int l = dfs(root->left);
        int r = dfs(root->right);
        l = max(0,l);
        r = max(0,r);

        result[0] = max(result[0], root->val + l + r);
        return root->val + max(l, r);

    }


    int maxPathSum(TreeNode* root) {
        // down(root);
        // return best;
        result.push_back(root->val);
        dfs(root);
        return result[0];
        



    }
};
