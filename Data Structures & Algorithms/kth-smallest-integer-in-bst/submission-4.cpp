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

    vector<int> nodes;

    void inorder(TreeNode*root){
        if(!root){return;}
        inorder(root->left);
        nodes.push_back(root->val);
        inorder(root->right);
    }

    // void sorted(TreeNode*root){
    //     if(root){
    //         bool pushed = false;
    //         if(!root->left){
    //             nodes.push_back(root->val);
    //             pushed = true;
    //         }
    //         else{
    //             sorted(root->left);
    //         }

    //         if(root->left && root->right){
    //             nodes.push_back(root->val);
    //         }
    //         if(!pushed){
                
    //         }
    //         if(!root->right){
    //             if(!pushed){
    //                 nodes.push_back(root->val);
    //             }
    //         }
    //         else{
    //             sorted(root->right);
    //         }
    //     }
    // }



    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        for(int i : nodes){
            cout<<i;
        }
        return nodes[k-1];







    }
};
